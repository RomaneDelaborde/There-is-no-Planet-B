#include "enigme.hh"

bool Enigme::code_correct(int val)
{
  if(val==_code_solution)
  {
    return 1;
  }
  // sinon le joueur a faux et on diminue le nombre de chances qu'il lui reste pour répondre juste à l'éngime
  _nb_essais--; // checker ici ou dans la fonction de Jeu si le _nb_essais n'est pas négatif + messages d'erreurs/pop-up
  return 0;
}
