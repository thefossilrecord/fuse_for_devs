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

void
debugger_sjasmplus_sym_init()
{
  if( !settings_current.debugger_sym_file )
    return;

  FILE *sym_file = fopen(settings_current.debugger_sym_file, "r");
  if(sym_file)
  {
    //printf("Sym File: %s\n", settings_current.debugger_sym_file);

    char *line = NULL;
    size_t len = 0;
    size_t read = 0;

    while((read = getline(&line, &len, sym_file)) != -1)
    {
      /* Sym file line format is:
      <name>: EQU <address>
      */
      char *split = strstr(line, ": EQU ");
      if(split)
      {
        *split = 0;
        /* ': EQU ' is 6 characters long */
        libspectrum_dword equ = strtoul(split + 6, NULL, 16);

        debugger_variable_set((const char *)line, equ);

        //printf("%s=%d\n", line, equ);
      }
    }
    if(line)
      free(line);
    fclose(sym_file);
  }
}
