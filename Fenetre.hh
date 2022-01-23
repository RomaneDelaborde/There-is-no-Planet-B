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
#include <gtkmm/separator.h>
#include <tuple>
#include <string>
#include <iostream>
#include "Widgets.hh"

//fonction venant de stackoverflow
bool is_number(const std::string& s);

//Fenetre pour l'ecran d'accueil et l'affichage des regles : Fenetre avec Image (dans un BoutonCarte), passe à la suite du programme quand le joueur clique sur l'image
class FenetreAccueil : public Gtk::Window {
	
	public:
		FenetreAccueil(const std::string image) : Gtk::Window(), image_bouton(image), bouton(image_bouton) {set_title("There is no Planet B"); set_position(Gtk::WIN_POS_CENTER); bouton.signal_clicked().connect(sigc::mem_fun(*this, &FenetreAccueil::hide)); add(bouton); show_all();};
	
	private:
		Image image_bouton;
		BoutonAccueil bouton;
};

//Pour inclusion circulaire
class Jeu;


//Fenetre du Jeu : lance le Jeu + gere l'interaction Joueur-Jeu et les affichages
class FenetreJeu : public Gtk::Window {
		
	//Contructeur et Initialisation
	public:
		FenetreJeu();
	
	private:

		//Methodes d'initialisation en prive car appelees une seule fois par le constructeur
	
		//Initialisation du vecteur de Cartes (toutes les cartes du Jeu, affichees sur le tableau du milieu)
		void init_allBoutonCartes();
	
		//Initialisation du vecteur d'Objets (toutes les Objets de l'inventaire du Jeu, affichees sur le tableau du bas)
		void init_allBoutonObjets();
	
		void init_table_zones_texte();
		void init_table_images();
		void init_table_inventory();

	//Méthodes
	public:
	
		std::string get_entry_objet_1() const {return entry_objet_1.get_text();}
		std::string get_entry_objet_2() const {return entry_objet_2.get_text();}
		std::string get_entry_id_enigme() const {return entry_id_enigme.get_text();}
		std::string get_entry_reponse_enigme_l() const {return entry_reponse_enigme_l.get_text();}
		std::string get_entry_carte_num() const {return entry_carte_num.get_text();}
	
		Jeu* get_Game() {return Game;};
	
		//Fenetre A Propos, pop-up quand on clique sur l'icone correspondante
		void afficherApropos();
	
		//Fenetre Regles, pop-up quand on clique sur l'icone correspondante
		void afficherRegles();
	
		void popupMessage(const std::string message, const std::string title);
		void remplacerCartetoWhite(BoutonCarte & bouton);
		void remplacerWhitetoCarte(BoutonCarte & bouton);
		void remplacerWhitetoObjet(BoutonCarte & bouton);
		void requestCarte();
		void requestRepondreEnigme();
		void requestCombinaison();

		BoutonCarte* boutonCarteFromName(const std::string name);
		BoutonCarte* boutonObjetFromName(const std::string name);

		//Renvoyer les coordonnees de la 1ere case blanche disponible
		std::pair<int, int> getFirstWhiteCarte() const;
	
		//Renvoyer les coordonnees de la 1ere case blanche de l'inventaire disponible
		std::pair<int, int> getFirstWhiteInventory() const;
	
		~FenetreJeu();
	
	private:

		Jeu* Game;

		std::vector<BoutonCarte*> allBoutonCartes;
		std::vector<BoutonCarte*> allBoutonObjets;

		BoutonTexte* bouton_combinaisons; BoutonTexte* bouton_enigme; BoutonTexte* bouton_carte;
		BoutonAccueil* bouton_about; BoutonAccueil* bouton_rules;
		
		Gtk::Table* table_big;
		Gtk::Table* table_zones_texte; //tableau du haut, pour les zones de texte et d'entrée utilisateur
		Gtk::Table* table_images; //tableau du milieu, pour les images en taille petite
		Gtk::Table* table_inventory;
		
