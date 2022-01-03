#pragma once

#include <iostream>
#include <map>
#include "enigme.hh"


class Enigme2 : public Enigme{ // énigme avec le livre de Roald Dahl

private:
  std::map<char, int> _alphabet_indices; // map pour ne pas balayer l'alphabet à chaque fois qu'on cherche l'indice d'une lettre
  std::string _phrase;                   // phrase rentrée par l'utilisateur à coder
  std::string _phrase_codee;             // phrase codée en fonction du décalage et du sens du décalage indiqués par l'utilisateur dans les paramètres de la fonction codage_jules_cesar

  // REMARQUE : _phrase et _phrase_codee contiennent uniquement des lettres en majuscules et/ou des espaces
  
public:
  // Constructeur
  Enigme2(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int code_solution, int id_carte_debloquee, std::string phrase);

  // Destructeur : bail virtuel ?? ou alors hérite direct de celui de la classe mère ??

  // Getter
  std::string get_phrase() const {return _phrase;};
  std::string get_phrase_codee() const {return _phrase_codee;};

  // Méthodes
  void codage_jules_cesar(int decalage, bool sens_decalage); // permet de coder la _phrase passée dans le constructeur par l'utilisateur



};
