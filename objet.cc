#include "objet.hh"

void Objet::affichage_info_carte() const {
  std::cout << "Nom carte : " << _nom_carte << std::endl;
  std::cout << "Id : " << _id << std::endl;


  //std::map<int,int>::iterator iter = _id_objets_combinables.begin();
  auto iter = _id_objets_combinables.begin(); // auto permet de savoir par lui-même quel est le type de iter (en fonction de ce qu'il y a à droite de l'égalité)

  while(iter != _id_objets_combinables.end()) {
    int c =  iter->first; // c pour clé
    int v = iter->second; // v pour valeur

    std::cout << "Id objet combinable : " << c << " => Id résultat combinaison : "<< v << std::endl;

    ++iter;
  }

  std::cout << "Bool inventaire : " << _est_objet_inventaire << std::endl;

  std::cout << std::endl << std::endl;
}


bool Objet::id_obj_est_combinable(int id_obj) const {
  if (_id_objets_combinables.find(id_obj)!=_id_objets_combinables.end()) {return 1;} // si l'id de l'objet est dans le map c'est bon
  return 0;
}

int  Objet::operator+(const Objet & p)
{
  if(id_obj_est_combinable(p.get_id()))
  {
    return _id_objets_combinables[p.get_id()];
  }
  std::cout << "ERREUR : pas de combinaison possible entre les deux objets indiqués" << std::endl;
  return -1;
}
