/* sjasmplus.c: SjASMplus support
   Copyright (c) 2026 bob_fossil

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

#include <string.h>
#ifdef HAVE_STRINGS_STRCASECMP
#include <strings.h>
#endif      /* #ifdef HAVE_STRINGS_STRCASECMP */

#ifdef HAVE_LIB_GLIB
#include <glib.h>
#endif				/* #ifdef HAVE_LIB_GLIB */

#include "libspectrum.h"

#include "debugger_internals.h"
#include "fuse.h"
#include "ui/ui.h"
#include "utils.h"

#include "settings.h"

void parse_sym_file(char *line, void *parameters)
{
  /* Sym file line format is:
  <name>: EQU <hex address>
  */
  char *split = strstr(line, ": EQU ");
  if(split)
  {
    *split = 0;
    /* ': EQU ' is 6 characters long */
    libspectrum_dword equ = strtoul(split + 6, NULL, 16);
    debugger_variable_set((const char *)line, equ);
  }
}

void
debugger_parse_lines_from_buffer(char *buffer, parse_function function, void *parameters)
{
  /* Go through buffer extracting a line at a time.*/
  char *line_start = buffer, *line_end = NULL;
  while(*line_start)
  {
    line_end = strchr(line_start, 0xa);
    if(line_end)
    {
      /* Terminate line.*/
      *line_end = 0;
      /* Check for Windows line ending.*/
      char *prev = line_end - 1;
      if(prev && *prev == 0xd)
        /* Terminate at previous character.*/
        *prev = 0;
    }
  /* Pass extracted line to parsing function.*/
  function(line_start, parameters);
  if(line_end)
    /* Move on to the next line.*/
    line_start = line_end + 1;
  else
    break;
  }
}

int
debugger_load_symbol_file_to_buffer(char *path, char **symbol_buffer)
{
  int ok = 0;
  FILE *sym_file = fopen(path, "r");
  if(sym_file)
  {
    /* Get the file size.*/
    fseek(sym_file, 0, SEEK_END);
    long sym_file_size = ftell(sym_file);
    if(sym_file_size!=-1)
    {
      /* Allocate a buffer to load the sym file into.*/
      char *buffer = (char *)malloc(sym_file_size + 1);
      if(buffer)
      {
        memset(buffer, 0, sym_file_size + 1);
        /* Move back to the start and read the file in.*/
        fseek(sym_file, 0, SEEK_SET);
        long size = fread(buffer, 1, sym_file_size, sym_file);
        if(size==sym_file_size)
        {
          ok = 1;
          *symbol_buffer = buffer;
        }
        else
          free(buffer);
      }
    }
    fclose(sym_file);
  }
  return ok;
}

void
debugger_sjasmplus_sym_init()
{
  if( !settings_current.debugger_sym_file )
    return;

  char *sjasm_plus_sym_file_buffer = NULL;
  if( debugger_load_symbol_file_to_buffer(settings_current.debugger_sym_file,
      &sjasm_plus_sym_file_buffer) )
  {
    debugger_parse_lines_from_buffer(sjasm_plus_sym_file_buffer, parse_sym_file, NULL);
    free(sjasm_plus_sym_file_buffer);
  }
}
