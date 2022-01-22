#pragma once

# include <iostream>
# include <map>
# include <math.h>
#include "enigme.hh"


class Enigme3 : public Enigme { // énigme avec le tableau et le coffre-fort

private:
  std::map<char,int> _lettres; // ensemble des lettres codables en clés et leurs valeurs associées en valeurs du map
  std::string _chaine;         // _chaine est l'ensemble de mots séparés par des + ou des - à coder


public:

  // Constructeur
  Enigme3(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int code_solution, int id_carte_debloquee):Enigme(nom_carte, id, id_cartes_kick, nb_essais, code_solution, id_carte_debloquee){};
  Enigme3(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int id_carte_debloquee, std::string chaine);

  // Destructeur : bail virtuel ?? ou alors hérite direct de celui de la classe mère ??

  // Getter
  std::string get_chaine() const {return _chaine;};

  // Méthodes
  bool lettre_existe(char l) const; // renvoie 1 si la lettre l existe dans _lettres et 0 sinon
  // OU bool lettre_existe(const char l) const; ??

  int codage_mot_planete(std::string mot); // permet de coder un mot avec les valeurs données dans _lettres
  void codage_chaine_planete();           // permet de sommer/soustraire les codes des mots de _chaine en fonction des + et - présents

};
