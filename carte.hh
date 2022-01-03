#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>

class Carte{

protected:

	//attribut Gtk::Image ....
  std::string _nom_carte;  // nom de l'image associée à la carte (au format XX)
  int _id;    // id=identifiant propre à chaque carte (déterminé par nous à la main)

  std::vector<int> _id_cartes_suivantes; // liste des id des cartes suivantes à afficher (ne contient pas les cartes secrètes déblocables par une énigme ou une combinaison d'objets)
  //std::vector<int> _id_cartes_suivantes_secretes; // liste des id des cartes suivantes à afficher qui sont déblocables seulement par combinaison/énigme -> on devrait pas en avoir besoin car déblocables grâce aux énigmes et aux combinaisons (voir futures classes Enigme et Objet)
  std::vector<int> _id_cartes_kick;         // liste des id des cartes permettant de kicker la carte de l'affichage du jeu (i.e. on en a plus besoin)


public:

  // Constructeur
  Carte(std::string nom_carte, int id): _nom_carte(nom_carte), _id(id){}; // utile à la classe fille Objet
  Carte(std::string nom_carte, int id, std::vector<int> id_cartes_posterieures, std::vector<int> id_cartes_kick): _nom_carte(nom_carte), _id(id), _id_cartes_suivantes(id_cartes_posterieures), _id_cartes_kick(id_cartes_kick){};
  Carte(std::string nom_carte, int id, std::vector<int> id_cartes_kick): _nom_carte(nom_carte), _id(id), _id_cartes_kick(id_cartes_kick){}; // certaines carte peuvent ne pas avoir de cartes suivantes mais toutes les cartes ont au moins une carte kick


  // Destructeur
  ~Carte(){}; // vide car pas de mémoire associée à un pointeur à libérer pour le moment



  // Ajout getter et setter
  // Getter de _nom_carte
  std::string get_nom_carte() const {return _nom_carte;};
  // Getter de _id
  int get_id() const {return _id;};
  // Getter de _id_cartes_suivantes
  std::vector<int> get_id_cartes_suivantes() const {return _id_cartes_suivantes;};

  // Méthodes
  void affichage_info_carte() const;



  // En lien avec l'interface graphique (à mettre ici ou dans une autre classe ?):
  // méthode pour afficher la carte
  // méthode pour retirer la carte

  // méthode pour zoomer sur la carte (faire peut-être appel à une imgae de meilleure qualité : dans ce cas rajouter un attribut std::string _nom_carte_zoomee qui correpond au nom de l'image ayant une qualité supérieure)


};
