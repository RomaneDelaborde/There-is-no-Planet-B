#pragma once

#include <iostream>
#include "carte.hh"


class Enigme : public Carte {

private:
  // 1 énigme = 1 carte (où il faut "rentrer" le code) donc pas besoin de _id_enigme
  int _nb_essais; // nombre d'essais pour réussir l'énigme

protected:
  int _code_solution; // code de la solution de l'énigme = code ou id d'un objet (ex: livre Charlie) -> à ne pas mettre dans le constructeur car calculé par des méthodes sauf pour Charlie (d'où 2 constructeurs)
  int _id_carte_debloquee; // id de la carte débloquée lorsque l'énigme est réussie


public:
  // Constructeurs
  Enigme(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int id_carte_debloquee): Carte(nom_carte, id, id_cartes_kick), _nb_essais(nb_essais), _id_carte_debloquee(id_carte_debloquee) {};
  Enigme(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int code_solution, int id_carte_debloquee): Carte(nom_carte, id, id_cartes_kick), _nb_essais(nb_essais), _code_solution(code_solution), _id_carte_debloquee(id_carte_debloquee) {}; // Constructeur pour Charlie

  // Destructeur : bail virtuel ?? ou alors hérite direct de celui de la classe mère ??

  // Getter
  int get_nb_essais() const {return _nb_essais;};
  int get_code_solution() const {return _code_solution;};
  int get_id_carte_debloquee() const {return _id_carte_debloquee;};

  // Méthodes
  void affichage_info_carte() const;
  bool code_correct(int val); // val est l'entier proposé par le joueur comme réponse à l'énigme : renvoie 0 si le joueur a faux et 1 sinon

  virtual void calcul_solution_enigme(); //  Méthode virtuelle qui renvoie la valeur correspondant à la solution de l'énigme

};
