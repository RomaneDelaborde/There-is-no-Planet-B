#pragma once

#include <iostream>
#include <set>
#include <map>


class Jeu{

private:

  std::map<Carte> _cartes_jeu; // ensemble des cartes du jeu : bool pour dire si elles sont affichées à l'écran ou non
  // ou alors faire un ensemble/liste(*) avec les cartes et le dico _carte_jeu contient des id en clés pour faciliter les choses et après on regarde les attributs dont on a besoin en parcourant chaque élément de (*)

public:

  // Constructeur
  Jeu(Carte carte_regles); // ou alors ne rien mettre dedans

  // Destructeur
  ~Jeu(){};

  // Méthodes
  void changement_valeur_carte_dico(int id_carte, bool dispo); // ou faire 2 fonctions explicites : dispo et pas_dispo (dispo pour disponible)
  // ajout carte dans les cartes affichées
  // retrait carte
  // màj valeurs clés de chaque map des cartes contenues dans _cartes_affichees
  // affichage des cartes ? -> voir tous les bails graphiques à faire

  //bool affichage_carte_autorise(); // indique si la carte peut-être affichée ou non

  // charger les dicos de chaque carte à partir du ou des fichiers csv -> peut-être il va falloir faire un switch si on a plusieurs csv
  // méthode pour taper les codes : s'ils sont valides alors on débloque des cartes

};
