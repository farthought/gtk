#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <stdlib.h>
#include <string.h>
#include <gdk/gdkkeysyms.h>

gboolean key_value(GtkWidget *widget, GdkEventKey *event, gpointer data)
{
    GtkWidget *label = (GtkWidget *)data;
    guint keyvalue = event->keyval;
    gchar temp[100];
    strcpy(temp, "press: ");
    if(event->state & GDK_CONTROL_MASK)
        strcat(temp, "CTRL+");
    if(event->state & GDK_SHIFT_MASK)
        strcat(temp, "SHIFT+");
    if(event->state & GDK_META_MASK)
        strcat(temp, "ALT+");
    if(event->state & GDK_LOCK_MASK)
        strcat(temp, "LOCK+"); 
    strcat(temp, gdk_keyval_name(event->keyval));
    gtk_label_set_text (GTK_LABEL(label), temp);
    g_print("%s, ",temp);
    g_print("%s value 0x%x/n", gdk_keyval_name(event->keyval), event->keyval);
    gtk_entry_set_text(GTK_ENTRY(widget), "");
    return FALSE;
}
int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *hbox;
    GtkWidget *label;
    GtkWidget *button;
    GtkWidget *entry;
   
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
    hbox = gtk_hbox_new(FALSE, 10);
    gtk_container_set_border_width(GTK_CONTAINER(hbox), 10);
    gtk_container_add (GTK_CONTAINER(window), hbox);

    label = gtk_label_new ("please press any key");
    gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 10);
   
    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), entry, FALSE, FALSE, 10);

    button = gtk_button_new_with_label ("close");
    gtk_box_pack_start(GTK_BOX(hbox), button, FALSE, FALSE, 10);

    gtk_widget_show_all(window);
    g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(entry, "key-press-event", G_CALLBACK(key_value), label);
    gtk_main();
    return 0;
}
