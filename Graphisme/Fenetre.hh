//
//  Fenetre.hpp
//  
//
//  Created by Maëlle Jolivet on 29/12/2021.
//

#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <gtkmm/main.h>
#include <gtkmm/image.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/table.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/aboutdialog.h>
#include <gtkmm/eventbox.h>
#include <string>
#include <iostream>

class Image: public Gtk::Image {
	
public:
	Image(const std::string & file) : Gtk::Image(file) {name = file;}
	Image() : Gtk::Image() {}
	Image& operator=(const Image& image);
	
private:
	std::string name;
	
};


class Bouton: public Gtk::Button {
	
public:
	//Utiles
	Bouton() : Gtk::Button() {}
	Bouton(const Glib::ustring& label, bool mnemonic=false) : Gtk::Button (label, false) {set_can_focus(false);}
	Bouton(Image& image);
	//void zoom_Image();
	//~Bouton();

private:
	std::string name;
	Image tiny_image;
	
};


class Fenetre: public Gtk::Window {
		
	public:
		static bool gastonChange;

		//Utiles
		Fenetre();
		void init_table_zones_texte();
		void init_table_images();
		void afficherApropos();
		~Fenetre();
	
		//Expérimentations
		void afficherErreur();
		//void afficherEntree();
		void changerWhitetoGaston();
		//Image& getImagefromName(std::string name);
		//void zoom_Image(Bouton& bouton);
	
	private:
		//Expérimentations
		Bouton* superbouton; //Création du pointeur sur bouton.
	
		Bouton* bouton_about;
		
		//Utiles
		Gtk::Table* table_big; //Grand tableau
		Gtk::Table* table_zones_texte; //tableau du haut, pour les zones de texte et d'entrée utilisateur
		Gtk::Table* table_images; //tableau du milieu, pour les images en taille petite
		
		//DECLARER TOOOOOOOOUTES LES IMAGES DONT ON AURA BESOIN
		//Même si 2 widgets utilisent la même image, il faut déclarer 2 Gtk::Image avec 2 noms différents
		//Ici on déclare les images "white", qui servent à remplir les cases du tableau quand les cases n'ont pas de cartes
		//Si au cours du jeu une carte est détruite, on la remplace par l'image white aux mêmes coordonnées
		Image white_0101; // nom image + coordonnées initiales dans le tab d'images
		Image white_1201;
		Image white_2301;
		Image white_3401;
		Image white_0112;
		Image white_1212;
		Image white_2312;
		Image white_3412;
	
		Bouton bouton_0101;
		Bouton bouton_1201;
		Bouton bouton_2301;
		Bouton bouton_3401;
		Bouton bouton_0112;
		Bouton bouton_1212;
		Bouton bouton_2312;
		Bouton bouton_3412;
	
		Image about_image;
		Image gaston;
	
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
