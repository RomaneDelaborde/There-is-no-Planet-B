//
//  Widgets.cpp
//  
// 
//  Created by Maëlle Jolivet on 08/01/2022.
//  
   
#include "Widgets.hh"

std::string split_name_image(std::string name) {
	std::string result = name.substr(0, name.find('.'));
	result.erase(0, result.find('/') + 1);
	return result;
}

BoutonCarte::BoutonCarte(Image& image, int c, int l) : Gtk::Button(), column_coordinate(c), line_coordinate(l) {
	set_image(image);
	set_relief(Gtk::RELIEF_NONE);
	set_can_focus(false);

	name_tiny_image = split_name_image(image.get_name()); //"gaston"
	std::cout << name_tiny_image << std::endl;
	//ne pas zoomer sur les images blanches
	if (name_tiny_image != "white" && name_tiny_image != "white_inventory") {
		name_big_image = "Images/" + name_tiny_image + "_big.jpg";
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
	if (name_tiny_image != "white" && name_tiny_image != "white_inventory") {
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
	name = split_name_image(image.name);
	return *this;
}
 
