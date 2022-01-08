//
//  main.cc
//  
//
//  Created by Maëlle Jolivet on 29/12/2021.
//
// g++ main.cc Fenetre.cc Widgets.cc -o graphisme -std=c++0x `pkg-config gtkmm-3.0 --cflags --libs`


#include <gtkmm/main.h>
#include "Fenetre.hh"
#include "Widgets.hh"


int main(int argc, char* argv[]) {
	//std::vector<Image> images;
	
	Gtk::Main app(argc, argv);
	FenetreAccueil accueil;
	Gtk::Main::run(accueil);
	FenetreJeu fenetre;
	Gtk::Main::run(fenetre);

	return 0;
}
