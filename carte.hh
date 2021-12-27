#pragma once

#include <iostream>
#include <string>
#include <list>
#include <map>

class Carte{

private:

  // peut-être à mettre en privé idk
  std::string _nom_carte;  // nom de l'image associée à la carte (au format XX)

protected:

  static int _cpt;        // compteur static
  int _id;                // id propre à chaque carte


  map<int, bool> _cartes_anterieures;  // dictionnaire des cartes permettant d’afficher cette carte : bool pour préciser si la carte est disponible ou pas dans le jeu
  map<int, bool> _cartes_posterieures; // dictionnaire des cartes suivantes à afficher : bool pour dire si on peut les afficher ou non (spécifique aux cartes énigmes -> si on peut mettre dans la classe énigme comment faire ??)
  map<int, bool> _cartes_kick;         // dictionnaire des cartes permettant de kicker la carte de l'affichage du jeu (i.e. on en a plus besoin) : bool pour dire si la carte est affichée à l'écran ou non

  set<int> _codes_objets; // ensemble des codes des objets présents sur la carte (en rouge et blanc)

public:

  // Constructeur
  Carte(std::string nom_carte): _nom_carte(nom_carte){};

  // Destructeur
  ~Carte();






};
