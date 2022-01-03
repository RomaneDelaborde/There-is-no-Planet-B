//
//  Fenetre.cpp
//  
//
//  Created by Maëlle Jolivet on 29/12/2021.
//

#include "Fenetre.hh"

bool Fenetre::gastonChange = false;

Fenetre::Fenetre() : about_image("about.png"), white_0101("white.jpeg"), white_1201("white.jpeg"), white_2301("white.jpeg"), white_3401("white.jpeg"), white_0112("white.jpeg"), white_1212("white.jpeg"), white_2312("white.jpeg"), white_3412("white.jpeg"), gaston("gaston.jpeg"), combinaisons("Saisir une combinaison d'objets (au moins 2)"), reponse_enigme("Saisir la réponse à une énigme"), tirer_carte_1("Saisir le numéro de la carte à tirer"), tirer_carte_2("(si vous en avez le droit)"), objet_1("objet n°1"), objet_2("objet n°2"), id_enigme("n° énigme"), reponse_enigme_l("réponse"), carte_num("n° carte"), bouton_2301(white_2301) { //à l'initialisation
	
	set_title("There is no Planet B");
	set_border_width(10);
	set_position(Gtk::WIN_POS_CENTER);
	
	table_big = new Gtk::Table(3, 1);
	add(*table_big);
	
	init_table_zones_texte();
	
	//Initialisation du tableau d'images : déclaration de 8 images "white.jpeg"
	table_images = new Gtk::Table(2, 4);
	table_big->attach(*table_images, 0, 1, 1, 2);

	table_images->attach(white_0101, 0, 1, 0, 1);
	//table_images->attach(white_1201, 1, 2, 0, 1);
	
	bouton_1201 = new Bouton(white_1201);
	table_images->attach(*bouton_1201, 1, 2, 0, 1);
	bouton_1201->signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::afficherErreur));
	
	
	//table_images->attach(white_2301, 2, 3, 0, 1);
	
	table_images->attach(bouton_2301, 2, 3, 0, 1);
	//bouton_2301.signal_clicked().connect(sigc::bind<Bouton*>(sigc::mem_fun(*this, &Fenetre::zoom_Image), &bouton_2301));
	
	
	table_images->attach(white_3401, 3, 4, 0, 1);
	table_images->attach(white_0112, 0, 1, 1, 2);
	table_images->attach(white_1212, 1, 2, 1, 2);
	table_images->attach(white_2312, 2, 3, 1, 2);
	table_images->attach(white_3412, 3, 4, 1, 2);
	

	
	
	
	
	superbouton = new Bouton("Super bouton");
	table_zones_texte->attach(*superbouton, 0, 2, 4, 5);
	superbouton->signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::changerWhitetoGaston));
	
	show_all();
}

void Fenetre::init_table_zones_texte() {
	table_zones_texte = new Gtk::Table(5, 8);
	table_big->attach(*table_zones_texte, 0, 1, 0, 1);
	
	table_zones_texte->attach(combinaisons, 0, 2, 0, 1);
	table_zones_texte->attach(objet_1, 0, 1, 1, 2);
	table_zones_texte->attach(entry_objet_1, 1, 2, 1, 2);
	table_zones_texte->attach(objet_2, 0, 1, 2, 3);
	table_zones_texte->attach(entry_objet_2, 1, 2, 2, 3);
	table_zones_texte->attach(reponse_enigme, 2, 4, 0, 1);
	table_zones_texte->attach(id_enigme, 2, 3, 1, 2);
	table_zones_texte->attach(entry_id_enigme, 3, 4, 1, 2);
	table_zones_texte->attach(reponse_enigme_l, 2, 3, 2, 3);
	table_zones_texte->attach(entry_reponse_enigme_l, 3, 4, 2, 3);
	table_zones_texte->attach(tirer_carte_1, 4, 6, 0, 1);
	table_zones_texte->attach(tirer_carte_2, 4, 6, 1, 2);
	table_zones_texte->attach(carte_num, 4, 5, 2, 3);
	table_zones_texte->attach(entry_carte_num, 5, 6, 2, 3);
	
	bouton_about = new Bouton(about_image);
	table_zones_texte->attach(*bouton_about, 6, 8, 0, 2);
	bouton_about->signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::afficherApropos));
}


void Fenetre::afficherErreur() {
	Gtk::MessageDialog dialogue(*this, "Erreur : vous ne pouvez pas tirer cette carte", false, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_NONE);
	dialogue.set_title("Avertissement");
	//dialogue.set_secondary_text("Et <i>ceci</i> est le texte secondaire qui explique quelque chose.", true); //Ajouter un texte secondaire.
	dialogue.run();
}

//Fenêtre A Propos, pop-up quand on clique sur l'icône correspondante
void Fenetre::afficherApropos() {
	//reste à ajouter le logo avec dialogue.set_logo(Gdk::Pixbuf::create_from_file("name.png"));
	Gtk::AboutDialog dialogue;
	dialogue.set_program_name("There is no planet B");
	dialogue.set_version("1.0");
	dialogue.set_copyright("2022");
	dialogue.set_comments("Petit Escape Game codé pour le cours de C++");
	std::vector<Glib::ustring> listeAuteurs;
	listeAuteurs.push_back("Mario");
	listeAuteurs.push_back("Romano");
	dialogue.set_authors(listeAuteurs);
	dialogue.set_position(Gtk::WIN_POS_CENTER);
	dialogue.run();
}


void Fenetre::changerWhitetoGaston() {
	if (gastonChange == false) {
		table_images->remove(white_0101);
		table_images->attach(gaston, 0, 1, 0, 1);
		show_all();
		gastonChange = true;
	}
	else {
		table_images->remove(gaston);
		table_images->attach(white_0101, 0, 1, 0, 1);
		show_all();
		gastonChange = false;
	}
}

Fenetre::~Fenetre() {
	delete superbouton;
	delete bouton_about;
	delete bouton_1201;
	delete table_zones_texte;
	delete table_images;
	delete table_big;
}


Bouton::Bouton(Image& image) : Gtk::Button() {
	set_image(image);
	set_relief(Gtk::RELIEF_NONE);
	set_can_focus(false);
	tiny_image = image;
}

/*
 
 
void Fenetre::afficherEntree() {
	 texte = entree->get_text();
	 std::cout << texte << std::endl;
 }

void Bouton::zoom_Image() {
	Gtk::Window fenetre_temp;
	fenetre_temp.set_title("Zoom sur l'image");
	fenetre_temp.add();
	fenetre_temp.set_position(Gtk::WIN_POS_CENTER);
	fenetre_temp.show_all();
}


void Fenetre::zoom_Image(std::string name) {
	Gtk::Window fenetre_temp;
	fenetre_temp.set_title("Zoom sur l'image");
	fenetre_temp.add(getImagefromName(name));
	fenetre_temp.set_position(Gtk::WIN_POS_CENTER);
	fenetre_temp.show_all();
}*/

Image& Image::operator=(const Image& image) {
	name = image.name;
	return *this;
}
