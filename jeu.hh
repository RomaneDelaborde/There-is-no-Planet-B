#pragma once

#include <iostream>
#include <vector>
#include <map>


class Jeu{

private:

  std::vector<Carte> _cartes_jeu; // liste des cartes du jeu
  std::map<int, bool> _id_cartes; //map des id des cartes du jeu : bool pour dire si elles sont affichées à l'écran ou non
  // ou alors faire un ensemble/liste(*) avec les cartes et le dico _carte_jeu contient des id en clés pour faciliter les choses et après on regarde les attributs dont on a besoin en parcourant chaque élément de (*)

public:

  // Constructeur
  Jeu(Carte carte_regles); // ou alors ne rien mettre dedans

  // Destructeur
  ~Jeu(){};

  // Méthodes (des getter vont peut-être être nécessaires pour accéder à certains attributs privés)
  Carte carte_id(int id_carte);
  /*
  {
    if(id_carte n'est pas dans les clés de _id_cartes)
    {
      alors id_carte n'existe pas, on affiche un message d'erreur et on exit en amont
    }
    for(int i=0; i< _cartes_jeu.size(); i++)
    {
      if(_cartes_jeu[i]._id==id_carte)
      {
        return _cartes_jeu[i];
      }
    }

  }
  */

  void changement_valeur_carte_dico(int id_carte, bool dispo); // ou faire 2 fonctions explicites : dispo et pas_dispo (dispo pour disponible)
  // ajout carte dans les cartes affichées
  // retrait carte
  // màj valeurs clés de chaque map des cartes contenues dans _cartes_affichees
  // affichage des cartes ? -> voir tous les bails graphiques à faire : ça serait bien affichage carte en fonction de l'id

  //bool affichage_carte_autorise(); // indique si la carte peut-être affichée ou non

  // charger les dicos de chaque carte à partir du ou des fichiers csv -> peut-être il va falloir faire un switch si on a plusieurs csv
  // méthode pour taper les codes : s'ils sont valides alors on débloque des cartes

};
