#include <gtk/gtk.h>
#include <stdlib.h>
#include <glib.h>

GtkWidget *status_bar;

void push_item(GtkWidget *widget, gpointer data)
{
    static int count = 1;
    char buff[20];

    g_snprintf(buff, 20, "Item %d", count ++);
    gtk_statusbar_push(GTK_STATUSBAR(status_bar), GPOINTER_TO_INT(data), buff);

    return;
}

void pop_item(GtkWidget *widget, gpointer data)
{
    gtk_statusbar_pop(GTK_STATUSBAR(status_bar), GPOINTER_TO_INT(data));
    return;
}

int main(int argc, char **argv)
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *button;

    gint context_id;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(GTK_WIDGET(window), 200, 100);
    gtk_window_set_title(GTK_WINDOW(window), "Gtk Statusbar Example");
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(exit), NULL);

    vbox = gtk_vbox_new(FALSE, 1);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show(vbox);

    status_bar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(vbox), status_bar, TRUE, TRUE, 0);
    gtk_widget_show(status_bar);

    context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(status_bar), "Statusbar example");

    button = gtk_button_new_with_label("push item");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(push_item), GINT_TO_POINTER(context_id));
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 2);
    gtk_widget_show(button);

    button = gtk_button_new_with_label("pop last item");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(pop_item), GINT_TO_POINTER(context_id));
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 2);
    gtk_widget_show(button);

    gtk_widget_show(window);
    gtk_main();

    return 0;

}
