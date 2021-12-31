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
#include <gtkmm/label.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/aboutdialog.h>
#include <string>
#include <iostream>


class Fenetre : public Gtk::Window {
		
	public :
		static bool gastonChange;

		//Utiles
		Fenetre();
		void afficherApropos();
		~Fenetre();
	
		//Expérimentations
		void augmenterTaille(int augmentationLargeur, int augmentationHauteur);
		void afficherErreur();
		void afficherEntree();
		void changerWhitetoGaston();
	
	private :
		//Expérimentations
		Gtk::Button* bouton; //Création du pointeur sur bouton.
	
		//Utiles
		Gtk::Table* table_big; //Grand tableau
		Gtk::Table* table_zones_texte; //tableau du haut, pour les zones de texte et d'entrée utilisateur
		Gtk::Table* table_images; //tableau du milieu, pour les images en taille petite
		Gtk::Entry* entree;
		std::string texte;
	
		//DECLARER TOOOOOOOOUTES LES IMAGES DONT ON AURA BESOIN
		//Même si 2 widgets utilisent la même image, il faut déclarer 2 Gtk::Image avec 2 noms différents
		//Ici on déclare les images "white", qui servent à remplir les cases du tableau quand les cases n'ont pas de cartes
		//Si au cours du jeu une carte est détruite, on la remplace par l'image white aux mêmes coordonnées
		Gtk::Image white_0101; // nom image + coordonnées initiales dans le tab d'images
		Gtk::Image white_1201;
		Gtk::Image white_2301;
		Gtk::Image white_3401;
		Gtk::Image white_0112;
		Gtk::Image white_1212;
		Gtk::Image white_2312;
		Gtk::Image white_3412;
	
		Gtk::Image gaston;
	
		Gtk::Label combinaisons;
		Gtk::Label reponse_enigme;
		Gtk::Label tirer_carte_1;
		Gtk::Label tirer_carte_2;
	
		Gtk::Label objet_1;
		Gtk::Label objet_2;
		Gtk::Label id_enigme;
		Gtk::Label reponse_enigme_l;
		Gtk::Label carte_num;
	
		Gtk::Entry entry_objet_1;
		Gtk::Entry entry_objet_2;
		Gtk::Entry entry_id_enigme;
		Gtk::Entry entry_reponse_enigme_l;
		Gtk::Entry entry_carte_num;


};

#endif
