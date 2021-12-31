#include "jeu.hh"


Jeu::Jeu()
{
  //parcours vecteur _cartes_jeu
  // _cartes_jeu[i]=new Carte(paramètres)
  // remplissage _cartes_jeu et __map_id en même temps (3 fichiers csv : cartes normales, cartes énigmes et cartes objets)
  // toutes les valeurs de _map_id sont initialisées à 0 sauf la carte règles qui vaut 1
  // vérifier qu'il y ait le même nb d'éléments dans _cartes_jeu et _map_id après la création de ces 2 conteneurs (sécurité)

}



std::vector<int> Jeu::lecture_str_tab(std::string chaine)
{
  std::vector<std::string> res={};

  // Lecture de la chaine avec des délimiteurs
  std::string const delims{ "-" }; // délimiteurs

  size_t beg, pos = 0;
  while ((beg = chaine.find_first_not_of(delims, pos)) != std::string::npos)
  {
      pos = chaine.find_first_of(delims, beg + 1);
      res.push_back(chaine.substr(beg, pos - beg)); // Ajout dans le vecteur _chaine_eclatee
  }

  std::vector<int> res_int={};

  std::transform(res.begin(), res.end(), std::back_inserter(res_int), [](const std::string& str) { return std::stoi(str); });

  // Affichage de res_int
  /*
  for (int i:res_int)
  {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  */

  return res_int;

}



void Jeu::lecture_csv_carte_basique(std::string nom_fichier)
{
  std::ifstream fichier(nom_fichier); // Ouverture du fichier en mode lecture

  if(fichier) // Si pas de problème à l'ouverture, on fait ce qu'on a à faire
  {
    std::string ligne= "";
    std::getline(fichier,ligne); // pour passer la première ligne
    while(std::getline(fichier,ligne))
    {
      std::string nom_carte;
      int id;
      std::string post;
      std::string kick;

      std::string tempString;

      std::stringstream inputString(ligne);

      std::getline(inputString, nom_carte, ',');
      std::getline(inputString, tempString, ',');
      id=atoi(tempString.c_str());

      std::getline(inputString, post, ',');
      std::getline(inputString, kick, ',');

      ligne="";

      // Création d'une carte
      std::cout << nom_carte <<  std::endl;
      std::cout << id <<  std::endl;

      std::cout << post <<  std::endl;
      std::cout << kick <<  std::endl;


      std::cout << "POST" << std::endl;
      std::vector<int> v1 =lecture_str_tab(post);
      std::cout << "KICK" << std::endl;
      std::vector<int> v2 =lecture_str_tab(kick);

    }
  }
  else
  {
    std::cout << "ERREUR : impossible d'ouvrir le fichier en lecture" << std::endl;
  }
}



// la fonction à la ligne ci-dessus créée-t-elle une nouveau pointeur (qu'il faut donc supprimer?) si on fait juste par exemple carte(0).get_nom_carte()   ??
Carte* Jeu::carte(const int id_carte) const // à partir d'une valeur d'id d'une carte (unique), renvoit sa carte correspondante
{
  for(std::size_t i=0; i< _cartes_jeu.size(); i++)
  {
    if(_cartes_jeu[i]->get_id()==id_carte) // si on a trouvé un match des id, on retourne la carte correspondante
    {
      return _cartes_jeu[i];
    }
  }
  // si on a pas trouvé un match des id, on affiche un message d'erreur et on retourne un pointeur vide
  std::cout << "ERREUR : l'id entré en paramètres ne correspond à aucune carte" << std::endl;
  return _cartes_jeu[0];//nullptr; // faudrait renvoyer une valeur NULL (passer par des pointeurs ??) return NULL ou dans l'idéal faire un "throw no_such_id_error"
  // message d'erreur mais renvoie quand même la carte règles
}


bool Jeu::id_existe(const int id_carte) const
{
  if(_map_id.find(id_carte)==_map_id.end()) // si l'id n'existe pas dans _map_id
  {
    //std::cout << "ERREUR : l'id entré en paramètres ne correspond à aucune carte" << std::endl;
    return 0;
  }
  return 1;
}



void Jeu::carte_map_affichage(const int id_carte) // on pourrait faire 1 seule lecture_str_tab pour affichage/désaffichage mais humain peut plus facilement se mélanger les pinceaux dans les valeurs
{
  if(!id_existe(id_carte)) // si l'id n'existe pas on ne fait rien
  {
    return;
  }
  _map_id[id_carte]=1; // sinon on modifie la valeur de la clé correspondant à id_carte dans _map_id
}

void Jeu::carte_map_desaffichage(const int id_carte)
{
  if(!id_existe(id_carte)) // si l'id n'existe pas on ne fait rien
  {
    return;
  }
  _map_id[id_carte]=-1; // sinon on modifie la valeur de la clé correspondant à id_carte dans _map_id
}


bool Jeu::affichage_carte_autorise(const int id_carte)
{
  for(std::size_t i=0; i< _cartes_jeu.size(); i++) // Parcours des cartes du jeu
  {
    if(_map_id[_cartes_jeu[i]->get_id()]==1) // Si la carte du jeu est affichée dans _map_id, on parcourt ses cartes postérieures
    {
      for(std::size_t j=0; j< _cartes_jeu[i]->get_id_cartes_posterieures().size(); j++) // Si dans la liste de ses cartes postérieures, on a id_carte alors on retourne 1 mais ATTENTION : cela signifie que dans les cartes postérieures il ne faut pas mettre les cartes déblocables (il faudrait séparer les cartes secrètes des cartes sans conditions)
      {
        if(_cartes_jeu[i]->get_id_cartes_posterieures()[j]==id_carte)
        {
          return 1;
        }
      }
    }
  }
  return 0;
}

void Jeu::demande_affichage_carte(const int id_carte) // pourrait être une lecture_str_tab qui renvoie un bool [0 si affichage carte effectué avec succès et 1 si carte pas affichée] et après on opère tous les changements (*)
{
  if(!id_existe(id_carte)) // si l'id n'existe pas
  {
    // affichage pop-up pour le joueur qqpart du type "Cet id ne correspond à aucune carte."
    return;
  }

  switch(_map_id[id_carte]){
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
