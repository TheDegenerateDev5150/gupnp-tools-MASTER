/*
 * Copyright (C) 2007 Zeeshan Ali <zeenix@gstreamer.net>
 *
 * Authors: Zeeshan Ali <zeenix@gstreamer.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <string.h>
#include <stdlib.h>
#include <config.h>

#include "av-cp-gui.h"
#include "av-cp-playlisttreeview.h"
#include "av-cp.h"

#define GLADE_FILE "gupnp-av-cp.glade"

static GladeXML  *glade_xml;
static GtkWidget *main_window;
static GtkWidget *about_dialog;

void
add_media_renderer (GUPnPDeviceProxy *renderer)
{
}

void
remove_media_renderer (GUPnPDeviceProxy *renderer)
{
}

gboolean
on_delete_event (GtkWidget *widget,
                 GdkEvent  *event,
                 gpointer   user_data)
{
        application_exit ();

        return TRUE;
}

gboolean
init_ui (gint   *argc,
         gchar **argv[])
{
        gint       window_width, window_height;
        gchar     *glade_path = NULL;

        gtk_init (argc, argv);
        glade_init ();
        g_thread_init (NULL);

        /* Try to fetch the glade file from the CWD first */
        glade_path = GLADE_FILE;
        if (!g_file_test (glade_path, G_FILE_TEST_EXISTS)) {
                /* Then Try to fetch it from the system path */
                glade_path = DATA_DIR "/" GLADE_FILE;

                if (!g_file_test (glade_path, G_FILE_TEST_EXISTS))
                        glade_path = NULL;
        }

        if (glade_path == NULL) {
                g_critical ("Unable to load the GUI file %s", GLADE_FILE);
                return FALSE;
        }

        glade_xml = glade_xml_new (glade_path, NULL, NULL);
        if (glade_xml == NULL)
                return FALSE;

        main_window = glade_xml_get_widget (glade_xml, "main-window");
        g_assert (main_window != NULL);
        about_dialog = glade_xml_get_widget (glade_xml, "about-dialog");
        g_assert (about_dialog != NULL);

        /* 40% of the screen but don't get bigger than 1000x800 */
        window_width = CLAMP ((gdk_screen_width () * 40 / 100), 10, 1000);
        window_height = CLAMP ((gdk_screen_height () * 40 / 100), 10, 800);
        gtk_window_set_default_size (GTK_WINDOW (main_window),
                                     window_width,
                                     window_height);

        gtk_about_dialog_set_version (GTK_ABOUT_DIALOG (about_dialog),
                                      VERSION);

        glade_xml_signal_autoconnect (glade_xml);

        setup_playlist_treeview (glade_xml);

        gtk_widget_show_all (main_window);

        return TRUE;
}

void
deinit_ui (void)
{
        g_object_unref (glade_xml);
        gtk_widget_destroy (main_window);
        gtk_widget_destroy (about_dialog);
}

