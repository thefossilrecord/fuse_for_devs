/* watch.c: watch support
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

#ifdef HAVE_LIB_GLIB
#include <glib.h>
#endif				/* #ifdef HAVE_LIB_GLIB */

#include "libspectrum.h"

#include "debugger_internals.h"
#include "fuse.h"
#include "ui/ui.h"
#include "utils.h"
#include "watch.h"

//#include "settings.h"

/* Current list of watches */
GSList *debugger_watches;

/* The next watch ID to use */
static size_t next_watch_id;

int
debugger_watch_add( libspectrum_dword address, const char *watch_type)
{
  debugger_watch *watch;
  GSList *ptr;
  GSList *ptr_next;

  /* Check if watch has already been added. */
  for( ptr = debugger_watches; ptr; ptr = ptr_next )
  {
    watch = ptr->data;
    ptr_next = ptr->next;
    if(watch->address==address)
      /* !!! Duplicate, so don't add.*/
      return 1;
  }

  //printf("Watch - address: %d, type: '%s'\n", address, watch_type ? watch_type : "u8");

  watch = libspectrum_new( debugger_watch, 1 );
  watch->address = address;
  watch->id = next_watch_id++;
  watch->name = NULL;
  if(last_variable_expression_name)
  {
    watch->name = utils_safe_strdup( last_variable_expression_name );
    //printf("VARIABLE: %s\n", last_variable_expression_name);
    last_variable_expression_name = NULL;
  }

  const char *watch_types_lookup[]=
  {
    NULL,
    "u8",
    "u16",
  };

  debugger_watch_type check = DEBUGGER_WATCH_TYPE_U8;
  if(watch_type)
  {
    while(check < DEBUGGER_WATCH_TYPE_END)
    {
      if(!strcasecmp(watch_types_lookup[check], watch_type))
        break;

      check++;
    }

    if(check==DEBUGGER_WATCH_TYPE_END)
      check = DEBUGGER_WATCH_TYPE_U8;
  }

  watch->type = check;

  debugger_watches = g_slist_append( debugger_watches, watch );

  ui_watches_updated();

  return 0;
}

static gint
find_watch_by_id( gconstpointer data, gconstpointer user_data )
{
  const debugger_watch *watch = data;
  size_t id = *(const size_t*)user_data;

  return watch->id - id;
}

debugger_watch *
get_watch_by_id( size_t id )
{
  GSList *ptr;

  ptr = g_slist_find_custom( debugger_watches, &id,
			     find_watch_by_id );
  if( !ptr ) {
    ui_error( UI_ERROR_ERROR, "Watch %ld does not exist",
	      (unsigned long)id );
    return NULL;
  }

  return ptr->data;
}

static void
free_watch( gpointer data, gpointer user_data GCC_UNUSED )
{
  debugger_watch *watch = data;
  if( watch->name ) libspectrum_free( watch->name );
  libspectrum_free( watch );
}

/* Remove all watches */
int
debugger_watch_remove_all( void )
{
  g_slist_foreach( debugger_watches, free_watch, NULL );
  g_slist_free( debugger_watches ); debugger_watches = NULL;

  if( debugger_mode == DEBUGGER_MODE_ACTIVE )
    debugger_mode = DEBUGGER_MODE_INACTIVE;

  /* Restart the watch numbering */
  next_watch_id = 0;

  ui_watches_updated();

  return 0;
}
