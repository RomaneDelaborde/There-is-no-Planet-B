//
//  Widgets.hpp
//  
//
//  Created by Maëlle Jolivet on 08/01/2022.
//

#pragma once

#include <gtkmm/image.h>
#include <gtkmm/button.h>
#include <string>
#include <iostream>

class Image: public Gtk::Image {
		
	public:
		Image(const std::string & file) : Gtk::Image(file) {name = file;}
		Image() : Gtk::Image() {}
		Image& operator=(const Image& image);
		
	private:
		std::string name;
	
};


class Bouton: public Gtk::Button {
		
	public:
		Bouton() : Gtk::Button() {}
		Bouton(const Glib::ustring& label, bool mnemonic=false) : Gtk::Button (label, false) {set_can_focus(false);}
		Bouton(Image& image);
		//void zoom_Image();
		//~Bouton();

	private:
		std::string name;
		Image tiny_image;
		
};
