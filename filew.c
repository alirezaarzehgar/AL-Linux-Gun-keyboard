#include "filew.h"

void init(GtkWidget* w, GtkFileSelection *fs)
{
	sprintf (selected, "%s", gtk_file_selection_get_filename (GTK_FILE_SELECTION (fs)));
}

void selectionFile(GtkWidget* w)
{
	GtkWidget* filew = gtk_file_selection_new("please select a file");

        g_signal_connect (filew , "destroy", G_CALLBACK (gtk_widget_destroy), NULL);

        g_signal_connect (GTK_FILE_SELECTION (filew)->ok_button, "clicked", G_CALLBACK (init), (gpointer) filew);
        g_signal_connect_swapped (GTK_FILE_SELECTION (filew)->ok_button, "clicked", G_CALLBACK (gtk_widget_destroy), G_OBJECT (filew));

        g_signal_connect_swapped (GTK_FILE_SELECTION (filew)->cancel_button, "clicked", G_CALLBACK (gtk_widget_destroy), G_OBJECT (filew));

        gtk_file_selection_set_filename (GTK_FILE_SELECTION(filew), "please select a file");

        gtk_widget_show (filew);
}

void ATTACK(GtkWidget* w, GtkSpinButton* spin)
{
	char command[1024];
	sprintf(command, "python3 key-Entered.py %s %d 500 600", selected, gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin)));
	system(command);
}
