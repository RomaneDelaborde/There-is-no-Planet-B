#include <iostream>
#include <string>
#include "jeu.hh"
#include "carte.hh"
#include "objet.hh"
#include "enigme.hh"
#include "enigme1.hh"
#include "enigme2.hh"
#include "enigme3.hh"

#include <gtkmm/main.h>
#include "Fenetre.hh"
#include "Widgets.hh"


int main(int argc, char* argv[]) {
  // PENSER A ENREGISTRER MAIN AUTRE PART AVANT DE SUPPRIMER TOUS LES TESTS (peut être utile de jeter un oeil à ces tests)
  /*
  Carte regles("regles.jpeg",0);
  std::cout << "Nom de la carte : " << regles.get_nom_carte() << std::endl;
  std::cout << "Id de la carte : " << regles.get_id() << std::endl << std::endl;

  std::cout << "Nom de la carte : " << Carte("regles.jpeg",0).get_nom_carte() << std::endl;
  std::cout << "Id de la carte : " << Carte("regles.jpeg",0).get_id() << std::endl;

  Carte* test = new Carte("regles.jpeg",0);
  std::cout << "Nom de la carte : " << test->get_nom_carte() << std::endl;
  std::cout << "Id de la carte : " << test->get_id() << std::endl << std::endl;

  delete test;
  */
  // _cartes_jeu[i]=new Carte(paramètres)
  /*
  Enigme2 charlie("zoom_livres",32,{33},5,311,33,"TIRER LE LIVRE DE ROALD DAHL");
  charlie.codage_jules_cesar(7,1);
  std::cout << charlie.get_phrase() << std::endl;
  std::cout << charlie.get_phrase_codee() << std::endl;


  Enigme3 planete("coffre_fort",45,{50},5,46, "UNJUST+B");
  std::cout << planete.get_chaine << std::endl;
  std::cout << planete.get_code_solution() << std::endl<< std::endl;

  */

  /*
  Jeu test; // Jeu test(); faux car il déclare une fonction
  std::cout << test.solution_enigme_valide(32, 311) << std::endl; // true
  std::cout << test.solution_enigme_valide(32, 312) << std::endl; // false

  std::cout << test.combinaison_realisable(101, 302) << std::endl; // true
  std::cout << test.combinaison_realisable(101, 666) << std::endl;  // false
  */

  //Enigme3 planete2("coffre_fort",45,{50},5,46, "VTJSUNB-B");
  //std::cout << planete2.get_code_solution() << std::endl;


  //Jeu Game;

  Gtk::Main app(argc, argv);

  FenetreAccueil accueil;
  Gtk::Main::run(accueil);

	std::cout << "before" << std::endl;

  FenetreJeu fenetre; //fenetre lance un Jeu() dans son constructeur
  Gtk::Main::run(fenetre);

  //std::cout << "ignbkj" << std::endl;

  return 0;

}



//int tab[5] = {0, 1, 2, 3, 4};
//tab[0] == 0

//list[i] = new Carte(....)
