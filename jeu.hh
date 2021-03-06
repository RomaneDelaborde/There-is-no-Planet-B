#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>

#include "carte.hh"
#include "objet.hh"
#include "enigme.hh"
#include "enigme1.hh"
#include "enigme2.hh"
#include "enigme3.hh"


#include "Fenetre.hh"

#define fichier_cartes_basiques "cartes_basiques.csv"
#define fichier_cartes_objets "cartes_objets.csv"

class Jeu {

	private:
	  std::vector<Carte> _cartes_jeu;
	  std::vector<Carte> _cartes_basiques;
	  std::vector<Objet> _cartes_objets;
	  std::vector<Enigme> _cartes_enigmes;
	
	  // map des id des cartes du jeu : valeur de la clé = int pour donner une indication sur leur affichage : 1 = carte affichée, 0 = carte pas encore affichée et -1 = carte pas affichable (car déjà affichée avant ou correspond à un autre choix que celui fait par le joueur (exemple biche et gun))
      // toutes les valeurs de _map_id sont initialisées à 0 sauf la carte règles qui vaut 1
	  std::map<int, int> _map_id;

	  std::vector<int> _inventaire;

	  // future amelioration : std::vector<Carte, int> _cartes_jeu; avec valeur 0 si carte est basique, valeur 1 si carte est objet et valeur 2 si carte est énigme, mais il faudrait tout changer dans jeu.cc pour _cartes_jeu
	  std::vector<int> _id_cartes_basiques;
	  std::vector<int> _id_cartes_objets;
	  std::vector<int> _id_cartes_enigmes;

	  FenetreJeu & _fenetre;


	public:

	  // Constructeur sans paramètres
	  Jeu(FenetreJeu &fenetre);

	  // Destructeur vide
	  //~Jeu() {};

	  // Getters
	  std::vector<Carte> get_cartes_jeu() const {return _cartes_jeu;};
	  std::vector<Carte> get_cartes_basiques() const {return _cartes_basiques;};
	  std::vector<Objet> get_cartes_objets() const {return _cartes_objets;};
	  std::vector<Enigme> get_cartes_enigmes() const {return _cartes_enigmes;};
	  std::map<int, int> get_map_id() const {return _map_id;};
	  std::vector<int> get_inventaire() const {return _inventaire;};
	  std::vector<int> get_id_cartes_basiques() const {return _id_cartes_basiques;};
	  std::vector<int> get_id_cartes_objets() const {return _id_cartes_objets;};
	  std::vector<int> get_id_cartes_enigmes() const {return _id_cartes_enigmes;};


	  // Méthodes
	
	  // lecture d'un str composé d'int séparés par des "-" (tabulats) : int retournés sous forme d'un vecteur
	  std::vector<int> lecture_str_tab(std::string chaine);
	
	  // lecture des infos sur les cartes basiques (ni objet ni énigme) depuis un csv
	  void lecture_csv_carte_basique(std::string nom_fichier);
	
	  // lecture des infos sur les cartes objets  depuis un csv
	  void lecture_csv_carte_objet(std::string nom_fichier);
	  
	  // pas de lecture des cartes enigmes depuis un csv car il y en a que 3 : fait à la main dans le constructeur de la classe Jeu

	  // à partir d'une valeur d'id (unique) d'une carte basique, renvoie sa carte correspondante si celle-ci existe
	  Carte carte(const int id_carte) const;
	  // à partir d'une valeur d'id (unique) d'une carte objet, renvoie sa carte correspondante si celle-ci existe
	  Objet objet(const int id_carte) const;
	  // à partir d'une valeur d'id (unique) d'une carte enigme, renvoie sa carte correspondante si celle-ci existe
	  Enigme enigme(const int id_carte) const;

	  // renvoie 1 si l'id est dans _map_id et 0 sinon (i.e. s'il existe)
	  bool id_existe(const int id_carte) const;

	  bool affichage_carte_autorise(const int id_carte);

	  // permet l'affichage d'une carte ainsi que les modifications qui en découlent
	  void affichage_carte(const int id_carte);

	  // demande de l'affichage d'une carte par le joueur
	  void demande_affichage_carte(const int id_carte);

	  // modifications en adéquation
	  void solution_enigme_valide(int id_carte_enigme, int val);

	  // modifications en adéquation)
	  void combinaison_valide(int id_obj_1, int id_obj_2);

};
