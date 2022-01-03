#include "objet.hh"

void Objet::affichage_info_objet() const
{
  std::cout << "Nom carte : " << _nom_carte << std::endl;
  std::cout << "Id : " << _id << std::endl;


  //std::map<int,int>::iterator iter = _id_objets_combinables.begin();
  auto iter = _id_objets_combinables.begin(); // auto permet de savoir par lui-même quel est le type de iter (en fonction de ce qu'il y a à droite de l'égalité)

  while(iter != _id_objets_combinables.end())
  {
    int c =  iter->first; // c pour clé
    int v = iter->second; // v pour valeur

    std::cout << "Id objet combinable : " << c << " => Id résultat combinaison : "<< v << std::endl;

    ++iter;
  }

  std::cout << std::endl << std::endl;
}
