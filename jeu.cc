#include "jeu.hh"

Jeu::Jeu()
{
  lecture_csv_carte_basique(fichier_cartes_basiques);
  lecture_csv_carte_objet(fichier_cartes_objets);

  int nb=5; // nombre d'essais (ici commun à toutes les énigmes mais chacune pourrait avoir sa propre valeur), 5 est une valeur arbitraire

  // Enigmes entrées à la main car il y en a que 3
  Enigme1 radio("radio", 13, {14}, 5, 14, 8, 7, 9);
  Enigme2 charlie("zoom_livres",32,{33},nb,311,33,"TIRER LE LIVRE DE ROALD DAHL");
  Enigme3 planete("coffre_fort",45,{50},nb,46, "UNJUST+B");

  // Ajout des énigmes dans la liste des énigmes
  _cartes_enigmes.push_back(radio);
  _cartes_enigmes.push_back(charlie); // OU _cartes_enigmes.push_back(Enigme2("zoom_livres",32,{33},5,311,33,"TIRER LE LIVRE DE ROALD DAHL"));
  _cartes_enigmes.push_back(planete);

  _id_cartes_enigmes.push_back(radio.get_id());
  _id_cartes_enigmes.push_back(charlie.get_id());
  _id_cartes_enigmes.push_back(planete.get_id());


  _cartes_jeu=_cartes_basiques;                                                                   // ajout des cartes basiques dans _cartes_jeu
  //_cartes_jeu.insert(_cartes_jeu.end(), _cartes_basiques.begin(), _cartes_basiques.end());
  _cartes_jeu.insert(_cartes_jeu.end(), _cartes_objets.begin(), _cartes_objets.end());            // ajout des cartes objets dans _cartes_jeu
  _cartes_jeu.insert(_cartes_jeu.end(), _cartes_enigmes.begin(), _cartes_enigmes.end());          // ajout des cartes enigmes dans _cartes_jeu

  for(std::size_t i=0;i<_cartes_jeu.size();i++) // parcours de _cartes_jeu
  {
    if(i==0) // seule la carte regles (le première de_cartes_jeu) est initialisée à la valeur 1 dans _map_id
    {
      _map_id[_cartes_jeu[i].get_id()]=1;
    }
    else    // sinon mise à 0 pour toutes les autres cartes
    {
      _map_id[_cartes_jeu[i].get_id()]=0;
    }
  }

  for(std::size_t i=0;i<_cartes_basiques.size();i++)  // Affichage des informations sur les cartes basiques
  {
    _cartes_basiques[i].affichage_info_carte();
  }

  for(std::size_t i=0;i<_cartes_objets.size();i++)    // Affichage des informations sur les cartes objets
  {
    _cartes_objets[i].affichage_info_objet();
  }

  for(std::size_t i=0;i<_cartes_enigmes.size();i++)   // Affichage des informations sur les cartes enigmes
  {
    _cartes_enigmes[i].affichage_info_enigme();
  }
}



std::vector<int> Jeu::lecture_str_tab(std::string chaine)
{
  std::vector<std::string> res={}; // res pour résultat

  // Lecture de la chaine avec un délimiteur
  std::string const delims{ "-" }; // délimiteur

  size_t beg, pos = 0;
  while ((beg = chaine.find_first_not_of(delims, pos)) != std::string::npos)
  {
      pos = chaine.find_first_of(delims, beg + 1);
      res.push_back(chaine.substr(beg, pos - beg)); // Ajout de chaque int (séparé par des tabulats) sous forme d'un str dans le vecteur res
  }

  std::vector<int> res_int={};

  std::transform(res.begin(), res.end(), std::back_inserter(res_int), [](const std::string& str) { return std::stoi(str); }); // conversion du vecteur res de str en vecteur res_int d'entiers

  return res_int;

}



