#pragma once

#include <iostream>
#include "enigme.hh"


class Enigme1 : public Enigme{ // énigme avec la radio et les fréquences

private:
  int _alpha;
  int _beta;
  int _gamma;
  int _val1;
  int _val2;
  int _val3;


public:
  // Constructeurs
  Enigme1(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int code_solution, int id_carte_debloquee):Enigme(nom_carte, id, id_cartes_kick, nb_essais, code_solution, id_carte_debloquee){};
  Enigme1(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int id_carte_debloquee, int alpha, int beta, int gamma);

  // Méthodes

};
