#pragma once

# include <iostream>
# include <map>
# include <math.h>
#include "enigme.hh"


class Enigme3 : public Enigme{ // énigme avec le tableau et le coffre-fort

private:
  std::map<char,int> _lettres; // ce type d'attribut est commun à Enigme2
  std::string _chaine;         // ce type d'attribut est commun à Enigme2
// chaine = ensemble de mots séparés par des + ou des -

public:

  // Constructeur
  Enigme3(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int id_carte_debloquee, std::string chaine); // ajouter kick et carte débloquée

  // Destructeur : bail virtuel ?? ou alors hérite direct de celui de la classe mère ??

  // Getter
  //std::map<char,int> get_lettres() const {return _lettres};
  std::string get_chaine() const {return _chaine;};


  // Méthodes
  bool lettre_existe(char l) const; // OU bool lettre_existe(const char l) const; ??

  int codage_mot_planete(std::string mot);
  void codage_chaine_planete();

};
