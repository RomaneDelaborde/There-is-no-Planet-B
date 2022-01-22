//
//  Fenetre.hh
//  
//
//  Created by Maëlle Jolivet on 29/12/2021.
//

#pragma once

#include <gtkmm/main.h>
#include <gtkmm/overlay.h>
#include <gtkmm/image.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/table.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/aboutdialog.h>
#include <string>
#include <iostream>
#include "Widgets.hh"

#include <tuple>

bool is_number(const std::string& s);

class Jeu;


class FenetreAccueil: public Gtk::Window {
	
	public:
		FenetreAccueil();
	
	private:
		Image galaxy;
		BoutonAccueil bouton_galaxy;
};



class FenetreJeu: public Gtk::Window {
		
	public:
		static bool retroviseurChange;

		FenetreJeu();
	
		void afficherApropos();

	
		std::string get_entry_objet_1() {return entry_objet_1.get_text();}
		std::string get_entry_objet_2() {return entry_objet_2.get_text();}
		std::string get_entry_id_enigme() {return entry_id_enigme.get_text();}
		std::string get_entry_reponse_enigme_l() {return entry_reponse_enigme_l.get_text();}
		std::string get_entry_carte_num() {return entry_carte_num.get_text();}

		~FenetreJeu();
	
		void popupMessage(const std::string message, const std::string title);
		void changerWhitetoRetroviseur();
		void remplacerCartetoWhite(BoutonCarte & bouton);
		void remplacerWhitetoCarte(BoutonCarte & bouton);
		void requestCarte();
		void requestRepondreEnigme();
		void requestCombinaison();

		BoutonCarte* boutonFromName(const std::string name);

		std::tuple<int, int> getFirstWhiteCarte();

	
	private:

		//passer les init en privé ?
		void init_table_zones_texte();
		void init_table_images();
		void init_table_inventory();
		void init_allBoutonCartes();

		Jeu* Game;

		std::vector<BoutonCarte*> allBoutonCartes;

		BoutonTexte* superbouton;
		BoutonTexte* bouton_combinaisons;
		BoutonTexte* bouton_enigme;
		BoutonTexte* bouton_carte;

		BoutonAccueil* bouton_about;
		
		Gtk::Table* table_big; //Grand tableau
		Gtk::Table* table_zones_texte; //tableau du haut, pour les zones de texte et d'entrée utilisateur
		Gtk::Table* table_images; //tableau du milieu, pour les images en taille petite
		Gtk::Table* table_inventory;
		
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
	
		Image inventory1;
		Image inventory2;
		Image inventory3;
		Image inventory4;
		Image inventory5;
		Image inventory6;
		Image inventory7;
 
		Image about_image;
	
		Image annonce_radio;
		Image bibliotheque;
		Image boite_chocolat;
		Image boite_gants;
		Image boite_outils;
		Image boss_assomme;
		Image boss_enerve;
		Image boss_mort;
		Image bureau;
		Image certificat;
		Image coffre_fort;
		Image dessin_mur;
		Image dessin_recto;
		Image dessin_sol;
		Image dessin_verso;
		Image dialogue_patron;
		Image frequences;
		Image garage;
		Image non_revelation;
		Image planetes;
		Image porte_cachee;
		Image pressing;
		Image radio;
		Image retroviseur;
		Image revelation;
		Image table_chevet;
		Image ticket_dore;
		Image tiroir;
		Image voiture;
		Image zoom_livres;

		BoutonCarte bouton_0101;
		BoutonCarte bouton_1201;
		BoutonCarte bouton_2301;
		BoutonCarte bouton_3401;
		BoutonCarte bouton_0112;
		BoutonCarte bouton_1212;
		BoutonCarte bouton_2312;
		BoutonCarte bouton_3412;
	
		BoutonCarte bouton_inventory1;
		BoutonCarte bouton_inventory2;
		BoutonCarte bouton_inventory3;
		BoutonCarte bouton_inventory4;
		BoutonCarte bouton_inventory5;
		BoutonCarte bouton_inventory6;
		BoutonCarte bouton_inventory7;
	
		BoutonCarte bouton_annonce_radio;
		BoutonCarte bouton_bibliotheque;
		BoutonCarte bouton_boite_chocolat;
		BoutonCarte bouton_boite_gants;
		BoutonCarte bouton_boite_outils;
		BoutonCarte bouton_boss_assomme;
		BoutonCarte bouton_boss_enerve;
		BoutonCarte bouton_boss_mort;
		BoutonCarte bouton_bureau;
		BoutonCarte bouton_certificat;
		BoutonCarte bouton_coffre_fort;
		BoutonCarte bouton_dessin_mur;
		BoutonCarte bouton_dessin_recto;
		BoutonCarte bouton_dessin_sol;
		BoutonCarte bouton_dessin_verso;
		BoutonCarte bouton_dialogue_patron;
		BoutonCarte bouton_frequences;
		BoutonCarte bouton_garage;
		BoutonCarte bouton_non_revelation;
		BoutonCarte bouton_planetes;
		BoutonCarte bouton_porte_cachee;
		BoutonCarte bouton_pressing;
		BoutonCarte bouton_radio;
		BoutonCarte bouton_retroviseur;
		BoutonCarte bouton_revelation;
		BoutonCarte bouton_table_chevet;
		BoutonCarte bouton_ticket_dore;
		BoutonCarte bouton_tiroir;
		BoutonCarte bouton_voiture;
		BoutonCarte bouton_zoom_livres;
	
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
