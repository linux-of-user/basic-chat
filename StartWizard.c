/* This program runs when preference.txt is not found. It will show
 * a window and ask the user to set preferences. It will then save them
 * and create the file preferences.txt */

/* Dependancies: GTK 3.0 */

#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

int sel;
const char *username;
const char *password;


GtkWidget *usr;
GtkWidget *pssd;

/* Defining Functions */

void save();

void combo_change(GtkWidget *wid, gpointer ptr)
{
    sel = gtk_combo_box_get_active(GTK_COMBO_BOX(wid));
    printf("The value is %d\n", sel);
}

void save_username(GtkWidget *wid, gpointer ptr)
{
    const char *usrname = gtk_entry_get_text(GTK_ENTRY(usr));
    const char *passwd = gtk_entry_get_text(GTK_ENTRY(pssd));
    printf("Username: %s\n", usrname);
    printf("Password: %s\n", passwd);
    username = usrname;
    password = passwd;
    save();
}

void quit(GtkWidget *wid, gpointer ptr)
{
	char *args[]={"./Init",NULL};
	execv (args[0],args);
    gtk_main_quit();
}

void save()
{
    FILE *ptxt;
    ptxt = fopen("Preferences.filset", "w");
    printf("Debug: Encryption level is %d\n", sel);
    printf("Debug: Username is %s\n", username);
    printf("Debug: Password is %s\n", password);
    fprintf(ptxt, "%d #DEBUG encryption level#\n", sel);
    fprintf(ptxt, "%s #DEBUG username#\n", username);
    fprintf(ptxt, "%s #DEBUG password#\n", password);
    printf("File Written to");
    fclose(ptxt);
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    printf("Startwizard started successfully\n");

    gtk_init(&argc, &argv);

    /* Defining Widgets */

    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *btn = gtk_button_new_with_label("Exit");
    GtkWidget *grd = gtk_grid_new();
    GtkWidget *enc = gtk_combo_box_text_new();
    GtkWidget *svusr = gtk_button_new_with_label("Save");
    GtkWidget *lblusr = gtk_label_new("Username:");
    GtkWidget *lblpssd = gtk_label_new("Password:");
    GtkWidget *frame = gtk_frame_new(NULL);

    usr = gtk_entry_new();
    pssd = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(pssd), FALSE);
    gtk_entry_set_invisible_char(GTK_ENTRY(pssd), '*');

    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(enc), "Weak Encryption");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(enc), "Standard Encryption");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(enc), "Strong Encryption");
    gtk_combo_box_set_active(GTK_COMBO_BOX(enc), 0);

    /* Adding functions to widgets */

    g_signal_connect(btn, "clicked", G_CALLBACK(quit), NULL);
    g_signal_connect(win, "delete_event", G_CALLBACK(quit), NULL);
    g_signal_connect(enc, "changed", G_CALLBACK(combo_change), NULL);
    g_signal_connect(svusr, "clicked", G_CALLBACK(save_username), NULL);

    /* Attaching to window via grid */

    gtk_container_set_border_width(GTK_CONTAINER(win), 10);
    gtk_container_add(GTK_CONTAINER(frame), lblpssd);
    gtk_grid_attach(GTK_GRID(grd), lblusr, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grd), usr, 2, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(grd), frame, 1, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(grd), pssd, 2, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(grd), enc, 1, 2, 2, 1);
	gtk_grid_attach(GTK_GRID(grd), svusr, 2, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(grd), btn, 1, 3, 1, 1);
	gtk_container_add(GTK_CONTAINER(win), grd);

	gtk_widget_show_all(win);

	gtk_main();

	return 0;
}
