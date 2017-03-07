#include <stdlib.h>
#include <gtk/gtk.h>

int main( int   argc, char *argv[] )
{
	GtkWidget *window;
	GtkWidget *socket;

	gtk_init (&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_set_size_request(window, 200, 200);

	socket = gtk_socket_new();
	gtk_widget_show (socket);
	gtk_container_add (GTK_CONTAINER (window), socket);
	gtk_widget_show (window);
	g_message("socket_id=%d\n", gtk_socket_get_id(GTK_SOCKET(socket)));
	gtk_main ();
	return 0;

}
