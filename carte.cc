#include "carte.hh"

void Carte::affichage_info_carte() const {
  std::cout << std::endl << "Nom carte : " << _nom_carte << std::endl;
  std::cout << "Id : " << _id << std::endl;

  std::cout << "Id cartes suivantes : ";
  for (std::size_t i=0; i<_id_cartes_suivantes.size();i++) {
    std::cout << _id_cartes_suivantes[i] << ' ';
  }
  std::cout << std::endl;
  std::cout << "Id cartes kick : ";
  for (std::size_t i=0; i<_id_cartes_kick.size();i++) {
    std::cout << _id_cartes_kick[i] << ' ';
  }
  std::cout << std::endl;
  std::cout << "Id carte autre choix (vaut 0 s'il y en a pas): " << _id_carte_autre_choix << std::endl;
  std::cout << std::endl;
}
