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
// #include "inventaire.hh"


// define nom_string "blabla" --> de type std::string
#define fichier_cartes_basiques "cartes_basiques.csv"
#define fichier_cartes_objets "cartes_objets.csv"
// #define nom_csv_cartes_enigmes "cartes_enigmes.csv"

class Jeu{

private:
  std::vector<Carte> _cartes_jeu; // liste des cartes du jeu
  std::vector<Carte> _cartes_basiques; // liste des cartes basiques du jeu
  std::vector<Objet> _cartes_objets; // liste des cartes objets du jeu
  std::vector<Enigme> _cartes_enigmes; // liste des cartes enigmes du jeu
  std::map<int, int> _map_id; // map des id des cartes du jeu : int pour donner une indication sur leur affichage : 1 = carte affichée, 0 = carte pas encore affichée et -1 = carte affichée dans le passé et pas réaffichable
  // toutes les valeurs de _map_id sont initialisées à 0 sauf la carte règles qui vaut 1

public:

  // Constructeur sans paramètres pour l'instant : quels paramètres à mettre dedans sinon ?
  Jeu();

  // Destructeur (vide normalement -> non il faut détruire chaque carte du vecteur _cartes_jeu)
  ~Jeu(){};


  // Méthodes
  std::vector<int> lecture_str_tab(std::string chaine); // lecture d'un str composé d'int séparés par des "-" (tabulats) : ces int sont retournés sous forme de vecteur

  void lecture_csv_carte_basique(std::string nom_fichier); // lecture des infos sur les cartes basiques (ni objet ni énigme) depuis un csv
  void lecture_csv_carte_objet(std::string nom_fichier);
  //void lecture_csv_carte_enigme(std::string nom_fichier); --> inutile je pense comme il n'y a que 3 énigmes


  Carte carte(const int id_carte) const; // à partir d'une valeur d'id d'une carte (unique), renvoit sa carte correspondante si celle-ci existe
  Objet objet(const int id_carte) const;
  Enigme enigme(const int id_carte) const;

  bool id_existe(const int id_carte) const; // renvoie 1 si l'id est dans _map_id (si id existe alors carte correspondante existe aussi normalement)

  void carte_map_affichage(const int id_carte); // dans _map_id la valeur de la clé correspondant à id_carte passe à la valeur 1
  void carte_map_desaffichage(const int id_carte); // dans _map_id la valeur de la clé correspondant à id_carte passe à la valeur -1

  bool affichage_carte_autorise(const int id_carte); // indique si la carte peut-être affichée ou non
  void demande_affichage_carte(const int id_carte); // demande de l'affichage d'une carte par le joueur


  bool solution_enigme_valide(int id_carte_enigme, int val) const; // renvoie 1 si la réponse est bonne et 0 sinon (et modifications en adéquation)

  bool combinaison_realisable(int id_obj_1, int id_obj_2) const; // renvoie 1 si la combinaison est réalisable et 0 sinon (et modifications en adéquation)

  // màj valeurs clés de chaque map des cartes contenues dans _cartes_affichees
  // affichage des cartes ? -> voir tous les bails graphiques à faire : ça serait bien affichage carte en fonction de l'id

  // méthodes pour taper les codes : s'ils sont valides alors on débloque des cartes

};
