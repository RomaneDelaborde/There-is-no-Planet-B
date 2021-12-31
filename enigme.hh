#pragma once

#include <iostream>
#include "carte.hh"


class Enigme : public Carte{

private:
  // 1 énigme = 1 carte (où il faut "rentrer" le code) donc pas besoin de _id_enigme
  int _nb_essais; // nombre d'essais pour réussir l'énigme (peut être différente pour chaque énigme mais le préciser au joueur dans ce cas)

protected:
  int _code_solution; // code de la solution de l'énigme : code ou id d'objet (Charlie) -> à ne pas mettre dans le constructeur car calculé par des méthodes sauf pour Charlie : 2 constructeurs à faire

public:
  // Constructeurs
  Enigme(std::string nom_carte, int id, int nb_essais): Carte(nom_carte, id), _nb_essais(nb_essais){};
  Enigme(std::string nom_carte, int id, int nb_essais, int code_solution): Carte(nom_carte, id), _nb_essais(nb_essais), _code_solution(code_solution){}; // Constructeur pour Charlie

  // Destructeur : bail virtuel ?? ou alors hérite direct de celui de la classe mère ??

  // Getter
  int get_code_solution() const {return _code_solution;};
  int get_nb_essais() const {return _nb_essais;};

  // Méthodes
  // Méthodes virtuelles communes : calcul_code_solution ?

};
