#pragma once

# include <iostream>
# include <map>
# include <math.h>
#include "enigme.hh"


class Enigme3 : public Enigme{ // énigme avec le tableau et le coffre-fort

private:
  std::map<char,int> _lettres; // ce type d'attribut est commun à Enigme2
  std::string _chaine;         // ce type d'attribut est commun à Enigme2


public:

  // Constructeur
  Enigme3(std::string nom_carte, int id, int id_enigme, int nb_essais, std::string chaine);

  // Destructeur : bail virtuel ?? ou alors hérite direct de celui de la classe mère ??

  // Getter
  //std::map<char,int> get_lettres() const {return _lettres};
  std::string get_chaine() const {return _chaine};


  // Méthodes
  bool lettre_existe(char l) const; // OU bool lettre_existe(const char l) const; ??

  int codage_mot_planete(std::string mot) const;
  void codage_mots_planete() const; // chaine = mots

};
