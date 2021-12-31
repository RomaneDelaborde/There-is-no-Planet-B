#include "enigme3.hh"

Enigme3::Enigme3(std::string nom_carte, int id, int nb_essais, std::string chaine):Enigme(nom_carte, id, nb_essais), _chaine(chaine) // mettre Enigme::Enigme ou pas ??
{
  _lettres= {{'V', 2}, {'T', 3}, {'J', 5}, {'S', 6}, {'U', 7}, {'N', 8}, {'B', 9}}; // this-> nécessaire ou pas ??
}

bool Enigme3::lettre_existe(char l) const // l pour lettre
{
  if(_lettres.find(l)==_lettres.end()) // si lettre n'existe pas dans les clés de _lettres
  {
    //std::cout << "ERREUR : la lettre entrée en paramètres n'existe pas dans les clés de _lettres" << std::endl;
    return 0;
  }
  return 1;
}


int Enigme3::codage_mot_planete(std::string mot)
{

  int code=0;
  int z=pow(10,mot.length()-1);

  for(std::string::size_type i=0; i<mot.length(); i++)
  {
      if(!lettre_existe(mot[i]))
      {
          return -1;
      }
      code+=z*_lettres[mot[i]];
      z=z/10;
  }
  return code;
}


void Enigme3::codage_chaine_planete()
{
  _code_solution=0;

  // Lecture de la _chaine avec des délimiteurs
  std::string const delims{ "-+" }; // délimiteurs

  size_t beg, pos = 0;
  while ((beg = _chaine.find_first_not_of(delims, pos)) != std::string::npos)
  {
    pos = _chaine.find_first_of(delims, beg + 1);

    if(beg==0)
    {
        _code_solution+=codage_mot_planete(_chaine.substr(beg, pos - beg));
    }

    if(_chaine[pos]== '+')
    {
        _code_solution+=codage_mot_planete(_chaine.substr(beg, pos - beg));
    }
    else if(_chaine[pos]== '-')
    {
        _code_solution-=codage_mot_planete(_chaine.substr(beg, pos - beg));
    }
  }
}
