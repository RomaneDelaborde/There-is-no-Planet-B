//
//  Fenetre.cpp
//  
//
//  Created by Maëlle Jolivet on 29/12/2021.
//

#include "Fenetre.hh" 

Fenetre::Fenetre() {
	//Modification de la fenêtre.
	set_title("Ma fenêtre héritée !");
	set_border_width(10);
	set_position(Gtk::WIN_POS_CENTER);
	
	table = new Gtk::Table(4, 4);
	add(*table);
	
	//si attribut bouton
	//bouton.show(); //Ne pas oublier l'affichage du bouton.
	//bouton.set_can_focus(false); //Nous pouvons aussi modifier le bouton.
	//add(bouton); //Ajouter le bouton à la fenêtre.
	
	//si attribut pointeur sur bouton
	bouton = new Gtk::Button("Super bouton");
	//bouton->show();
	bouton->set_can_focus(false);
	//bouton->signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
	//bouton->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(this, &Fenetre::set_title), "Titre de la fenêtre"));
	//Lorsque l'utilisateur cliquera sur le bouton, le titre de la fenêtre changera.
	//Si nous voulons envoyer plusieurs paramètres, il suffit de les séparer par des virgules aux deux endroits (entre les chevrons et après le nom de la fonction de rappel).
	
	//on connecte à notre fonction de rappel
	//bouton->signal_clicked().connect(sigc::bind<int, int>(sigc::mem_fun(*this, &Fenetre::augmenterTaille), 130, 140));
	//bouton->signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::afficherErreur));
	//bouton->signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::afficherApropos));
	bouton->signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::afficherEntree));

	table->attach(*bouton, 0, 1, 3, 4);
	
	
	entree = new Gtk::Entry;
	entree->signal_activate().connect(sigc::mem_fun(*this, &Fenetre::afficherEntree)); //quand l'utilisateur appuie sur la touche entrée, la fonction afficherEntree est appelée
	table->attach(*entree, 1, 2, 0, 1);
	
	
	show_all();
}

//Il est impossible de surcharger une fonction de rappel
void Fenetre::augmenterTaille(int augmentationLargeur, int augmentationHauteur) {
	int largeur(0);
	int hauteur(0);
	get_size(largeur, hauteur);
	resize(largeur + augmentationLargeur, hauteur + augmentationHauteur);
}


void Fenetre::afficherErreur() {
	Gtk::MessageDialog dialogue(*this, "Erreur : vous ne pouvez pas tirer cette carte", false, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_NONE);
		//Comme cette classe hérite de Gtk::Window, il est possible d'appeler des méthodes de cette dernière classe.
	dialogue.set_title("Avertissement");
		//Ajouter un texte secondaire.
		//dialogue.set_secondary_text("Et <i>ceci</i> est le texte secondaire qui explique quelque chose.", true);
	dialogue.run(); //Lancer la boîte de dialogue.
}

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

void Fenetre::afficherEntree() {
	texte = entree->get_text();
	std::cout << texte << std::endl;
}

Fenetre::~Fenetre() {
	delete bouton;
	delete table;
	delete entree;
}

