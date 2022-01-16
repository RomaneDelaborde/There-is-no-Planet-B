//
//  Fenetre.cpp
//  
//
//  Created by Maëlle Jolivet on 29/12/2021.
//

#include "Fenetre.hh"
#include "jeu.hh"


bool FenetreJeu::retroviseurChange = false;

//fonction venant de stackoverflow
bool is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}


FenetreAccueil::FenetreAccueil() : galaxy("Images/galaxy.jpg"), bouton_galaxy(galaxy) {
	set_title("There is no Planet B");
	set_position(Gtk::WIN_POS_CENTER);
	
	bouton_galaxy.signal_clicked().connect(sigc::mem_fun(*this, &FenetreAccueil::hide));

	add(bouton_galaxy);
	
	show_all();
}

 
FenetreJeu::FenetreJeu() : 
white_0101("Images/white.jpg"), white_1201("Images/white.jpg"), white_2301("Images/white.jpg"), 
white_3401("Images/white.jpg"), white_0112("Images/white.jpg"), white_1212("Images/white.jpg"), 
white_2312("Images/white.jpg"), white_3412("Images/white.jpg"), 
inventory1("Images/white_inventory.jpg"), inventory2("Images/white_inventory.jpg"), 
inventory3("Images/white_inventory.jpg"), inventory4("Images/white_inventory.jpg"), 
inventory5("Images/white_inventory.jpg"), inventory6("Images/white_inventory.jpg"), 
inventory7("Images/white_inventory.jpg"), about_image("Images/about.png"), 
retroviseur("Images/retroviseur.jpg"),
bouton_0101(white_0101), bouton_1201(white_1201), bouton_2301(white_2301), 
bouton_3401(white_3401), bouton_0112(white_0112), bouton_1212(white_1212), 
bouton_2312(white_2312), bouton_3412(white_3412), bouton_inventory1(inventory1), 
bouton_inventory2(inventory2), bouton_inventory3(inventory3), 
bouton_inventory4(inventory4), bouton_inventory5(inventory5), 
bouton_inventory6(inventory6), bouton_inventory7(inventory7), 
bouton_retroviseur(retroviseur), 
combinaisons("Saisir une combinaison d'objets (au moins 2)"), 
reponse_enigme("Saisir la réponse à une énigme"), 
tirer_carte_1("Saisir le numéro de la carte à tirer"), 
tirer_carte_2("(si vous en avez le droit)"), 
objet_1("objet n°1"), objet_2("objet n°2"), id_enigme("n° énigme"), 
reponse_enigme_l("réponse"), carte_num("n° carte") { //à l'initialisation
	
	//commencer par un écran d'accueil....
 
	Game = new Jeu(*this);
	
	set_title("There is no Planet B");
	set_border_width(20);
	set_position(Gtk::WIN_POS_CENTER);
	
	table_big = new Gtk::Table(3, 1);
	add(*table_big);
	
	init_table_zones_texte();
	init_table_images();
	init_table_inventory();

	superbouton = new BoutonTexte("Super bouton");
	table_zones_texte->attach(*superbouton, 0, 2, 5, 6, Gtk::SHRINK);
	superbouton->signal_clicked().connect(sigc::mem_fun(*this, &FenetreJeu::changerWhitetoRetroviseur));
	
	show_all();
}

void FenetreJeu::init_table_zones_texte() {
	table_zones_texte = new Gtk::Table(6, 8);
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
	
	bouton_about = new BoutonAccueil(about_image);
	table_zones_texte->attach(*bouton_about, 6, 8, 0, 2, Gtk::SHRINK);
	bouton_about->signal_clicked().connect(sigc::mem_fun(*this, &FenetreJeu::afficherApropos));
	
	bouton_combinaisons = new BoutonTexte("Envoyer");
	table_zones_texte->attach(*bouton_combinaisons, 0, 1, 4, 5, Gtk::SHRINK);
	bouton_combinaisons->signal_clicked().connect(sigc::mem_fun(*this, &FenetreJeu::requestCombinaison));
	
	bouton_enigme = new BoutonTexte("Envoyer");
	table_zones_texte->attach(*bouton_enigme, 2, 3, 4, 5, Gtk::SHRINK);
	bouton_enigme->signal_clicked().connect(sigc::mem_fun(*this, &FenetreJeu::requestRepondreEnigme));
	
	bouton_carte = new BoutonTexte("Envoyer");
	table_zones_texte->attach(*bouton_carte, 4, 5, 4, 5, Gtk::SHRINK);
	bouton_carte->signal_clicked().connect(sigc::mem_fun(*this, &FenetreJeu::requestCarte));

}

void FenetreJeu::init_table_images() {
	//Initialisation du tableau d'images : déclaration de 8 images "white.jpeg"
	table_images = new Gtk::Table(2, 4);
	table_big->attach(*table_images, 0, 1, 1, 2);
	
	table_images->attach(bouton_0101, 0, 1, 0, 1);
	table_images->attach(bouton_1201, 1, 2, 0, 1);
	table_images->attach(bouton_2301, 2, 3, 0, 1);
	table_images->attach(bouton_3401, 3, 4, 0, 1);
	table_images->attach(bouton_0112, 0, 1, 1, 2);
	table_images->attach(bouton_1212, 1, 2, 1, 2);
	table_images->attach(bouton_2312, 2, 3, 1, 2);
	table_images->attach(bouton_3412, 3, 4, 1, 2);
	
	//bouton_2301.signal_clicked().connect(sigc::bind<Bouton*>(sigc::mem_fun(*this, &Fenetre::zoom_Image), &bouton_2301));
}

