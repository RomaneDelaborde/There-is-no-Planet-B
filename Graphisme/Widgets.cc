//
//  Widgets.cpp
//  
//
//  Created by Maëlle Jolivet on 08/01/2022.
// 

#include "Widgets.hh"

Bouton::Bouton(Image& image) : Gtk::Button() {
	set_image(image);
	set_relief(Gtk::RELIEF_NONE);
	set_can_focus(false);
	tiny_image = image;
}

/*
void Bouton::zoom_Image() {
	Gtk::Window fenetre_temp;
	fenetre_temp.set_title("Zoom sur l'image");
	fenetre_temp.add();
	fenetre_temp.set_position(Gtk::WIN_POS_CENTER);
	fenetre_temp.show_all();
}
*/

Image& Image::operator=(const Image& image) {
	name = image.name;
	return *this;
}
 
