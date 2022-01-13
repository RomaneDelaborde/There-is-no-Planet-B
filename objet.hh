#pragma once

#include <iostream>
#include <map>
#include "carte.hh"

class Objet : public Carte{

private:
  std::map<int, int> _id_objets_combinables; // id des objets combinables avec cet objet en clés et id de la carte résultante de cette combinaison en valeur
  bool _est_objet_inventaire; // vaut 1 si l'objet peut-être placé dans l'inventaire et 0 sinon
public:

  // Constructeurs avec héritage du constructeur de la classe mère
  Objet(std::string nom_carte, int id, bool est_objet_inventaire):Carte(nom_carte,id), _est_objet_inventaire(est_objet_inventaire){}; // certains objets (ticket_dore_o, certificat, ...) ne se combinent avec rien
  Objet(std::string nom_carte, int id, std::map<int, int> id_objets_combinables, bool est_objet_inventaire): Carte(nom_carte, id), _id_objets_combinables(id_objets_combinables), _est_objet_inventaire(est_objet_inventaire){};

  // Destructeur : bail virtuel ?? ou alors hérite direct de celui de la classe mère ??

  // Getter
  std::map<int, int> get_id_objets_combinables() const {return _id_objets_combinables;};
  bool get_est_objet_inventaire() const {return _est_objet_inventaire;};

  // Méthodes
  void affichage_info_objet() const;
  bool id_obj_est_combinable(int id_obj) const; // renvoie 0 si id_obj n'est pas combinable avec l'objet et 1 sinon
};
