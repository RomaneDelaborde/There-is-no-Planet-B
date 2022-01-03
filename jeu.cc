#include "jeu.hh"


Jeu::Jeu()
{
  lecture_csv_carte_basique(fichier_cartes_basiques);
  lecture_csv_carte_objet(fichier_cartes_objets);

  int nb=5; // nombre d'essais (ici commun à toutes les énigmes mais chacune pourrait avoir sa propre valeur), 5 est une valeur arbitraire

  // Enigmes entrées à la main car il y en a que 3
  Enigme2 charlie("zoom_livres",32,{33},nb,311,33,"TIRER LE LIVRE DE ROALD DAHL");
  //charlie.codage_jules_cesar(7,1); // fonction utile seulement à la création des énigmes -> c'est pour ça qu'elle n'est pas mise dans le constructeur
  //std::cout << charlie.get_phrase() << std::endl;
  //std::cout << charlie.get_phrase_codee() << std::endl;

  _cartes_enigmes.push_back(charlie);
  //_cartes_jeu.push_back(Enigme2("zoom_livres",32,{33},5,311,33,"TIRER LE LIVRE DE ROALD DAHL"));

  Enigme3 planete("coffre_fort",45,{50},nb,46, "UNJUST+B");
  //std::cout << planete.get_chaine << std::endl;
  //std::cout << planete.get_code_solution() << std::endl<< std::endl;

  _cartes_enigmes.push_back(planete);


  _cartes_jeu=_cartes_basiques;
  //_cartes_jeu.insert(_cartes_jeu.end(), _cartes_basiques.begin(), _cartes_basiques.end());
  _cartes_jeu.insert(_cartes_jeu.end(), _cartes_objets.begin(), _cartes_objets.end());
  _cartes_jeu.insert(_cartes_jeu.end(), _cartes_enigmes.begin(), _cartes_enigmes.end());

  for(std::size_t i=0;i<_cartes_jeu.size();i++)
  {
    if(i==0) // seule la carte regles (le premiere du vector _cartes_jeu) est initialisée à la valeur 1 dans _map_id
    {
      _map_id[_cartes_jeu[i].get_id()]=1;
    }
    else
    {
      _map_id[_cartes_jeu[i].get_id()]=0;
    }
  }

  for(std::size_t i=0;i<_cartes_basiques.size();i++)
  {
    _cartes_basiques[i].affichage_info_carte();
  }

  for(std::size_t i=0;i<_cartes_objets.size();i++)
  {
    _cartes_objets[i].affichage_info_objet();
  }

  for(std::size_t i=0;i<_cartes_enigmes.size();i++)
  {
    _cartes_enigmes[i].affichage_info_enigme();
  }

  /*
  for(std::size_t i=0;i<_cartes_basiques.size();i++)
  {
    _cartes_basiques[i].affichage_info_carte();

    if(i==0) // seule la carte regles (le premiere du vector _cartes_jeu) est initialisée à la valeur 1 dans _map_id
    {
      _map_id[_cartes_basiques[i].get_id()]=1;
    }
    else
    {
      _map_id[_cartes_basiques[i].get_id()]=0;
    }
  }

  for(std::size_t i=0;i<_cartes_objets.size();i++)
  {
    _cartes_objets[i].affichage_info_objet();
    _map_id[_cartes_objets[i].get_id()]=0;

  }

  for(std::size_t i=0;i<_cartes_enigmes.size();i++)
  {
    _cartes_enigmes[i].affichage_info_enigme();
    _map_id[_cartes_enigmes[i].get_id()]=0;
  }
  */


  //parcours vecteur _cartes_jeu
  // _cartes_jeu[i]=new Carte(paramètres)
  // remplissage _cartes_jeu et __map_id en même temps (3 fichiers csv : cartes normales, cartes énigmes et cartes objets)
  // toutes les valeurs de _map_id sont initialisées à 0 sauf la carte règles qui vaut 1

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
      std::vector<int> v1 =lecture_str_tab(post); // à renommer
      std::vector<int> v2 =lecture_str_tab(kick); // à renommer
      if(v1[0]!=0) // si la carte possède au moins une carte suivante
      {
        _cartes_basiques.push_back(Carte(nom_carte, id, v1, v2));
      }
      else
      {
        _cartes_basiques.push_back(Carte(nom_carte, id, v2));
      }
    }
  }
  else
  {
    std::cout << "ERREUR : impossible d'ouvrir le fichier en lecture" << std::endl;
  }
}



