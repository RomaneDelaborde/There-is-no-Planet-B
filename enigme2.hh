#pragma once

#include <iostream>
#include <map>
#include "enigme.hh"


class Enigme2 : public Enigme{ // énigme avec le livre de Roald Dahl

private:
  std::map<char, int> _alphabet_indices; // map pour ne pas balayer l'alphabet à chaque fois qu'on cherche l'indice d'une lettre
  std::string _phrase;
  std::string _phrase_codee;


public:

  // Constructeur
  Enigme1(std::string nom_carte, int id, int id_enigme, int nb_essais, int code_solution, std::string phrase);

  // Destructeur : bail virtuel ?? ou alors hérite direct de celui de la classe mère ??

  // Getter
  std::string get_phrase() const {return _phrase};
  std::string get_phrase_codee() const {return _phrase_codee};

  // Méthodes
  std::string codage_jules_cesar(int decalage, bool sens_decalage);



};
