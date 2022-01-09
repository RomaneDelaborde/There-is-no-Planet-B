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
		//~Bouton();
};


class BoutonCarte: public Gtk::Button {
	public:
		BoutonCarte(Image& image);
		void zoom_Image();

	private:
		std::string name_tiny_image;
		std::string name_big_image;
		//Image tiny_image;
};

class BoutonAccueil: public Gtk::Button {
	public:
		BoutonAccueil(Image& image);
		
};
