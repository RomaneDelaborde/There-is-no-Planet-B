#include "Widgets.hh"

//name est de format : "Images/image.png" => ne garder que "image"
std::string split_name_image(std::string name) {
	std::string result = name.substr(0, name.find('.'));
	result.erase(0, result.find('/') + 1);
	return result;
}   

BoutonCarte::BoutonCarte(Image& image, int c, int l) : Bouton(image), column_coordinate(c), line_coordinate(l) {
	set_relief(Gtk::RELIEF_NONE);
	name_tiny_image = split_name_image(image.get_name()); //"gaston"
	//ne pas zoomer sur les images blanches
	if (name_tiny_image != "white" && name_tiny_image != "white_inventory") {
		name_big_image = "Images/" + name_tiny_image + "_big.jpg";
		signal_clicked().connect(sigc::mem_fun(*this, &BoutonCarte::zoom_Image));
	}
}

//Methode qui peut etre reliee a un Bouton, affiche l'image en 700*700 dans une nouvelle fenetre
void BoutonCarte::zoom_Image() const {
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
 
 
