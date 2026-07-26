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
#include "debugger/debugger_internals.h"
#include "settings.h"
#include "win32internals.h"

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


// Auto complete functions.

BOOL auto_complete_ok = FALSE;
HWND auto_complete_window = NULL;
GSList *auto_complete_list = NULL;
int auto_complete_beam_start = -1;
int auto_complete_typed_length = 0;

void
parse_autocomplete(char *line, void *parameter)
{
  char *split = strstr(line, ": EQU ");
  if(split)
  {
    *split = 0;
    int length = strlen(line);
    char *copy = malloc(length + 1);
    memset(copy, 0, length + 1);
    memcpy(copy, line, length);
    auto_complete_list = g_slist_append( auto_complete_list, copy );
  }
}

char
*match_auto_complete(char *source, char *match)
{
  char *character = source;
  while(*character)
  {
    if(toupper(*character)==toupper(*match))
    {
      char *one = character + 1;
      char *two = match + 1;
      while(1)
      {
        if(!*two)
          // Matched all the characters.
          return character;
       if(!*one)
         // Ran out of source characters.
         break;
       if(toupper(*one)!=toupper(*two))
         break;
      one++;
      two++;
      }
    }
    character++;
  }
  return NULL;
}

void
show_auto_complete()
{
  if( !settings_current.debugger_sym_file )
    return;

  if( !auto_complete_list )
  {
    /* Load in symbols into completion list. */
    char *auto_complete_buffer = NULL;
    if( debugger_load_symbol_file_to_buffer(settings_current.debugger_sym_file,
      &auto_complete_buffer) )
    {
      debugger_parse_lines_from_buffer(auto_complete_buffer, parse_autocomplete, NULL);
      if(auto_complete_list)
        auto_complete_ok = TRUE;
      free( auto_complete_buffer );
    }
  }

  if( !auto_complete_ok )
    return;

  /* Get the current command. */
  char *line = get_command_text();
  if(!line)
    return;

  if(auto_complete_beam_start==-1)
  {
    /* Get position of caret when we typed $. */
    DWORD start = 0, end = 0;
    SendMessage(debugger_edit_area, EM_GETSEL, (WPARAM)&start, (LPARAM)&end);
    auto_complete_beam_start = (int)start;
  }

  char *typed = &line[auto_complete_beam_start + 1]; // +1 to skip $

  //char dbg[256];
  //wsprintf(dbg, "'%s' '%s'", line, typed);
  //MessageBox(NULL, dbg, "debug", MB_OK);

  RECT debugger_edit_area_rect;
  GetWindowRect(debugger_edit_area, &debugger_edit_area_rect);

  if(!auto_complete_window)
  {
    /* Create popup completion list window. */
    HWND desktop = GetDesktopWindow();
    RECT desktop_rect;
    int auto_complete_window_y = debugger_edit_area_rect.bottom;
    GetWindowRect(desktop, &desktop_rect);
    if(debugger_edit_area_rect.bottom + AUTO_COMPLETE_HEIGHT > desktop_rect.bottom)
      // No space so put completion list above the edit area.
      auto_complete_window_y = debugger_edit_area_rect.top - AUTO_COMPLETE_HEIGHT;

    auto_complete_window = CreateWindowEx(WS_EX_NOACTIVATE|WS_EX_TOPMOST, "LISTBOX", "", WS_POPUP|WS_BORDER|LBS_SORT|LBS_NOINTEGRALHEIGHT|WS_VSCROLL,
      debugger_edit_area_rect.left, auto_complete_window_y, debugger_edit_area_rect.right - debugger_edit_area_rect.left, AUTO_COMPLETE_HEIGHT, debugger_edit_area, NULL, fuse_hInstance, 0);
    HFONT auto_complete_font = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
    SendMessage( auto_complete_window, WM_SETFONT, (WPARAM) auto_complete_font, FALSE );
  }

  auto_complete_typed_length = strlen(typed);
  if(auto_complete_typed_length < 2)
  {
    free(line);
    return;
  }

  SendMessage(auto_complete_window, LB_RESETCONTENT, 0, 0);
  GSList *ptr;
  int added = 0;
  for( ptr = auto_complete_list; ptr; ptr = ptr->next )
  {
    char *text = ptr->data;
    if(match_auto_complete(text, typed))
    {
      LRESULT index = SendMessageA(auto_complete_window, LB_ADDSTRING, 0, (LPARAM)text);
      SendMessage(auto_complete_window, LB_SETITEMDATA, index, (LPARAM)text);
      added++;
    }
  }

  if(added)
  {
    /* Show list and add any matching entries. */
    ShowWindow(auto_complete_window, SW_SHOWNA);
    SendMessage(auto_complete_window, LB_SETCURSEL, 0, 0);
  }
  else
    ShowWindow(auto_complete_window, SW_HIDE);

  free(line);
}

