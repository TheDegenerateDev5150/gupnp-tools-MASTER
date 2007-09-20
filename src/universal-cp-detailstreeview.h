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
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __GUPNP_UNIVERSAL_CP_DETAILS_TREEVIEW_H__
#define __GUPNP_UNIVERSAL_CP_DETAILS_TREEVIEW_H__

#include <gtk/gtk.h>
#include <glade/glade.h>

void
update_details                  (const char      **tuples);

void
setup_details_treeview          (GladeXML *glade_xml);

#endif /* __GUPNP_UNIVERSAL_CP_DETAILS_TREEVIEW_H__ */
