#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>

class Carte{

private:
  std::string _nom_carte;  // nom de l'image associée à la carte (au format XX)

protected:

  int _id;                // id=identifiant propre à chaque carte (déterminé par nous à la main)


  //std::vector<int> _id_cartes_anterieures;  // liste des id des cartes permettant d’afficher cette carte --> vraiment utile ?
  std::vector<int> _id_cartes_posterieures; // liste des id des cartes suivantes à afficher
  //std::vector<int> _id_cartes_posterieures_secretes; // liste des id des cartes suivantes à afficher qui sont déblocables seulement par combinaison/énigme
  std::vector<int> _id_cartes_kick;         // liste des id des cartes permettant de kicker la carte de l'affichage du jeu (i.e. on en a plus besoin)


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

  // Ajout getter et setter

};
