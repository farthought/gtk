#include <gtk/gtk.h>

int main(int argc, char ** argv)
{
    GtkWidget *window;
    GtkWidget *scrolled;
    GtkWidget *text;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window, 200, 200);
    gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), scrolled);
    gtk_widget_show(scrolled);

    text = gtk_text_view_new();
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled), text);
    gtk_widget_show(text);

    gtk_widget_show(window);
    gtk_main();


}
