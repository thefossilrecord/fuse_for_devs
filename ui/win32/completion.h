/* completion.h: auto complete for debugger text entry
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

*/

#ifndef FUSE_COMPLETION_H
#define FUSE_COMPLETION_H

// Maximum size of command history buffer.
#define MAX_COMMAND_HISTORY 32

#define AUTO_COMPLETE_HEIGHT 150

void reset_auto_complete(BOOL insert);
BOOL in_auto_complete();
char *get_command_text();
void init_command_history(HWND edit);

void update_command_history(char *command);

#endif
