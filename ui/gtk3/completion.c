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

#define _GNU_SOURCE

#include <gtk/gtk.h>
#include <string.h>

#include "settings.h"

#define COMPLETION_HEIGHT 480

gboolean in_auto_complete = FALSE;
gint auto_complete_caret_start = -1;
gint auto_complete_typed_length = -1;

void
reset_auto_complete()
{
  in_auto_complete = FALSE;
  auto_complete_caret_start = -1;
  auto_complete_typed_length = -1;
}

static gboolean
completion_match_selected(GtkEntryCompletion *completion, GtkTreeModel *model,
                           GtkTreeIter *iter, gpointer user_data)
{
  gchar *completion_text = NULL;
  gboolean ok = FALSE;

  // Gettext from from column 0.
  gtk_tree_model_get(model, iter, 0, &completion_text, -1);
  if(completion_text)
  {
    //g_print("User selected: %s\n", completion_text);

    // Get the text entry associated with the completion.
    GtkWidget *entry = gtk_entry_completion_get_entry(completion);
    // Get current cursor position in characters
    gint position = gtk_editable_get_position(GTK_EDITABLE(entry));
    // Delete text typed from the $ to the caret.
    gtk_editable_delete_text(GTK_EDITABLE(entry), auto_complete_caret_start, position);
    // Insert completion text at the caret.
    position = auto_complete_caret_start;
    gtk_editable_insert_text(GTK_EDITABLE(entry), completion_text, -1, &position);
    // Move the caret to the end of text that was just inserted.
    gtk_editable_set_position(GTK_EDITABLE(entry), auto_complete_caret_start + strlen(completion_text));

    g_free(completion_text);
    // Set ok to stop GTK from applying its default text insertion.
    ok = TRUE;
  }

  reset_auto_complete();
  return ok;
}

// Custom match function
static gboolean
completion_match_func(GtkEntryCompletion *completion, const gchar *key,
                  GtkTreeIter *iter, gpointer user_data)
{
  GtkTreeModel *model;
  gchar *completion_text;
  gboolean is_match = FALSE;

  if(!in_auto_complete)
    return is_match;

  if(auto_complete_caret_start==-1)
  {
    // Get the text entry associated with the completion.
    GtkWidget *entry = gtk_entry_completion_get_entry(completion);
    // Get current cursor position in characters.
    auto_complete_caret_start = gtk_editable_get_position(GTK_EDITABLE(entry));
  }

  const gchar *characters = &key[auto_complete_caret_start];
  if(*characters==0)
    // String after $ is 0 bytes long.
    return is_match;

  //g_print("%s %d '%s'\n", key, auto_complete_caret_start, characters);

  // Get the model from the completion.
  model = gtk_entry_completion_get_model(completion);
  if(model)
  {
    // Get the string from the model - text is in column 0.
    gtk_tree_model_get(model, iter, 0, &completion_text, -1);
    if(completion_text)
    {
      // Check for what we've typed inside the text.
      if (strcasestr((char *)completion_text, (char *)characters))
      {
        auto_complete_typed_length = strlen(characters);
        is_match = TRUE;
      }
      g_free(completion_text);
    }
  }

  return is_match;
  }

//

static
gboolean text_entry_keypress(GtkWidget *widget, GdkEventKey *event,
                               gpointer user_data)
{
  switch(event->keyval)
  {
    case GDK_KEY_Up:
      g_print("Cursor up\n");
      break;

    case GDK_KEY_Down:
      g_print("Cursor down\n");
      break;

    case GDK_KEY_dollar:
      //g_print("$\n");
      in_auto_complete = TRUE;
      break;

//    default:
//      g_print("keypress: %#06x %#06x\n", event->keyval, event->hardware_keycode);
  }

  return FALSE;
  }

void
add_completion_to_entry(GtkWidget *text_entry)
{
  // Create a list store from the sym file.
  GtkListStore *store = NULL;
  int store_size = 0;

  FILE *sym_file = fopen(settings_current.debugger_sym_file, "r");
  if(sym_file)
  {
    //printf("Sym File: %s\n", settings_current.debugger_sym_file);
    store = gtk_list_store_new(1, G_TYPE_STRING);
    char *line = NULL;
    size_t len = 0;
    size_t read = 0;
    GtkTreeIter iter;

    while((read = getline(&line, &len, sym_file)) != -1)
    {
      /* Sym file line format is:
         <name>: EQU <address>
      */
      char *split = strstr(line, ": EQU ");
      if(split)
      {
        *split = 0;
        int length = strlen(line);

        gtk_list_store_append(store, &iter);
        gchar *new_entry = (gchar *)malloc(length + 1);// 2);
        gchar *pointer = new_entry;

        memcpy(pointer, line, length + 1);

        gtk_list_store_set(store, &iter, 0, new_entry, -1);
        store_size++;
      }
    }

    if(line)
      free(line);

    fclose(sym_file);
  }

  if(!store_size)
    return;

  // Create an entry completion.
  GtkEntryCompletion *completion = gtk_entry_completion_new();
  gtk_entry_completion_set_model(completion, GTK_TREE_MODEL(store));
  gtk_entry_completion_set_text_column(completion, 0);
  // Disable inline completion and enable the popup.
  gtk_entry_completion_set_inline_completion(completion, FALSE);
  gtk_entry_completion_set_popup_completion(completion, TRUE);
  // Add custom code for matching and finalising the auto complete.
  gtk_entry_completion_set_match_func(completion, completion_match_func, NULL, NULL);
  g_signal_connect(completion, "match-selected", G_CALLBACK(completion_match_selected), NULL);
  // Add inline completion to the text entry.
  gtk_entry_set_completion(GTK_ENTRY(text_entry), completion);

  g_signal_connect(text_entry, "key_press_event", G_CALLBACK(text_entry_keypress), NULL);

  // Clean up references.
  g_object_unref(store);
  g_object_unref(completion);
}
