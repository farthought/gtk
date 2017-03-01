#include <gtk/gtk.h>
#include <glib.h>

void my_callback_function(GtkWidget *widget, GtkWidget *entry )
{
    const gchar * entry_text;
    entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
    printf("Entry contents:%s\n", entry_text);
}

int main(int argc, char **argv)
{
    GtkWidget *window;    
    GtkWidget *combo;
    GtkWidget *vbox;
    GList *list = NULL;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_title(GTK_WINDOW(window), "Combo Box");

    vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    combo = gtk_combo_new();
    gtk_entry_set_text(GTK_ENTRY(GTK_COMBO(combo)->entry), "My String.");
    gtk_box_pack_start(GTK_BOX(vbox), combo, TRUE, TRUE, 5);
    
    list = g_list_append(list, "First");
    list = g_list_append(list, "Second");
    list = g_list_append(list, "Third");
    list = g_list_append(list, "Fourth");
    gtk_combo_set_popdown_strings(GTK_COMBO(combo), list);

    gtk_combo_set_use_arrows(GTK_COMBO(combo), TRUE);
    gtk_combo_set_use_arrows_always(GTK_COMBO(combo), TRUE);
    gtk_combo_set_case_sensitive(GTK_COMBO(combo), TRUE);

    g_signal_connect(G_OBJECT(GTK_COMBO(combo)->entry), "activate", G_CALLBACK(my_callback_function), GTK_COMBO(combo)->entry);
    gtk_widget_show(combo);
    gtk_widget_show(vbox);
    gtk_widget_show(window);
    gtk_main();

    return 0;

}
