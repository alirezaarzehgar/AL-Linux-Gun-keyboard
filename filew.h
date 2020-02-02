#include <gtk/gtk.h>

volatile char selected[1024];

#ifndef FILEW_H_H
#define FILEW_H_H

void init(GtkWidget* w, GtkFileSelection *fs);
void selectionFile(GtkWidget* w);
void ATTACK(GtkWidget* w, GtkSpinButton* spin);

#endif /* filew.h */
