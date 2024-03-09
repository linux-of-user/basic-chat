#include <stdio.h>
#include <gtk/gtk.h>

char username[16];
char password[26];

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE); // Remove title bar
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); // Center window on screen



    GtkWidget *image = gtk_image_new_from_file("Logo.gif");
    
    GtkWidget *label = gtk_label_new("Chat App Rev 1 Loading..."); // Create a new label widget
    gtk_label_set_xalign(GTK_LABEL(label), 0.5); // Set the horizontal alignment to center

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_box_pack_start(GTK_BOX(box), image, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

