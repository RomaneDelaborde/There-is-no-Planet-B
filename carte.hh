#pragma once

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <set>

class Carte{

private:
  std::string _nom_carte;  // nom de l'image associée à la carte (au format XX)

protected:

  int _id;                // id propre à chaque carte (déterminé par nous à la main)


  std::set<int, bool> _cartes_anterieures;  // ensemble des cartes permettant d’afficher cette carte
  std::set<int, bool> _cartes_posterieures; // ensemble des cartes suivantes à afficher
  std::set<int, bool> _cartes_kick;         // ensemble des cartes permettant de kicker la carte de l'affichage du jeu (i.e. on en a plus besoin)


public:

  // Constructeur
  Carte(std::string nom_carte, int id): _nom_carte(nom_carte), _id(id){};

  // Destructeur
  ~Carte(){}; // vide car pas de mémoire associée à un pointeur à libérer pour le moment

  // Méthodes

  // getter de _nom_carte
  // ajout élément dictionnaire (obligé de faire 3 fonctions pour les 3 dictionnaires ??)
  // modifier clé d'un élément
  // mettre toutes les clés d'un dictionnaire à 0 ou 1 -> à voir peut-être pas nécessaire


  // En lien avec l'interface graphique :
  // méthode pour afficher la carte
  // méthode pour zoomer sur la carte
  // méthode pour retirer la carte


};
