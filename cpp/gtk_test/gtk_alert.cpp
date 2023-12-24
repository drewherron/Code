// g++ gtk_alert.cpp `pkg-config --cflags --libs gtk+-3.0` -o gtk_alert

#include <gtk/gtk.h>

static void on_submit_clicked(GtkWidget *submit_button, gpointer data) {
    GtkWidget *entry = (GtkWidget *)data;
    const char *text = gtk_entry_get_text(GTK_ENTRY(entry));
    g_print("Entered text: %s\n", text);

    // Clear the text entry after submission
    gtk_entry_set_text(GTK_ENTRY(entry), "");
}

static void on_quit_clicked(GtkWidget *quit_button, gpointer data) {
    GApplication *app = G_APPLICATION(data);
    g_application_quit(app);
}

static void activate(GtkApplication* app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *entry;
    GtkWidget *submit_button;
    GtkWidget *quit_button;
    GtkWidget *box;

    // Create a window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Text Echo");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 150);

    // Create a box to arrange widgets
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Create a text entry
    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);

    // Create a submit button
    submit_button = gtk_button_new_with_label("Submit");
    gtk_box_pack_start(GTK_BOX(box), submit_button, FALSE, FALSE, 0);
    g_signal_connect(submit_button, "clicked", G_CALLBACK(on_submit_clicked), entry);

    // Create a quit button
    quit_button = gtk_button_new_with_label("Quit");
    gtk_box_pack_start(GTK_BOX(box), quit_button, FALSE, FALSE, 0);
    g_signal_connect(quit_button, "clicked", G_CALLBACK(on_quit_clicked), app);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.example.textecho", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
