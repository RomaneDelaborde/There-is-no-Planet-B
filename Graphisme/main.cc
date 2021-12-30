//
//  main.cc
//  
//
//  Created by Maëlle Jolivet on 29/12/2021.
//
// g++ main.cc Fenetre.cc -o graphisme -std=c++0x `pkg-config gtkmm-3.0 --cflags --libs`

// brain dump : mettre des tableaux dans un tableau..
// un tableau en haut pour les zones de textes à entrer (demande bcp de colonnes / lignes car etiquettes + zones d'entree etc
// sur ce même tableau à droite, icones d'aide etc
// un tableau au milieu pour les max 8 images
// peut-être un tableau en bas pour l'inventaire

#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/messagedialog.h>

#include "Fenetre.hh"

int main(int argc, char* argv[]) {
	Gtk::Main app(argc, argv);
	Fenetre fenetre;
	Gtk::Main::run(fenetre);
	return 0;
}