void Jeu::lecture_csv_carte_basique(std::string nom_fichier)
{
  std::ifstream fichier(nom_fichier); // Ouverture du fichier en mode lecture

  if(fichier) // Si pas de problème à l'ouverture, on fait ce qu'on a à faire
  {
    std::string ligne= "";
    std::getline(fichier,ligne); // pour passer la première ligne (celle avec le nom des colonnes)
    while(std::getline(fichier,ligne))
    {
      std::string nom_carte;
      int id;
      std::string suiv; // id des cartes suivantes sous forme de string (valeurs séparées par des tabulats)
      std::string kick; // id des cartes permettant de kicker la carte (valeurs séparées par des tabulats)
      int choix; // id de la carte autre choix

      std::string tempString;

      std::stringstream inputString(ligne);

      std::getline(inputString, nom_carte, ',');
      std::getline(inputString, tempString, ',');
      id=atoi(tempString.c_str());

      std::getline(inputString, suiv, ',');
      std::getline(inputString, kick, ',');

      std::getline(inputString, tempString, ',');
      choix=atoi(tempString.c_str());

      ligne="";

      // Création d'une carte
      std::vector<int> v1 =lecture_str_tab(suiv); // v1 = vecteur des id des cartes suivantes sous forme de int
      std::vector<int> v2 =lecture_str_tab(kick); // v2 = vecteur des id des cartes kick sous forme de int

      _cartes_basiques.push_back(Carte(nom_carte, id, v1, v2, choix));
      _id_cartes_basiques.push_back(id);
    }
  }
  else // s'il y a un problème à l'ouverture, on affiche un message d'erreur
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
    std::getline(fichier,ligne); // pour passer la première ligne (celle avec le nom des colonnes)
    while(std::getline(fichier,ligne))
    {
      std::string nom_carte;
      int id;
      std::string objets_combinables; // id des cartes des objets combinables sous forme de string (valeurs séparées par des tabulats)
      std::string combinaisons_obtenues; // id des cartes obtenues par combinaison sous forme de string (valeurs séparées par des tabulats)
      bool est_objet_inventaire;

      std::string tempString;

      std::stringstream inputString(ligne);

      std::getline(inputString, nom_carte, ',');
      std::getline(inputString, tempString, ',');
      id=atoi(tempString.c_str());

      std::getline(inputString, objets_combinables, ',');
      std::getline(inputString, combinaisons_obtenues, ',');

      std::getline(inputString, tempString, ',');
      est_objet_inventaire=atoi(tempString.c_str());

      ligne="";

      // Création d'une carte
      std::vector<int> v1 =lecture_str_tab(objets_combinables); // v1 = vecteur des id des cartes des objets combinables sous forme de int
      std::vector<int> v2 =lecture_str_tab(combinaisons_obtenues); // v2 = vecteur des id des cartes obtenues par combinaison sous forme de int

      if(v1.size()!=v2.size()) // si jamais v1 et v2 ne sont pas de la même taille, on affiche un message d'erreur (car 1 combinaison = 1 carte obtenue)
      {
        std::cout << "ERREUR : il n'y a pas autant d'objets combinables que de combinaisons possibles" << std::endl;
        return;
      }

      if(v1[0]!=0) // si l'objet n'est pas combinable avec d'autres objets
      {
        // Création map
        std::map<int, int> obj; // obj pour objets combinables
        for(std::size_t i=0; i<v1.size();i++)
        {
          obj[v1[i]]=v2[i];
        }
        _cartes_objets.push_back(Objet(nom_carte, id, obj, est_objet_inventaire));
      }
      else // sinon si l'objet n'est pas combinable avec d'autres objets (ex: certificat)
      {
        _cartes_objets.push_back(Objet(nom_carte, id, est_objet_inventaire));
        _id_cartes_objets.push_back(id);
      }
    }
  }
  else // s'il y a un problème à l'ouverture, on affiche un message d'erreur
  {
    std::cout << "ERREUR : impossible d'ouvrir le fichier en lecture" << std::endl;
  }
}


Carte Jeu::carte(const int id_carte) const // à partir d'une valeur d'id (unique) d'une carte basique, renvoie sa carte correspondante
{
  for(std::size_t i=0; i< _cartes_basiques.size(); i++)
  {
    if(_cartes_basiques[i].get_id()==id_carte) // si on a trouvé un match des id, on retourne la carte (basique) correspondante
    {
      return _cartes_basiques[i];
    }
  }
  // si on a pas trouvé un match des id, on affiche un message d'erreur mais on renvoie quand même une carte (celle des règles du jeu)
  std::cout << "ERREUR : l'id entré en paramètres ne correspond à aucune carte basique" << std::endl;
  return _cartes_basiques[0];
}

