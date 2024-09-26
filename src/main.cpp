#include <gtk/gtk.h>
#include "py_interface.h"

GtkWidget *txt_output;
GtkWidget *ent;
GtkTextBuffer *txt_buffer;
GtkWidget *sbtn;

static void on_btn_clicked(GtkWidget *widget, gpointer data) {
	const char* raw_password = gtk_entry_get_text(GTK_ENTRY(ent));

	int password_size = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(sbtn));
	char* password = gen_password(raw_password, password_size);
	
	gtk_text_buffer_set_text(txt_buffer, password, -1);
	gtk_text_view_set_buffer(GTK_TEXT_VIEW(txt_output), txt_buffer);
}

int main(int argc, char* argv[]) {
	GtkBuilder *builder;
	GtkWidget *main_window;
	GtkWidget *btn;
	GtkWidget *lbl_const_1;
	GtkWidget *lbl_const_2;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "../res/interface.glade", NULL);

	main_window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
	g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	lbl_const_1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_const_1"));

	lbl_const_2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_const_2"));

	txt_buffer = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "txt_buffer")); 

	txt_output = GTK_WIDGET(gtk_builder_get_object(builder, "txt_output"));

	btn = GTK_WIDGET(gtk_builder_get_object(builder, "btn"));
	g_signal_connect(btn, "clicked", G_CALLBACK(on_btn_clicked), NULL);

	ent = GTK_WIDGET(gtk_builder_get_object(builder, "ent"));

	sbtn = GTK_WIDGET(gtk_builder_get_object(builder, "sbtn"));

	gtk_widget_show(main_window);
	gtk_main();
	
	return 0;
}
