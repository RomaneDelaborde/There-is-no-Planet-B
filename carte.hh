#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>

class Carte{

protected:

	// ajouter attribut Gtk::Image .... pour l'interface graphique

  std::string _nom_carte;  // nom de l'image associée à la carte (rajouter +".jpeg" par exemple pour le format)
  int _id;                 // id=identifiant propre à chaque carte (déterminé manuellement voir tableau drive)

  std::vector<int> _id_cartes_suivantes; // liste des id des cartes suivantes à afficher (ne contient pas les cartes secrètes déblocables par une énigme ou une combinaison d'objets)
  std::vector<int> _id_cartes_kick;      // liste des id des cartes permettant de kicker la carte de l'affichage du jeu (quand elle n'est plus utile)


public:

  // Constructeurs
  Carte(std::string nom_carte, int id): _nom_carte(nom_carte), _id(id){}; // constructeur utile à la classe fille Objet
  Carte(std::string nom_carte, int id, std::vector<int> id_cartes_posterieures, std::vector<int> id_cartes_kick): _nom_carte(nom_carte), _id(id), _id_cartes_suivantes(id_cartes_posterieures), _id_cartes_kick(id_cartes_kick){};
  Carte(std::string nom_carte, int id, std::vector<int> id_cartes_kick): _nom_carte(nom_carte), _id(id), _id_cartes_kick(id_cartes_kick){}; // certaines carte peuvent ne pas avoir de cartes suivantes mais toutes les cartes ont au moins une carte kick

  // Destructeur
  ~Carte(){}; // vide

  // Getters
  std::string get_nom_carte() const {return _nom_carte;};
  int get_id() const {return _id;};
  std::vector<int> get_id_cartes_suivantes() const {return _id_cartes_suivantes;};
  std::vector<int> get_id_cartes_kick() const {return _id_cartes_kick;};

  // Méthodes
  void affichage_info_carte() const; // permet l'affichage des informations d'une carte basique (i.e. une carte qui ne se débloque ni par résolution d'énigme ni par combinaison de 2 objets)


  // En lien avec l'interface graphique (à mettre ici ou dans une autre classe ?):
  // méthode pour afficher la carte
  // méthode pour retirer la carte

  // méthode pour zoomer sur la carte (faire peut-être appel à une imgae de meilleure qualité : dans ce cas rajouter un attribut std::string _nom_carte_zoomee qui correpond au nom de l'image ayant une qualité supérieure)

};
