#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "Chat App");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Create a header bar
    GtkWidget *header_bar = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(header_bar), "Chat App");
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header_bar), TRUE);
    gtk_window_set_titlebar(GTK_WINDOW(window), header_bar);

    // Create a box for the content
    GtkWidget *content_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), content_box);

    // Create a scrolled window for the chat history
    GtkWidget *chat_history_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(chat_history_scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(content_box), chat_history_scrolled, TRUE, TRUE, 0);

    // Create a text view for the chat history
    GtkTextBuffer *chat_history_buffer = gtk_text_buffer_new(NULL);
    GtkWidget *chat_history_view = gtk_text_view_new_with_buffer(chat_history_buffer);
    gtk_container_add(GTK_CONTAINER(chat_history_scrolled), chat_history_view);

    // Create a scrolled window for the text entry
    GtkWidget *text_entry_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(text_entry_scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_end(GTK_BOX(content_box), text_entry_scrolled, FALSE, FALSE, 0);

    // Create a text view for the text entry
    GtkTextBuffer *text_entry_buffer = gtk_text_buffer_new(NULL);
    GtkWidget *text_entry_view = gtk_text_view_new_with_buffer(text_entry_buffer);
    gtk_container_add(GTK_CONTAINER(text_entry_scrolled), text_entry_view);

    // Create a button box for the buttons
    GtkWidget *button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add(GTK_CONTAINER(content_box), button_box);

    // Create the buttons
    GtkWidget *send_button = gtk_button_new_with_label("Send");
    GtkWidget *clear_button = gtk_button_new_with_label("Clear");

    // Pack the buttons into the button box
    gtk_box_pack_start(GTK_BOX(button_box), send_button, TRUE, TRUE, 0);
    gtk_box_pack_end(GTK_BOX(button_box), clear_button, TRUE, TRUE, 0);

    // Set high contrast theme
    GtkCssProvider *provider;
    GFile *file;
    GError *error = NULL;

    provider = gtk_css_provider_new();
    file = g_file_new_for_path("high-contrast.css");
    gtk_css_provider_load_from_file(provider, file, &error);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                               GTK_STYLE_PROVIDER(provider),
                                               GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
