#pragma once

#include <iostream>
#include <set>


class PlateauJeu{

private:

  std::set<Carte> _cartes_affichees; // ensemble des cartes affichées à l'écran

public:

  // Constructeur
  PlateauJeu(Carte carte_regles); // ou alors ne rien mettre dedans comme la carte des règles est connue et tjrs la 1ère

  // Destructeur
  ~PlateauJeu(){};

  // Méthodes
  // ajout carte dans les cartes affichées
  // retrait carte
  // màj valeurs clés de chaque map des cartes contenues dans _cartes_affichees
  // affichage des cartes ? -> voir tous les bails graphiques à faire
};
