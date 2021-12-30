#include "carte.hh"

void Carte::affichage_info_carte() const
{
  std::cout << "Nom carte : " << _nom_carte << std::endl;
  std::cout << "Id : " << _id << std::endl;
  std::cout << "Id cartes suivantes : ";
  for(int i=0; i<_id_cartes_posterieures.size();i++)
  {
    std::cout << _id_cartes_posterieures[i] << ' ';
  }
  std::cout << std::endl;
  std::cout << "Id cartes kick : ";
  for(int i=0; i<_id_cartes_kick.size();i++)
  {
    std::cout << _id_cartes_kick[i] << ' ';
  }
}