void
reset_auto_complete(BOOL insert)
{
  if(auto_complete_window)
  {
    if(insert)
    {
      /* Get text from the auto complete list. */
      int selection = SendMessage(auto_complete_window, LB_GETCURSEL, 0, 0);
      if(selection!=LB_ERR)
      {
        char *auto_complete_text = (char *)SendMessage(auto_complete_window, LB_GETITEMDATA, selection, 0);
        if(auto_complete_text)
        {
          /* Replace typed text with auto complete text. */
          auto_complete_beam_start++;
          int auto_complete_beam_end = auto_complete_beam_start + auto_complete_typed_length;
          SendMessage(debugger_edit_area, EM_SETSEL, auto_complete_beam_start, auto_complete_beam_end);
          SendMessage(debugger_edit_area, EM_REPLACESEL, FALSE, (LPARAM)auto_complete_text);
          auto_complete_beam_end = auto_complete_beam_start + strlen(auto_complete_text);
          SendMessage(debugger_edit_area, EM_SETSEL, auto_complete_beam_end, auto_complete_beam_end);
        }
      }
    }
    DestroyWindow(auto_complete_window);
    auto_complete_window = NULL;
    auto_complete_beam_start = -1;
    auto_complete_typed_length = 0;
  }
}

BOOL
in_auto_complete()
{
  if(auto_complete_window && IsWindowVisible(auto_complete_window))
    return TRUE;
  
  return FALSE;
}

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
          if(!auto_complete_window)
            get_command_from_history(TRUE);
          else
          {
            /* Relay keypress to the auto complete list. */
            SendMessage(auto_complete_window, uMsg, wParam, lParam);
          }
          return 0;
        case VK_DOWN:
          if(!auto_complete_window)
            get_command_from_history(FALSE);
          else
          {
            SendMessage(auto_complete_window, uMsg, wParam, lParam);
          }
          return 0;

        case VK_HOME:
        case VK_END:
        case VK_NEXT:
        case VK_PRIOR:
        {
          if(auto_complete_window)
          {
            SendMessage(auto_complete_window, uMsg, wParam, lParam);
            return 0;
          }
          break;
        }

        case VK_F11:
          debugger_step();
          break;
      }
      break;
    }
    break;

    case WM_KEYUP:
    {
      switch(wParam)
      {
        case VK_UP:
        case VK_DOWN:
        case VK_HOME:
        case VK_END:
        case VK_PRIOR:
        case VK_NEXT:
          if(auto_complete_window)
            /* Auto complete list has already handled these. */
            return 0;
          break;
        default:
        {
          if(auto_complete_window)
            /* Update auto complete list with latest keypress. */
            show_auto_complete();
        }
      }
    }
    break;

    case WM_CHAR:
    {
      switch(wParam)
      {
        case 0x24:	// $
        {
        if(!auto_complete_window)
          show_auto_complete();
        }
        break;
      }
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

char *
get_command_text()
{
  char *command = NULL;
  int command_size = SendMessage( debugger_edit_area, WM_GETTEXTLENGTH,
                                   (WPARAM) 0, (LPARAM) 0 );
  command = malloc( ( command_size + 1 ) * sizeof( char ) );
  if(!command)
    return command;

  SendMessageA( debugger_edit_area, WM_GETTEXT, (WPARAM) ( command_size + 1 ),
                          (LPARAM) command );
  return command;
}
