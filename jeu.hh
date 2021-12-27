#pragma once

#include <iostream>
#include <set>
#include <map>


class Jeu{

private:

  std::map<Carte> _cartes_jeu; // ensemble des cartes du jeu : bool pour dire si elles sont affichées à l'écran ou non

public:

  // Constructeur
  Jeu(Carte carte_regles); // ou alors ne rien mettre dedans

  // Destructeur
  ~Jeu(){};

  // Méthodes
  // ajout carte dans les cartes affichées
  // retrait carte
  // màj valeurs clés de chaque map des cartes contenues dans _cartes_affichees
  // affichage des cartes ? -> voir tous les bails graphiques à faire

  // charger les dicos de chaque carte à partir du ou des fichiers csv -> peut-être il va falloir faire un switch si on a plusieurs csv
  // méthode pour taper les codes : s'ils sont valides alors on débloque des cartes

};
