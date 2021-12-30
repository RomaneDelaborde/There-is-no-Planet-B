//
//  Fenetre.hpp
//  
//
//  Created by Maëlle Jolivet on 29/12/2021.
//

#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/table.h>
#include <gtkmm/entry.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/aboutdialog.h>
#include <string>
#include <iostream>



class Fenetre : public Gtk::Window {
	public :
		Fenetre();
		void augmenterTaille(int augmentationLargeur, int augmentationHauteur);
		void afficherErreur();
		void afficherApropos();
		void afficherEntree();
		~Fenetre(); //Le destructeur pour pouvoir détruire le bouton.
	
	private :
		//Gtk::Button bouton; //Déclaration du bouton.
		Gtk::Button* bouton; //Création du pointeur sur bouton.
		Gtk::Table* table;
		Gtk::Entry* entree;
		std::string texte;
	
};

#endif
