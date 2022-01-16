//
//  Widgets.cpp
//  
//
//  Created by Maëlle Jolivet on 08/01/2022.
// 

#include "Widgets.hh"

std::string split_name_image(std::string name) {
	std::string result = name.substr(0, name.find('.'));
	return result;
}

BoutonCarte::BoutonCarte(Image& image) : Gtk::Button() {
	set_image(image);
	set_relief(Gtk::RELIEF_NONE);
	set_can_focus(false);
	//tiny_image = image;
	name_tiny_image = image.get_name(); //"gaston.jpg"
	//ne pas zoomer sur les images blanches
	if (name_tiny_image != "Images/white.jpg" && name_tiny_image != "Images/white_inventory.jpg") {
		name_big_image = split_name_image(name_tiny_image) + "_big.jpg";
		signal_clicked().connect(sigc::mem_fun(*this, &BoutonCarte::zoom_Image));
	}
}

BoutonAccueil::BoutonAccueil(Image& image) : Gtk::Button() {
	set_image(image);
	set_relief(Gtk::RELIEF_NONE);
	set_can_focus(false);
}



void BoutonCarte::zoom_Image() {
	//ne pas zoomer sur les images blanches
	if (name_tiny_image != "Images/white.jpg" && name_tiny_image != "Images/white_inventory.jpg") {
		Gtk::Window fenetre_temp;
		fenetre_temp.set_title("Zoom sur l'image");
		Image big(name_big_image);
		fenetre_temp.add(big);
		fenetre_temp.set_position(Gtk::WIN_POS_CENTER);
		fenetre_temp.show_all();
		Gtk::Main::run(fenetre_temp);
	}
}


Image& Image::operator=(const Image& image) {
	name = image.name;
	return *this;
}
 