Objet Jeu::objet(const int id_carte) const // à partir d'une valeur d'id (unique) d'une carte objet, renvoie son objet correspondant
{
  for(std::size_t i=0; i< _cartes_objets.size(); i++)
  {
    if(_cartes_objets[i].get_id()==id_carte) // si on a trouvé un match des id, on retourne l'objet correspondant
    {
      return _cartes_objets[i];
    }
  }
  // si on a pas trouvé un match des id, on affiche un message d'erreur mais on renvoie quand même un objet
  std::cout << "ERREUR : l'id entré en paramètres ne correspond à aucun objet" << std::endl;
  return _cartes_objets[0];
}

Enigme Jeu::enigme(const int id_carte) const // à partir d'une valeur d'id (unique) d'une carte enigme, renvoie son énigme correspondante
{
  for(std::size_t i=0; i< _cartes_enigmes.size(); i++)
  {
    if(_cartes_enigmes[i].get_id()==id_carte) // si on a trouvé un match des id, on retourne l'énigme correspondante
    {
      return _cartes_enigmes[i];
    }
  }
  // si on a pas trouvé un match des id, on affiche un message d'erreur mais on renvoie quand même une énigme
  std::cout << "ERREUR : l'id entré en paramètres ne correspond à aucune carte basique" << std::endl;
  return _cartes_enigmes[0];
}


bool Jeu::id_existe(const int id_carte) const
{
  if(_map_id.find(id_carte)==_map_id.end()) // si l'id n'existe pas dans _map_id
  {
    //std::cout << "ERREUR : l'id entré en paramètres ne correspond à aucune carte" << std::endl;
    return 0;
  }
  return 1; // sinon tout va bien, il existe et on renvoie 1
}


// fonction pas utilisée pour le moment
void Jeu::carte_map_affichage(const int id_carte) // on pourrait faire 1 seule lecture_str_tab pour affichage/désaffichage mais humain peut plus facilement se mélanger les pinceaux dans les valeurs
{
  if(!id_existe(id_carte)) // si l'id n'existe pas on ne fait rien
  {
    return;
  }
  _map_id[id_carte]=1; // sinon on modifie la valeur de la clé correspondant à id_carte dans _map_id
}