		//DECLARER TOOOOOOOOUS LES WIDGETS QUI SERONT AFFICHES SUR LA FENETRE PRINCIPALE AU COURS DU JEU
		//Même si 2 widgets utilisent la même image, il faut déclarer 2 Gtk::Image avec 2 noms différents
		Image white_0101; Image white_1201; Image white_2301; Image white_3401; Image white_0112;
		Image white_1212; Image white_2312; Image white_3412;
		Image inventory1; Image inventory2; Image inventory3; Image inventory4; Image inventory5;
		Image inventory6; Image inventory7; Image inventory8;
		Image about_image; Image rules;
		Image annonce_radio; Image bibliotheque; Image boite_chocolat; Image boite_gants; Image boite_outils;
		Image boss_assomme; Image boss_enerve; Image boss_mort; Image bureau; Image certificat; Image coffre_fort;
		Image dessin_mur; Image dessin_recto; Image dessin_sol; Image dessin_verso; Image dialogue_patron;
		Image frequences; Image garage; Image non_revelation; Image planetes; Image porte_cachee; Image pressing;
		Image radio; Image retroviseur; Image revelation; Image table_chevet; Image ticket_dore;
		Image tiroir; Image voiture; Image zoom_livres;
		Image boss_o; Image certificat_o; Image cesar; Image epingle_cheveux; Image morceau1; Image morceau2;
		Image pied_biche; Image porte_cachee_o; Image porte_electronique; Image revolver; Image ticket_dore_o;

		BoutonCarte bouton_0101; BoutonCarte bouton_1201; BoutonCarte bouton_2301; BoutonCarte bouton_3401;
		BoutonCarte bouton_0112; BoutonCarte bouton_1212; BoutonCarte bouton_2312; BoutonCarte bouton_3412;
		BoutonCarte bouton_inventory1; BoutonCarte bouton_inventory2; BoutonCarte bouton_inventory3;
		BoutonCarte bouton_inventory4; BoutonCarte bouton_inventory5; BoutonCarte bouton_inventory6;
		BoutonCarte bouton_inventory7; BoutonCarte bouton_inventory8;
		BoutonCarte bouton_annonce_radio; BoutonCarte bouton_bibliotheque; BoutonCarte bouton_boite_chocolat;
		BoutonCarte bouton_boite_gants; BoutonCarte bouton_boite_outils; BoutonCarte bouton_boss_assomme;
		BoutonCarte bouton_boss_enerve; BoutonCarte bouton_boss_mort; BoutonCarte bouton_bureau;
		BoutonCarte bouton_certificat; BoutonCarte bouton_coffre_fort; BoutonCarte bouton_dessin_mur;
		BoutonCarte bouton_dessin_recto; BoutonCarte bouton_dessin_sol; BoutonCarte bouton_dessin_verso;
		BoutonCarte bouton_dialogue_patron; BoutonCarte bouton_frequences; BoutonCarte bouton_garage;
		BoutonCarte bouton_non_revelation; BoutonCarte bouton_planetes; BoutonCarte bouton_porte_cachee;
		BoutonCarte bouton_pressing; BoutonCarte bouton_radio; BoutonCarte bouton_retroviseur;
		BoutonCarte bouton_revelation; BoutonCarte bouton_table_chevet; BoutonCarte bouton_ticket_dore;
		BoutonCarte bouton_tiroir; BoutonCarte bouton_voiture; BoutonCarte bouton_zoom_livres;
		BoutonCarte bouton_boss_o; BoutonCarte bouton_certificat_o; BoutonCarte bouton_cesar;
		BoutonCarte bouton_epingle_cheveux; BoutonCarte bouton_morceau1; BoutonCarte bouton_morceau2;
		BoutonCarte bouton_pied_biche; BoutonCarte bouton_porte_cachee_o; BoutonCarte bouton_porte_electronique;
		BoutonCarte bouton_revolver; BoutonCarte bouton_ticket_dore_o;
	
		Gtk::Label combinaisons; Gtk::Label reponse_enigme; Gtk::Label tirer_carte_1; Gtk::Label tirer_carte_2;
		Gtk::Label objet_1; Gtk::Label objet_2; Gtk::Label id_enigme; Gtk::Label reponse_enigme_l; Gtk::Label carte_num;
	
		Gtk::Entry entry_objet_1; Gtk::Entry entry_objet_2; Gtk::Entry entry_id_enigme; Gtk::Entry entry_reponse_enigme_l;
		Gtk::Entry entry_carte_num;
	
		Gtk::Separator separator1; Gtk::Separator separator2; Gtk::Separator separator3;
};
