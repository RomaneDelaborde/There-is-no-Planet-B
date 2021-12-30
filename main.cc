# include <iostream>
# include <string>
#include "jeu.hh"
#include "carte.hh"
#include "objet.hh"
#include "enigme.hh"
#include "enigme1.hh"
#include "enigme2.hh"
#include "enigme3.hh"

int main()
{
  Carte regles("regles.jpeg",0);
  std::cout << "Nom de la carte : " << regles.get_nom_carte() << std::endl;
  std::cout << "Id de la carte : " << regles.get_id() << std::endl;

  return 0;
}
