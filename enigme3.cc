#include "enigme3.hh"

Enigme3::Enigme3(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int id_carte_debloquee, std::string chaine):Enigme(nom_carte, id, id_cartes_kick, nb_essais, id_carte_debloquee), _chaine(chaine){
  _lettres= {{'V', 2}, {'T', 3}, {'J', 5}, {'S', 6}, {'U', 7}, {'N', 8}, {'B', 9}}; // création du map _lettres
  codage_chaine_planete();
}

bool Enigme3::lettre_existe(char l) const // l pour lettre
{
  if(_lettres.find(l)==_lettres.end()) // si la lettre l n'existe pas dans les clés de _lettres
  {
    //std::cout << "ERREUR : la lettre entrée en paramètres n'existe pas dans les clés de _lettres" << std::endl;
    return 0;
  }
  return 1; // sinon tout va bien, elle existe et on renvoie 1
}


int Enigme3::codage_mot_planete(std::string mot)
{
  int code=0; // initialisation du code du mot à la valeur 0
  int z=pow(10,mot.length()-1); // pour pouvoir faire le décalage des puissances de 10 dans le code

  for(std::string::size_type i=0; i<mot.length(); i++) // pour chaque lettre du mot
  {
      if(!lettre_existe(mot[i])) // si la lettre n'existe pas on renvoie -1
      {
          return -1;
      }
      code+=z*_lettres[mot[i]]; // sinon on ajoute le chiffre correspondant à la lettre (donné par _lettres) dans le mot codé
      z=z/10;                   // divison par 10 pour passer à la puissance inférieure
  }
  return code;
}


void Enigme3::codage_chaine_planete()
{
  _code_solution=0; // initialisation du code de _chaine à la valeur 0

  // Lecture de la _chaine avec des délimiteurs
  std::string const delims{ "-+" }; // délimiteurs

  size_t beg, pos = 0;
  while ((beg = _chaine.find_first_not_of(delims, pos)) != std::string::npos) // parcours de la _chaine
  {
    pos = _chaine.find_first_of(delims, beg + 1);

    if(beg==0) // codage pour le premier mot
    {
        _code_solution+=codage_mot_planete(_chaine.substr(beg, pos - beg));
    }
    else // codage pour les potentiels mots suivants
    {
      if(_chaine[pos]== '+' || pos== std::string::npos) // on somme si on tombe sur un signe +
      {
          _code_solution+=codage_mot_planete(_chaine.substr(beg, pos - beg));
      }
      else if(_chaine[pos]== '-' || pos== std::string::npos) // on soustrait si on tombe sur un signe -
      {
          _code_solution-=codage_mot_planete(_chaine.substr(beg, pos - beg));
      }
    }
  }
}
