#include <iostream>
#include <string>

#include "jeu.hh"
#include "carte.hh"
#include "objet.hh"
#include "enigme.hh"
#include "enigme1.hh"
#include "enigme2.hh"
#include "enigme3.hh"

#include <gtkmm/main.h>
#include "Fenetre.hh"
#include "Widgets.hh"


int main(int argc, char* argv[]) {
 
	//Lancer une application Gtk
	Gtk::Main app(argc, argv);
	
	//Afficher la fenetre d'accueil
	FenetreImage accueil("Images/galaxy.jpg");
	Gtk::Main::run(accueil);
	 
	//Afficher les regles
	FenetreImage regles("Images/regles.jpeg");
	Gtk::Main::run(regles);
	
	//Lancer le Jeu, en boucle infinie jusqu'a fermeture manuelle de la fenetre ou fin du jeu
	FenetreJeu fenetre;
	Gtk::Main::run(fenetre);
		
  return 0;
}

