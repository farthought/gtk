#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <glib.h>

void on_button_clicked(GtkWidget *widget, gpointer data)
{
	g_printf("plug button clicked\n");
}

int main( int   argc,  char *argv[] )
{
	gint socket_id = 0;

	GtkWidget *window;
	GtkWidget *button;

	gtk_init (&argc, &argv);

	if(argc != 2)
	{
		g_message("usage: %s [socket]\n", argv[0]);
		return -1;
	}
	else
	{
		socket_id = atoi(argv[1]);
	}

	window = gtk_plug_new(socket_id);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	button = gtk_button_new_with_label("button_plug");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(on_button_clicked), NULL);
	gtk_widget_show (button);
	gtk_container_add (GTK_CONTAINER (window), button);
	gtk_widget_show (window);

	gtk_main ();
	return 0;

}
