#include "filew.h"

int main(int argc, char** argv)
{
	gtk_init(&argc, &argv);
	GtkWidget* win    = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget* attack = gtk_button_new_with_label("               start attack!            ");
	GtkWidget* sel	  = gtk_button_new_with_label("selection file");
	GtkWidget* spin   = gtk_spin_button_new(((GtkAdjustment *) gtk_adjustment_new (10, 0, 10000000, 1, 5, 0)),0, 0);
	GtkWidget* fix    = gtk_fixed_new();

	//desine
        gtk_widget_set_usize(GTK_WIDGET(win), 400, 200);
        gtk_widget_set_usize(GTK_WIDGET(sel), 180, 30);
        gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
	gtk_window_set_resizable(GTK_WINDOW(win), FALSE);

        GdkColor btns;
        GdkColor back;

        gdk_color_parse("#0a0a0a", &back);
        gdk_color_parse("#050505", &btns);

        gtk_widget_modify_bg(GTK_WIDGET(win), GTK_STATE_NORMAL, &back);
        gtk_widget_modify_bg(GTK_WIDGET(sel), GTK_STATE_NORMAL, &btns);
        gtk_widget_modify_bg(GTK_WIDGET(attack), GTK_STATE_NORMAL, &btns);

	//...
	gtk_fixed_put(GTK_FIXED(fix), sel, 20,     50);
        gtk_fixed_put(GTK_FIXED(fix), spin, 240   ,50);
        gtk_fixed_put(GTK_FIXED(fix), attack, 110, 130);

	//signal
	g_signal_connect(win,   "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(sel,   "clicked"     , G_CALLBACK(selectionFile), NULL);
        g_signal_connect(attack,"clicked"     , G_CALLBACK(ATTACK), (GtkWidget*)spin);


	//...

	gtk_container_add(GTK_CONTAINER(win), fix);
	gtk_widget_show_all(win);
	gtk_main();
	return 0;
}
