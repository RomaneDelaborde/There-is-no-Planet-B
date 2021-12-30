#include "jeu.hh"


Jeu::Jeu()
{
  // remplissage _cartes_jeu et __map_id en même temps (3 fichiers csv : cartes normales, cartes énigmes et cartes objets)
  // toutes les valeurs de _map_id sont initialisées à 0 sauf la carte règles qui vaut 1
  // vérifier qu'il y ait le même nb d'éléments dans _cartes_jeu et _map_id après la création de ces 2 conteneurs (sécurité)

}

bool Jeu::id_existe(const int id_carte) const
{
  if(_map_id.find(carte(id_carte))==_map_id.end()) // si l'id n'existe pas dans _map_id
  {
    //std::cout << "ERREUR : l'id entré en paramètres ne correspond à aucune carte" << std::endl;
    return 0;
  }
  return 1;
}



Carte Jeu::carte(const int id_carte) const // à partir d'une valeur d'id d'une carte (unique), renvoit sa carte correspondante
{
  for(int i=0; i< _cartes_jeu.size(); i++)
  {
    if(_cartes_jeu[i]._id==id_carte) // si on a trouvé un match des id, on retourne la carte correspondante
    {
      return _cartes_jeu[i];
    }
  }
  // si on a pas trouvé un match des id, on affiche un message d'erreur et on retourne un pointeur vide
  std::cout << "ERREUR : l'id entré en paramètres ne correspond à aucune carte" << std::endl;
  return std::nullptr; // return NULL ou dans l'idéal faire un "throw no_such_id_error"
}


void Jeu::carte_map_affichage(const int id_carte) // on pourrait faire 1 seule fonction pour affichage/désaffichage mais humain peut plus facilement se mélanger les pinceaux dans les valeurs
{
  if(!id_existe(id_carte)) // si l'id n'existe pas on ne fait rien
  {
    return;
  }
  _map_id[carte(id_carte)]=1; // sinon on modifie la valeur de la clé correspondant à id_carte dans _map_id
}

void Jeu::carte_map_desaffichage(const int id_carte)
{
  if(!id_existe(id_carte)) // si l'id n'existe pas on ne fait rien
  {
    return;
  }
  _map_id[carte(id_carte)]=-1; // sinon on modifie la valeur de la clé correspondant à id_carte dans _map_id
}


bool Jeu::affichage_carte_autorise(const int id_carte) const
{
  for(int i=0; i< _cartes_jeu.size(); i++) // Parcours des cartes du jeu
  {
    if(_map_id[_cartes_jeu[i]._id]==1) // Si la carte du jeu est affichée dans _map_id, on parcourt ses cartes postérieures
    {
      for(int j=0; j< _cartes_jeu._id_cartes_posterieures.size(); j++) // Si dans la liste de ses cartes postérieures, on a id_carte alors on retourne 1 mais ATTENTION : cela signifie que dans les cartes postérieures il ne faut pas mettre les cartes déblocables (il faudrait séparer les cartes secrètes des cartes sans conditions)
      {
        if(_cartes_jeu._id_cartes_posterieures[j]==id_carte)
        {
          return 1;
        }
      }
    }
  }
  return 0;
}

void Jeu::demande_affichage_carte(const int id_carte) // pourrait être une fonction qui renvoie un bool [0 si affichage carte effectué avec succès et 1 si carte pas affichée] et après on opère tous les changements (*)
{
  if(!id_existe(id_carte)) // si l'id n'existe pas
  {
    // affichage pop-up pour le joueur qqpart du type "Cet id ne correspond à aucune carte."
    return;
  }

  switch(_map_id[carte(id_carte)]){
    case 1:
      //std::cout << "ERREUR : la carte est déjà affichée" << std::endl;
      // affichage pop-up pour le joueur qqpart du type "La carte souhaitée est déjà affichée."
      break;

    case -1:
      //std::cout << "ERREUR : la carte a déjà été affichée" << std::endl;
      // affichage pop-up pour le joueur qqpart du type "La carte souhaitée a été défaussée car elle n'est plus utile."

      break;

    case 0:
      if(affichage_carte_autorise(id_carte))
      {
        // afficher carte dans la fenêtre graphique
        // faire passer carte à la valeur 1 et tout le blabla -> à faire ici ou là (*) ?
      }
      else
      {
        // affichage pop-up pour le joueur qqpart du type "La carte souhaitée n'est pas accessible."
      }

      break;

    //default:
      //break;

  }
  return;
}
