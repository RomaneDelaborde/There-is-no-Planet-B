#pragma once

#include <iostream>
#include <map>
#include "carte.hh"

class Objet : public Carte{

// Classe pas à jour

private:
  bool _union; // vaut 1 s'il faut combiner juste l'un des objets combinable de la liste et 0 s'il faut les combiner au moins une fois avec tous les objets de la liste
  std::map<Objet, Carte> _objets_combinables; // map : en clé les objets combinables avec cet objet (map d'Objet ou d'id pour faciliter les choses ??) et en valeur : Carte (ou id_carte ??) de la carte résultante de cette union


public:

  // Constructeur
  Objet(std::string nom_carte, int id, bool union): Carte(nom_carte, id), _union(union){}; // héritage constructeur classe mère

  // Destructeur : bail virtuel ?? ou alors hérite direct de celui de la classe mère ??

  // Méthodes

  // Getter _union
  bool get_union() const {return _union};

  // Getter _objets_combinables
  std::map<Objet> get_objets_combinables() const {return _objets_combinables};

};
