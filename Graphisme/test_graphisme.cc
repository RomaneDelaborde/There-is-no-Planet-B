//
//  test.cc
//  
//
//  Created by Maëlle Jolivet on 26/12/2021.
//

// compilation :
// g++ test_graphisme.cc -o test_graphisme -std=c++0x `pkg-config gtkmm-3.0 --cflags --libs`

#include <stdio.h>
#include <iostream>

#include <gtkmm/button.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/table.h>
#include <gtkmm/image.h>
#include <gtkmm/eventbox.h>

void yes() {
	std::cout << "Bonjour" << std::endl;
}

int main(int argc, char* argv[]) {
	Gtk::Main app(argc, argv);
	Gtk::Window fenetre;
	fenetre.maximize();
	//fenetre.resize(640, 480);
	fenetre.set_border_width(10); //Ajouter une bordure (invisible) de 10px à la fenêtre.
	fenetre.set_position(Gtk::WIN_POS_CENTER); //positionner la fenetre au centre de l'ecran
	fenetre.set_title("Essai");
	
	//Gtk::Button bouton("Clique-moi !"); //Création d'un bouton.
	//fenetre.add(bouton); //Ajout du bouton à la fenêtre.
	
	//bouton.show(); //Afficher le bouton.
	//bouton.set_can_focus(false); //Empêcher le bouton d'avoir le focus.
	
	//bouton.signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit)); //Connexion du signal clicked() à la fonction Gtk::Main::quit() qui ferme le programme.
	
	//bouton.signal_clicked().connect([]() { Gtk::Main::quit(); });
	
	Gtk::Table tableau(4, 4, false);
	fenetre.add(tableau);

	//tableau.resize(2, 2);

	//tableau.attach(bouton, 0, 1, 0, 1);
	
	//Gtk::Button bouton2("Bouton 2");
	//bouton2.set_can_focus(false);
	//tableau.attach(bouton2, 1, 2, 0, 1); //Le widget prend l'espace qui lui est alloué et tout autre espace additionnel.

	//Gtk::Button bouton3("Bouton 3");
	//bouton3.set_can_focus(false);
	//tableau.attach(bouton3, 0, 2, 1, 2, Gtk::FILL, Gtk::FILL, 25, 10); //Le widget prend l'espace qui lui est alloué. Ajout d'espace (25px horizontal et 10px vertical) autour du widget.

	Gtk::EventBox boite;
	
	Gtk::Image image("gaston.jpeg"); //Création d'une image à partir d'un fichier.
	Gtk::Image image2("garage.jpeg"); //Création d'une image à partir d'un fichier.
	Gtk::Image image3("gaston.jpeg"); //Création d'une image à partir d'un fichier.
	Gtk::Image image4("garage.jpeg"); //Création d'une image à partir d'un fichier.
	
	Gtk::Image image5("gaston.jpeg"); //Création d'une image à partir d'un fichier.
	Gtk::Image image6("garage.jpeg"); //Création d'une image à partir d'un fichier.
	Gtk::Image image7("gaston.jpeg"); //Création d'une image à partir d'un fichier.
	Gtk::Image image8("garage.jpeg"); //Création d'une image à partir d'un fichier.
	
	Gtk::Image image9("right.jpeg"); //Création d'une image à partir d'un fichier.
	Gtk::Image image10("left.jpeg"); //Création d'une image à partir d'un fichier.
			  

	tableau.attach(image, 0, 1, 2, 3);
	tableau.attach(image2, 1, 2, 2, 3);
	tableau.attach(image3, 2, 3, 2, 3);
	tableau.attach(image4, 3, 4, 2, 3);
	
	//tableau.attach(image5, 0, 1, 1, 2);
	tableau.attach(boite, 0, 1, 1, 2);
	boite.add(image5);
	
	boite.set_events(Gdk::BUTTON_PRESS_MASK);
	//boite.signal_button_press_event().connect(sigc::ptr_fun(&yes));
	boite.show_all();
	tableau.attach(image6, 1, 2, 1, 2);
	tableau.attach(image7, 2, 3, 1, 2);
	tableau.attach(image8, 3, 4, 1, 2);

	tableau.attach(image9, 0, 2, 0, 1);
	tableau.attach(image10, 2, 4, 0, 1);

	
	fenetre.show_all(); //L'habituel show_all() pour afficher tous les widgets.
	
	Gtk::Window fenetre2;
	Gtk::Image image11("gaston.jpeg"); //Création d'une image à partir d'un fichier.
	fenetre2.add(image11);
	fenetre2.set_position(Gtk::WIN_POS_CENTER); //positionner la fenetre au centre de l'ecran
	fenetre2.show_all();
	
	Gtk::Main::run(fenetre);
	return 0;
}