// fonction pas utilisée pour le moment
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
    if(_map_id[_cartes_jeu[i].get_id()]==1) // Si la carte du jeu est affichée dans _map_id, on parcourt les id qui se trouvent dans son attribut _id_cartes_suivantes
    {
      for(std::size_t j=0; j< _cartes_jeu[i].get_id_cartes_suivantes().size(); j++) // Si dans la liste de ses cartes suivantes, on a id_carte alors on retourne 1
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

void Jeu::affichage_carte(const int id_carte)
{

  // affichage carte interface graphique (ou ailleurs idk)

  // modifications communes aux différentes types de cartes
  // kick les cartes : si des cartes actuellement affichées peuvent être kick par l'arrivée de cette carte alors on les tej
  for(std::size_t i=0; i< _cartes_jeu.size(); i++) // Parcours des cartes du jeu
  {
    if(_map_id[_cartes_jeu[i].get_id()]==1) // Si la carte du jeu est affichée dans _map_id, on regarde son attribut id_cartes_kick
    {
      for(std::size_t j=0; j< _cartes_jeu[i].get_id_cartes_kick().size(); j++) // Si id_carte se trouve dans _id_cartes_kick, on peut tej la carte correspondate
      {
        if(_cartes_jeu[i].get_id_cartes_kick()[j]==id_carte)
        {
          _map_id[_cartes_jeu[i].get_id()]=-1;
        }
      }
    }
  }

  _map_id[id_carte]=1; // indiquer que la carte est affichée dans _map_id


  if(std::count(_id_cartes_basiques.begin(), _id_cartes_basiques.end(), id_carte)) // si la carte est une carte basique
  {
    if(carte(id_carte).get_id_carte_autre_choix() !=0) // s'il s'agit d'une carte choix (attribut _id_carte_autre_choix rempli seulement pour les cartes basiques)
    {
      _map_id[carte(id_carte).get_id_carte_autre_choix()]=-1; // on empêche le joueur d'accèder aux cartes des autres choix
    }
  }

  /*
  else if(std::count(_id_cartes_enigmes.begin(), _id_cartes_enigmes.end(), id_carte)) // si la carte est une carte énigme
  {
  }
  */

  else if(std::count(_id_cartes_objets.begin(), _id_cartes_objets.end(), id_carte)) // si la carte est une carte objet
  {
    if(objet(id_carte).get_est_objet_inventaire()) // si c'est une carte objet inventaire, on l'ajoute à l'inventaire
    {
      _inventaire.push_back(id_carte);
    }
  }

}


void Jeu::demande_affichage_carte(const int id_carte)
{
  if(!id_existe(id_carte)) // si l'id n'existe pas
  {
    // affichage pop-up pour le joueur qqpart du type "Cet id ne correspond à aucune carte."
    return;
  }

  switch(_map_id[id_carte]){
    case 1:
      // affichage pop-up pour le joueur qqpart du type "La carte souhaitée est déjà affichée."
      break;

    case -1:
      // affichage pop-up pour le joueur qqpart du type "La carte souhaitée ne peut pas être affichée."
      break;

    case 0:
      if(affichage_carte_autorise(id_carte)) // si la carte peut-être autorisée à être affichée, on l'affiche sinon pop-up d'erreur
      {
        // affichage_carte(id_carte); // afficher carte dans la fenêtre graphique et faire les modifications qui vont avec
        //remplacer bouton blanc par bouton image

      }
      else
      {
        // affichage pop-up pour le joueur qqpart du type "La carte souhaitée n'est pas accessible."
      }

      break;
  }
}



void Jeu::solution_enigme_valide(int id_carte_enigme, int val) const
{
  if(!std::count(_id_cartes_enigmes.begin(), _id_cartes_enigmes.end(), id_carte_enigme)) // si la carte n'est pas une carte énigme
  {
    // affichage pop-up du style : "Vous tentez de répondre à une carte énigme qui n'existe pas"
    return;
  }
  if(enigme(id_carte_enigme).code_correct(val))
  {
    // affichage pop-up du style : "Bonne réponse !"
    // afficher la carte qui est debloquée par l'enigme (sauf pour le pied de biche --> ajouter condition compteur pour vérifier que le mec ait tout regardé dans le garage)
    // affichage_carte(enigme(id_carte_enigme).get_id_cart_debloquee()); // afficher carte dans la fenêtre graphique et faire les modifications qui vont avec

  }
  else
  {
    if(enigme(id_carte_enigme).get_nb_essais()>0) // s'il reste encore des tentatives en stock on affiche un message
    {
      // affichage pop-up du style : "Réponse fausse ... Vous avez encore X tentatives pour résoudre cette énigme" avec X=enigme(id_carte_enigme).get_nb_essais()
    }
    else // il ne reste plus aucune chance de tenter l'énigme
    {
      // affichage pop-up du style : "Réponse fausse ... Vous avez épuisé le nombre de tentatives pour cette énigme, vous avez perdu ... "
    }
  }

}



void Jeu::combinaison_valide(int id_obj_1, int id_obj_2) const
{
  if(!std::count(_id_cartes_objets.begin(), _id_cartes_objets.end(), id_obj_1) || !std::count(_id_cartes_objets.begin(), _id_cartes_objets.end(), id_obj_2)) // si au moins l'un des objets n'existe pas 
  {
    // affichage pop-up du type : "1 des objets n'existe pas"
    return;
  }
  if(std::count(_inventaire.begin(), _inventaire.end(), id_obj_1) && std::count(_inventaire.begin(), _inventaire.end(), id_obj_2))
  {
    if(objet(id_obj_1).id_obj_est_combinable(id_obj_2)) // si les 2 objets sont bien combinables
    {
      // afficher la carte qui résulte de la combinaison
      // affichage_carte(objet(id_obj_1).get_id_objets_combinables()[id_obj_2]); // afficher carte dans la fenêtre graphique et faire les modifications qui vont avec

    }
    // affichage pop-up du type : "les 2 objets ne sont pas combinables"
  }
  // affichage pop-up du type : "Au moins 1 des 2 objets ne se situe pas dans l'inventaire"
}




//Fenetre kick les cartes,
