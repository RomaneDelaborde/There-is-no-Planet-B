//
//  Widgets.hh
//  
//
//  Created by Maëlle Jolivet on 08/01/2022.
//

#pragma once

#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/button.h>
#include <string>
#include <iostream>

std::string split_name_image(std::string name);

class Image: public Gtk::Image {
		
	public:
		Image(const std::string & file) : Gtk::Image(file) {name = file;}
		Image() : Gtk::Image() {}
		Image& operator=(const Image& image);
		std::string get_name() {return name;}
		
	private:
		std::string name;
	
};

class BoutonTexte: public Gtk::Button {
		
	public:
		BoutonTexte(const Glib::ustring& label, bool mnemonic=false) : Gtk::Button (label, false) {set_can_focus(false);}
};


class BoutonCarte: public Gtk::Button {
	public:
		BoutonCarte(Image& image, int c = -1, int l = -1);
		void zoom_Image();
		std::string get_name_tiny_image() {return name_tiny_image;};
		int get_column() {return column_coordinate;};
		int get_line() {return line_coordinate;};
		void set_column(int col) {column_coordinate = col;};
		void set_line(int line) {line_coordinate = line;};

		bool operator== (std::string name) {return name_tiny_image == name;};

	private:
		std::string name_tiny_image;
		std::string name_big_image;
		int column_coordinate;
		int line_coordinate;
};

class BoutonAccueil: public Gtk::Button {
	public:
		BoutonAccueil(Image& image);
		
};
