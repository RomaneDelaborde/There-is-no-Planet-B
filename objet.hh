#pragma once

#include <iostream>
#include <map>
#include "carte.hh"

class Objet : public Carte{

private:
  std::map<int, int> _id_objets_combinables; // id des objets combinables avec cet objet en clés et id de la carte résultante de cette combinaison en valeur


public:

  // Constructeurs avec héritage du constructeur de la classe mère
  Objet(std::string nom_carte, int id):Carte(nom_carte,id){}; // certains objets (ticket_dore_o, certificat, ...) ne se combinent avec rien
  Objet(std::string nom_carte, int id, std::map<int, int> id_objets_combinables): Carte(nom_carte, id), _id_objets_combinables(id_objets_combinables){};

  // Destructeur : bail virtuel ?? ou alors hérite direct de celui de la classe mère ??

  // Getter
  std::map<int, int> get_id_objets_combinables() const {return _id_objets_combinables;};

  // Méthodes
  void affichage_info_objet() const;
  bool id_obj_est_combinable(int id_obj) const; // renvoie 0 si id_obj n'est pas combinable avec l'objet et 1 sinon 
};
