#include <gtk/gtk.h>

static int status_count = 0;
guint context_id;

void on_window_destroy(GtkWidget *widget, gpointer user_data)
{
	gtk_main_quit();
}

void on_gtk_about_activate(GtkWidget *widget, gpointer user_data)
{
    gtk_dialog_run(GTK_DIALOG(user_data));
	gtk_widget_hide(GTK_WIDGET(user_data));
}

void on_gtk_quit_activate(GtkWidget *widget, gpointer user_data)
{
    gtk_main_quit();
}

void on_push_status_activate(GtkWidget *widget, gpointer user_data)
{
	status_count ++;
	gchar * str;
	str = g_strdup_printf("Message number %d", status_count);
	context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(user_data),"staus");
	gtk_statusbar_push(GTK_STATUSBAR(user_data), context_id, str);
}
void on_pop_status_activate(GtkWidget *widget, gpointer user_data)
{
	status_count --;
	context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(user_data),"staus");
	gtk_statusbar_pop(GTK_STATUSBAR(user_data), context_id);

}
void on_clear_status_activate(GtkWidget *widget, gpointer user_data)
{
	context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(user_data),"staus");
	while(status_count > 0)
	{
		status_count --; 
        gtk_statusbar_pop(GTK_STATUSBAR(user_data), context_id);
	}
}

int main(int argc, char *argv[])
{
	GtkBuilder *builder;
	GtkWidget *window;

	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "tutorial.glade", NULL);
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(G_OBJECT(builder));
	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
}
