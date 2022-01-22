#include "enigme1.hh"

Enigme1::Enigme1(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int id_carte_debloquee, int alpha, int beta, int gamma):Enigme(nom_carte, id, id_cartes_kick, nb_essais, id_carte_debloquee), _alpha(alpha), _beta(beta), _gamma(gamma) {
  _val1=3*_alpha;
  _val2=2*_beta+_alpha;
  _val3=2*_gamma+_beta;

  _code_solution=_alpha*10+_beta; // modifier ici si on veut une autre réponse à l'énigme
}

//alpha = 8
//beta = 7
//gamma = 9
//solution = 87
