/* watch.h: a debugger breakpoint
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

#ifndef FUSE_DEBUGGER_WATCH_H
#define FUSE_DEBUGGER_WATCH_H

/* Types of watch */
typedef enum debugger_watch_type {
  DEBUGGER_WATCH_TYPE_U8 = 1,		/* Start marker */
  DEBUGGER_WATCH_TYPE_U16,
  DEBUGGER_WATCH_TYPE_END		/* End marker */
} debugger_watch_type;

/* Watch structure */
typedef struct debugger_watch {
  size_t id;

  libspectrum_dword address;
  debugger_watch_type type;
  char *name;
} debugger_watch;

/* The current breakpoints */
extern GSList *debugger_watches;

/* Add a new watch */
int
debugger_watch_add(
  libspectrum_dword address, const char *watch_type
);

debugger_watch *
get_watch_by_id( size_t id );

#endif				/* #ifndef FUSE_DEBUGGER_WATCH_H */