void FenetreJeu::init_table_inventory() {
	table_inventory = new Gtk::Table(2, 7);
	table_big->attach(*table_inventory, 0, 1, 2, 3);
	
	table_inventory->attach(bouton_inventory1, 0, 1, 1, 2);
	table_inventory->attach(bouton_inventory2, 1, 2, 1, 2);
	table_inventory->attach(bouton_inventory3, 2, 3, 1, 2);
	table_inventory->attach(bouton_inventory4, 3, 4, 1, 2);
	table_inventory->attach(bouton_inventory5, 4, 5, 1, 2);
	table_inventory->attach(bouton_inventory6, 5, 6, 1, 2);
	table_inventory->attach(bouton_inventory7, 6, 7, 1, 2);
}


/*void FenetreJeu::popupErreur() {
	Gtk::MessageDialog dialogue(*this, "Erreur : vous ne pouvez pas tirer cette carte", false, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_NONE);
	dialogue.set_title("Avertissement");
	//dialogue.set_secondary_text("Et <i>ceci</i> est le texte secondaire qui explique quelque chose.", true); //Ajouter un texte secondaire.
	dialogue.run();
}*/

void FenetreJeu::popupMessage(const std::string message, const std::string title) {
	Gtk::MessageDialog dialogue(*this, message, false, Gtk::MESSAGE_WARNING);//, Gtk::BUTTONS_NONE);
	dialogue.set_title(title);
	dialogue.run();
}

//Fenêtre A Propos, pop-up quand on clique sur l'icône correspondante
void FenetreJeu::afficherApropos() {
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


void FenetreJeu::changerWhitetoRetroviseur() {
	if (retroviseurChange == false) {
		table_images->remove(bouton_0101);
		table_images->attach(bouton_retroviseur, 0, 1, 0, 1);
		show_all();
		retroviseurChange = true;
	}
	else {
		//table_images->remove(bouton_retroviseur);
		//table_images->attach(bouton_0101, 0, 1, 0, 1);
		//attribut bouton => ses coordonnées..... les remplir à -1 si on connait pas
		//comment recup automatiquement les coordonnées ? a etudier
		remplacerCartetoWhite(bouton_retroviseur, 0, 0);
		show_all();
		retroviseurChange = false;
	}
}

void FenetreJeu::remplacerCartetoWhite(BoutonCarte & bouton, int colonne, int ligne) {
	table_images->remove(bouton);
	switch (colonne) {
		case 0:
			switch (ligne) {
				case 0:
					table_images->attach(bouton_0101, 0, 1, 0, 1);
					break;
				case 1:
					table_images->attach(bouton_0112, 0, 1, 1, 2);
					break;
			}
			break;
		case 1:
			switch (ligne) {
				case 0:
					table_images->attach(bouton_1201, 1, 2, 0, 1);
					break;
				case 1:
					table_images->attach(bouton_1212, 1, 2, 1, 2);
					break;
			}
			break;
		case 2:
			switch (ligne) {
				case 0:
					table_images->attach(bouton_2301, 2, 3, 0, 1);
					break;
				case 1:
					table_images->attach(bouton_2312, 2, 3, 1, 2);
					break;
			}
			break;
		case 3:
			switch (ligne) {
				case 0:
					table_images->attach(bouton_3401, 3, 4, 0, 1);
					break;
				case 1:
					table_images->attach(bouton_3412, 3, 4, 1, 2);
					break;
			}
			break;
	}

}

FenetreJeu::~FenetreJeu() {
	delete superbouton;
	delete bouton_about;
	delete bouton_combinaisons;
	delete bouton_enigme;
	delete bouton_carte;
	delete table_zones_texte;
	delete table_images;
	delete table_big;
	delete Game;
}

/*
void Fenetre::zoom_Image(std::string name) {
	Gtk::Window fenetre_temp;
	fenetre_temp.set_title("Zoom sur l'image");
	fenetre_temp.add(getImagefromName(name));
	fenetre_temp.set_position(Gtk::WIN_POS_CENTER);
	fenetre_temp.show_all();
}*/

void FenetreJeu::requestCarte() {

	if (is_number(entry_carte_num.get_text())) {
		//appeler fct qui demande a afficher une carte
		Game->demande_affichage_carte(std::stoi(entry_carte_num.get_text()));
		return;
	}
	else {
		popupMessage("Vous n'avez pas saisi un nombre entier", "Erreur");
	}
}


void FenetreJeu::requestRepondreEnigme() {
	
	if (is_number(entry_id_enigme.get_text())) {
		if (is_number(entry_reponse_enigme_l.get_text())) {
			Game->solution_enigme_valide(std::stoi(entry_id_enigme.get_text()), std::stoi(entry_reponse_enigme_l.get_text()));
			return;
		}
		else {
			popupMessage("Vous n'avez pas saisi un nombre entier pour la réponse", "Erreur");

		}
	}
	else {
		popupMessage("Vous n'avez pas saisi un nombre entier pour l'énigme", "Erreur");
	}
}


void FenetreJeu::requestCombinaison() {
	
	if (is_number(entry_objet_1.get_text())) {
		if (is_number(entry_objet_2.get_text())) {
			Game->combinaison_valide(std::stoi(entry_objet_1.get_text()), std::stoi(entry_objet_2.get_text()));
			return;
		}
		else {
			popupMessage("Vous n'avez pas saisi un nombre entier pour l'objet 2", "Erreur");

		}
	}
	else {
		popupMessage("Vous n'avez pas saisi un nombre entier pour l'objet 1", "Erreur");
	}
}


