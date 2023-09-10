#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    // Initialize GTK+
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "morpion");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 350, 500);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a grid for the buttons
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create nine buttons and add them to the grid
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file("image/blank.png", NULL);
            GtkWidget* image = gtk_image_new_from_pixbuf(pixbuf);
            GtkWidget *button = gtk_button_new();
            gtk_button_set_image(GTK_BUTTON(button),image);
            gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);
            gtk_widget_set_hexpand(button, TRUE);
            gtk_widget_set_vexpand(button, TRUE);
            gtk_widget_set_halign(button, GTK_ALIGN_FILL);
            gtk_widget_set_valign(button, GTK_ALIGN_FILL);
        }
    }

    
    // Set the expand property of the grid
    gtk_widget_set_hexpand(grid, TRUE);
    gtk_widget_set_vexpand(grid, TRUE);

    // Show the main window and start the main event loop
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