void Jeu::lecture_csv_carte_objet(std::string nom_fichier)
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
      std::string objets_combinables;
      std::string combinaisons_obtenues;

      std::string tempString;

      std::stringstream inputString(ligne);

      std::getline(inputString, nom_carte, ',');
      std::getline(inputString, tempString, ',');
      id=atoi(tempString.c_str());

      std::getline(inputString, objets_combinables, ',');
      std::getline(inputString, combinaisons_obtenues, ',');

      ligne="";

      // Création d'une carte
      std::vector<int> v1 =lecture_str_tab(objets_combinables); // à renommer
      std::vector<int> v2 =lecture_str_tab(combinaisons_obtenues); // à renommer

      if(v1.size()!=v2.size())
      {
        std::cout << "ERREUR : il n'y a pas autant d'objets combinables que de combinaisons possibles" << std::endl;
        return;
      }
      if(v1[0]!=0)
      {
        // Création map
        std::map<int, int> obj; // obj pour objets combinables
        for(std::size_t i=0; i<v1.size();i++)
        {
          obj[v1[i]]=v2[i];
        }
        _cartes_objets.push_back(Objet(nom_carte, id, obj));
      }
      else
      {
        _cartes_objets.push_back(Objet(nom_carte, id));
      }


    }
  }
  else
  {
    std::cout << "ERREUR : impossible d'ouvrir le fichier en lecture" << std::endl;
  }
}


Carte Jeu::carte(const int id_carte) const // à partir d'une valeur d'id d'une carte (unique), renvoie sa carte correspondante
{
  for(std::size_t i=0; i< _cartes_jeu.size(); i++)
  {
    if(_cartes_jeu[i].get_id()==id_carte) // si on a trouvé un match des id, on retourne la carte correspondante
    {
      return _cartes_jeu[i];
    }
  }
  // si on a pas trouvé un match des id, on affiche un message d'erreur mais renvoie quand même une carte (celle des règles du jeu)
  std::cout << "ERREUR : l'id entré en paramètres ne correspond à aucune carte basique" << std::endl;
  return _cartes_jeu[0];
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
    if(_map_id[_cartes_jeu[i].get_id()]==1) // Si la carte du jeu est affichée dans _map_id, on parcourt ses cartes postérieures
    {
      for(std::size_t j=0; j< _cartes_jeu[i].get_id_cartes_suivantes().size(); j++) // Si dans la liste de ses cartes postérieures, on a id_carte alors on retourne 1 mais ATTENTION : cela signifie que dans les cartes postérieures il ne faut pas mettre les cartes déblocables (il faudrait séparer les cartes secrètes des cartes sans conditions)
      {
        if(_cartes_jeu[i].get_id_cartes_suivantes()[j]==id_carte)
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


/*
bool Jeu::solution_enigme_valide(int id_carte_enigme, int val)
{
  if(!id_existe(id_carte_enigme))
  {
    // affichage pop-up du style : "Vous tentez de répondre à une carte énigme qui n'existe pas"
    return 0;
  }

  // ENIGME.code_correct(int val)

}
*/

/*
bool Jeu::combinaison_realisable(int id_obj_1, int id_obj_2)
{
  if(!id_existe(id_obj_1) || !id_existe(id_obj_2))
  {
    return 0;
  }
}
*/
