#include <gtk/gtk.h>
#include <stdlib.h>

GtkWidget *xpm_label_box(gchar *xpm_filename, gchar *label_text)
{
	GtkWidget *box;
    GtkWidget *label;
	GtkWidget *image;

	box = gtk_hbox_new(FALSE, 0);
	gtk_container_set_border_width(GTK_CONTAINER(box), 2);

	image = gtk_image_new_from_file(xpm_filename);	
	label = gtk_label_new(label_text);

	gtk_box_pack_start(GTK_BOX(box), image, FALSE, FALSE, 3);
	gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 3);

	gtk_widget_show(image);
	gtk_widget_show(label);

	return box;
}
void callback(GtkWidget *widget, gpointer data)
{
	g_print("Hello again - %s was pressed\n", (char *)data);
}


int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *box;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Pixmap'd Buttons!");
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	
	button = gtk_button_new();
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(callback), (gpointer)"cool button");

	box = xpm_label_box("/usr/share/icons/Windows7-iSoft/actions/22/computer.png", "cool button");
	gtk_widget_show(box);
	gtk_container_add(GTK_CONTAINER(button), box);
	gtk_widget_show(button);
	gtk_container_add(GTK_CONTAINER(window), button);

	gtk_widget_show(window);
    
	

	gtk_main();
	return 0;
}
