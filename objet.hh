#pragma once

#include <iostream>
#include <map>
#include "carte.hh"

class Objet : public Carte{

// Classe pas à jour

private:
  // bool _union; // vaut 1 s'il faut combiner juste l'un des objets combinable de la liste et 0 s'il faut les combiner au moins une fois avec tous les objets de la liste -> on devrait pas en avoir besoin
  std::map<int, int> _objets_combinables; // map : en clé les id des objets combinables avec cet objet et en valeur : id de la carte résultante de cette combinaison


public:

  // Constructeur
  Objet(std::string nom_carte, int id, std::map<int, int> objets_combinables): Carte(nom_carte, id), _objets_combinables(objets_combinables){}; // héritage constructeur classe mère

  // Destructeur : bail virtuel ?? ou alors hérite direct de celui de la classe mère ??

  // Méthodes

  // Getter _objets_combinables
  std::map<int, int> get_objets_combinables() const {return _objets_combinables;};

};
