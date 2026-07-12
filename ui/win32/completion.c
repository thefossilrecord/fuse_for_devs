/* completion.c: auto complete for debugger text entry
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

#include <windows.h>
#include <commctrl.h>
#include <stdio.h>

#include "completion.h"
#include "debugger/debugger.h"

// Command history functions.

HWND debugger_edit_area = NULL;
char *command_history_lookup[MAX_COMMAND_HISTORY] = {0};
int command_history_slot = 0;
int command_history_selected = -1;

void
dump_command_history()
{
  for(int dump = 0; dump < MAX_COMMAND_HISTORY; dump++)
  {
    if(command_history_lookup[dump])
    {
      printf("[%d]='%s'\n", dump, command_history_lookup[dump]);
    }
  }
}

void
get_command_from_history(BOOL previous)
{
  char *restore = NULL;
  if(command_history_selected==-1)
  {
    // First time, so go with the current entry.
    command_history_selected = command_history_slot;
  }
  else
  {
    if(previous)
      {
        if(command_history_selected > 0)
          // Move back an entry.
          command_history_selected--;
      }
    else
    {
      if(command_history_selected < MAX_COMMAND_HISTORY - 1)
      {
        int next = command_history_selected + 1;
        if(command_history_lookup[next])
          // Move to the next entry as there's something there.
          command_history_selected++;
      }
    }
  }

  restore = command_history_lookup[command_history_selected];

  if(restore)
  {
    // Clear the current text, drop in the text from the command history
    // and position the caret at the end of the line.
    SetWindowTextA(debugger_edit_area, "");
    SetWindowTextA(debugger_edit_area, restore);
    int restore_length = strlen(restore);
    SendMessage(debugger_edit_area, EM_SETSEL, (WPARAM)restore_length, (LPARAM)restore_length);
  }
}

void
update_command_history(char *command)
{
  if(!command)
    return;

  int save_slot = -1;

  char *previous_command = command_history_lookup[command_history_slot];
  if(previous_command)
  {
    if(!stricmp(command, previous_command))
    {
      command_history_selected = -1;
      return;
    }
    else
    {
      save_slot = command_history_slot;
      if(save_slot + 1 < MAX_COMMAND_HISTORY)
        save_slot++;
      else
      {
        free(command_history_lookup[0]);
        for(int move = 0; move < MAX_COMMAND_HISTORY - 1; move++)
          command_history_lookup[move] = command_history_lookup[move + 1];
      }
    }
  }
  else
  {
    // Empty lookup.
    save_slot = 0;
  }

  if(save_slot!=-1)
  {
    // Add command to the specified slot.
    int alloc = strlen(command) + 1;
    char *copy = (char *)malloc(alloc);
    memset(copy, 0, alloc);
    memcpy(copy, command, alloc - 1);
    command_history_slot = save_slot;
    command_history_lookup[save_slot] = copy;
    command_history_selected = -1;
  }

  //dump_command_history();

  SetWindowTextA(debugger_edit_area, "");
}


//
/*
static
gboolean text_entry_keypress(GtkWidget *widget, GdkEventKey *event,
                               gpointer user_data)
{
  gboolean handled = FALSE;
  switch(event->keyval)
  {
    case GDK_KEY_Up:
      //g_print("Cursor up\n");
      if(!in_auto_complete)
      {
        get_command_from_history(TRUE);
        handled = TRUE;
      }
      break;

    case GDK_KEY_Down:
      //g_print("Cursor down\n");
      if(!in_auto_complete)
      {
        get_command_from_history(FALSE);
        handled = TRUE;
      }
      break;

    case GDK_KEY_dollar:
      //g_print("$\n");
      if(auto_complete_ok)
        in_auto_complete = TRUE;
      break;

//    default:
//      g_print("keypress: %#06x %#06x\n", event->keyval, event->hardware_keycode);
  }

  return handled;
  }
*/

LRESULT CALLBACK
debugger_edit_subclass_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
  switch(uMsg)
  {
    case WM_KEYDOWN:
    {
      switch(wParam)
      {
        case VK_UP:
          get_command_from_history(TRUE);
          return 0;
        case VK_DOWN:
          get_command_from_history(FALSE);
          return 0;
        case VK_F11:
          debugger_step();
          break;
      }
      break;
    }
    break;

    case WM_SYSKEYDOWN:
    {
      switch(wParam)
      {
        case VK_F10:
          debugger_next();
          return 0;
      }
    }
    break;
  }
  return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}

void
init_command_history(HWND edit)
{
  debugger_edit_area = edit;
  SetWindowSubclass(edit, (SUBCLASSPROC)debugger_edit_subclass_proc, 100, 0);
}
