#include "enigme.hh"

void Enigme::affichage_info_carte() const {
  std::cout << "Nom carte : " << _nom_carte << std::endl;
  std::cout << "Id : " << _id << std::endl;

  std::cout << "Id cartes kick : ";
  for (std::size_t i=0; i<_id_cartes_kick.size();i++) {std::cout << _id_cartes_kick[i] << ' ';}

  std::cout << std::endl << "Nb d'essais : " << _nb_essais << std::endl;
  std::cout << "Code solution : " << _code_solution << std::endl;
  std::cout << "Carte débloquée : " << _id_carte_debloquee << std::endl;

  std::cout << std::endl << std::endl;
}

bool Enigme::code_correct(int val) {
  if (val ==_code_solution) {return 1;}  // le joueur a bon, on renvoie 0
  // sinon le joueur a faux et on diminue le nombre de chances qu'il lui reste pour répondre juste à l'éngime
  _nb_essais--; // checker ici ou dans la fonction de Jeu si le _nb_essais n'est pas négatif + messages d'erreurs/pop-up

  return 0;
}

void Enigme::calcul_solution_enigme(){};
