#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "carte.hh"
#include "objet.hh"
#include "enigme.hh"
// #include "inventaire.hh"


class Jeu{

private:

  std::vector<Carte> _cartes_jeu; // liste des cartes du jeu
  std::map<int, int> _map_id; //map des id des cartes du jeu : int pour donner une indication sur leur affichage : 1 = carte affichée, 0 = carte pas encore affichée et -1 = carte affichée dans le passé et pas réaffichable
  // toutes les valeurs de _map_id sont initialisées à 0 sauf la carte règles qui vaut 1

public:

  // Constructeur sans paramètres pour l'instant : quels paramètres à mettre dedans sinon ?
  Jeu();

  // Destructeur (vide normalement)
  ~Jeu(){};

  // Méthodes (des getter vont peut-être être nécessaires dans d'autres classes pour accéder à certains attributs privés)

  bool id_existe(const int id_carte) const; // renvoie 1 si l'id est dans _map_id (si id existe alors carte correspondante existe aussi normalement)
  Carte carte(const int id_carte) const; // à partir d'une valeur d'id d'une carte (unique), renvoit sa carte correspondante si celle-ci existe

  void carte_map_affichage(const int id_carte); // dans _map_id la valeur de la clé correspondant à id_carte passe à la valeur 1
  void carte_map_desaffichage(const int id_carte); // dans _map_id la valeur de la clé correspondant à id_carte passe à la valeur -1

  bool affichage_carte_autorise(const int id_carte) const; // indique si la carte peut-être affichée ou non
  void demande_affichage_carte(const int id_carte) const; // demande de l'affichage d'une carte par le joueur



  // màj valeurs clés de chaque map des cartes contenues dans _cartes_affichees
  // affichage des cartes ? -> voir tous les bails graphiques à faire : ça serait bien affichage carte en fonction de l'id

  // méthodes pour taper les codes : s'ils sont valides alors on débloque des cartes

};
