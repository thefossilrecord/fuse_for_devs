/* command.c: Parse a debugger command
   Copyright (c) 2002-2017 Philip Kendall
   Copyright (c) 2026 Fredrick Meunier

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

   Author contact information:

   E-mail: philip-fuse@shadowmagic.org.uk

*/

#include "config.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "debugger.h"
#include "debugger_internals.h"
#include "mempool.h"
#include "ui/ui.h"
#include "utils.h"
#include "z80/z80.h"
#include "z80/z80_macros.h"

#define PASS_SIZING 0
#define PASS_REPLACING PASS_SIZING + 1
#define MAX_PASS PASS_REPLACING + 1

char *
debugger_process_evaluate_dollars( const char *command )
{
  int pass = PASS_SIZING;
  int replacements = 0, replacement_offset = 0;
  char *evaluated = NULL;

  /* PASS_SIZING works out if we need to do anything and calculates sizes.
  PASS_REPLACING replaces any $ characters with 0x. */
  while(pass < MAX_PASS)
  {
    char *dollar = strchr(command, 0x24);
    while(dollar)
    {
      int matched = 0;
      char *check = dollar + 1;
      while(*check && *check!=0x20)
      {
        if((*check >= 0x30 && *check <=0x39) ||
          (*check >= 0x41 && *check <=0x46) ||
          (*check >= 0x61 && *check <=0x66))
            matched++;
        else
          {
            matched = 0;
            break;
          }
        check++;
      }
      if(matched && matched <= 4)
      {
        if(pass==PASS_REPLACING)
        {
          size_t source_offset = (dollar - command);
          size_t destination_offset = source_offset + replacement_offset;

          /* Set $ to 0. */
          char *replace = &evaluated[destination_offset];
          *replace = 0x30; // 0
          size_t remaining = strlen(replace + 1);
          /* Move the following characters up by one. */
          memmove(replace + 2, replace + 1, remaining);
          replacement_offset++;
          replace++;
          /* Put x in the gap we just made. */
          *replace = 0x78; // x
        }
        replacements++;
      }
    dollar = strchr(dollar + 1, 0x24);
    }

    if(pass==PASS_SIZING)
    {
      if(replacements)
      {
      /* Allocate a string with enough space to hold the replaced $
      characters. */
      size_t alloc = strlen(command);
      evaluated = (char *)malloc(alloc + replacements);
      memset(evaluated, 0, alloc + replacements);
      memcpy(evaluated, command, alloc);
      }
    else
      /* Nothing to replace. */
      return evaluated;
    }

  pass++;
  }


  return evaluated;
}


/* The last debugger command we were given to execute */
static char *command_buffer = NULL;

/* And a pointer as to how much we've parsed */
static char *command_ptr;

int yyparse( void );

/* Evaluate the debugger command given in 'command' */
void
debugger_command_evaluate( const char *command )
{
  if( !command ) return;

  if( command_buffer ) libspectrum_free( command_buffer );

  /* See if we need to replace any $xxxx hex numbers with 0x. */
  char *evaluated = debugger_process_evaluate_dollars(command);
  if(evaluated)
  {
    command_buffer = utils_safe_strdup( evaluated );
    free( evaluated );
  }
  else
    command_buffer = utils_safe_strdup( command );

  /* Start parsing at the start of the given command */
  command_ptr = command_buffer;
    
  /* Parse the command */
  yyparse();

  /* And free any memory we allocated while parsing */
  mempool_free( debugger_memory_pool );

  ui_debugger_update();
}

/* Called to get up to 'max_size' bytes of the command to be parsed */
int
debugger_command_input( char *buf, int *result, int max_size )
{
  size_t length = strlen( command_ptr );

  if( !length ) {
    return 0;
  } else if( length < (size_t)max_size ) {
    memcpy( buf, command_ptr, length );
    *result = length; command_ptr += length;
    return 1;
  } else {
    memcpy( buf, command_ptr, max_size );
    *result = max_size; command_ptr += max_size;
    return 1;
  }
}

/* Utility functions called by the bison parser */

/* The error callback if yyparse finds an error */
void
yyerror( const char *s )
{
  ui_error( UI_ERROR_ERROR, "Invalid debugger command: %s", s );
}
