// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "jeu.hh"
#include "carte.hh"
#include "objet.hh"
#include "enigme.hh"
#include "enigme1.hh"
#include "enigme2.hh"
#include "enigme3.hh"
#include "Fenetre.hh"
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

TEST_CASE("1: Classe Carte") {
  Carte regles("regles",1);
  REQUIRE(regles.get_nom_carte() == "regles");
  REQUIRE(regles.get_id() == 1);
}

TEST_CASE("2: Classe Objet") {
  std::map<int, int> map={{302, 40}};
  Objet epingle_cheveux("epingle_cheveux", 101, map, 1);
  REQUIRE(epingle_cheveux.get_nom_carte() == "epingle_cheveux");
  REQUIRE(epingle_cheveux.get_id() == 101);
  REQUIRE(epingle_cheveux.get_est_objet_inventaire());
}

TEST_CASE("3: Classe Enigme") {
  Enigme livre1("zoom_livres",32,{33},5,311,33);
  REQUIRE(livre1.get_nom_carte() == "zoom_livres");
  REQUIRE(livre1.get_id() == 32);
  REQUIRE(livre1.get_nb_essais() == 5);
  REQUIRE(livre1.get_code_solution() == 311);
  REQUIRE(livre1.get_id_carte_debloquee() == 33);

}

TEST_CASE("4: Classe Enigme1") {
  Enigme1 radio("radio", 13, {14}, 5, 14, 8, 7, 9);
  REQUIRE(radio.get_nom_carte() == "radio");
  REQUIRE(radio.get_id() == 13);
  REQUIRE(radio.get_nb_essais() == 5);
  REQUIRE(radio.get_id_carte_debloquee() == 14);
  REQUIRE(radio.get_alpha() == 8);
  REQUIRE(radio.get_beta() == 7);
  REQUIRE(radio.get_gamma() == 9);
  REQUIRE(radio.get_val1() == 24);
  REQUIRE(radio.get_val2() == 22);
  REQUIRE(radio.get_val3() == 25);
  REQUIRE(radio.get_code_solution() == 87);

}

TEST_CASE("5: Classe Enigme2") {
  Enigme2 livre2("zoom_livres",32,{33},5,311,33); // revient à la même chose que livre1
  REQUIRE(livre2.get_nom_carte() == "zoom_livres");
  REQUIRE(livre2.get_id() == 32);
  REQUIRE(livre2.get_nb_essais() == 5);
  REQUIRE(livre2.get_code_solution() == 311);
  REQUIRE(livre2.get_id_carte_debloquee() == 33);

  Enigme2 charlie("zoom_livres",32,{33},5,311,33,"TIRER LE LIVRE DE ROALD DAHL");
  REQUIRE(charlie.get_nom_carte() == "zoom_livres");
  REQUIRE(charlie.get_id() == 32);
  REQUIRE(charlie.get_nb_essais() == 5);
  REQUIRE(charlie.get_code_solution() == 311);
  REQUIRE(charlie.get_id_carte_debloquee() == 33);
  REQUIRE(charlie.get_phrase() == "TIRER LE LIVRE DE ROALD DAHL");
  REQUIRE(charlie.get_phrase_codee() == "APYLY SL SPCYL KL YVHSK KHOS");

  Enigme2 charlie1("zoom_livres",32,{33},5,311,33,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  REQUIRE(charlie1.get_phrase_codee() ==           "HIJKLMNOPQRSTUVWXYZABCDEFG");

  Enigme2 charlie2("zoom_livres",32,{33},5,311,33,"S");
  REQUIRE(charlie2.get_phrase_codee() == "Z");

}

TEST_CASE("6: Classe Enigme3") {
  Enigme3 planete("coffre_fort",45,{50},5,46, "UNJUST+B");
  REQUIRE(planete.get_nom_carte() == "coffre_fort");
  REQUIRE(planete.get_id() == 45);
  REQUIRE(planete.get_nb_essais() == 5);
  REQUIRE(planete.get_id_carte_debloquee() == 46);
  REQUIRE(planete.get_chaine() == "UNJUST+B");
  REQUIRE(planete.get_code_solution() == (785772));

  Enigme3 planete1("coffre_fort",45,{50},5,46, "VTJSUNB");
  REQUIRE(planete1.get_code_solution() == 2356789);

  Enigme3 planete2("coffre_fort",45,{50},5,46, "VTJSUNB-B");
  REQUIRE(planete2.get_code_solution() == 2356780);

}


TEST_CASE("7: Classe Jeu (et constructeur FenetreJeu)") {
		
  cout << endl << "-------------------------------------------------------------------------" << endl;
  cout << "     7 - CLASSE JEU : IL FAUT FERMER LES FENETRES GRAPHIQUES" << endl;
  cout << "-------------------------------------------------------------------------" << endl << endl;

	
  Gtk::Main app;
  FenetreJeu fenetre; //il faut fermer la fenetre graphique qui apparait
  //Fenetre a un attribut Jeu* Game, les tests sont effectués sur celle-ci a l'aide du getter get_Game()
	
  REQUIRE(fenetre.get_Game()->get_map_id()[1]==1);
  REQUIRE(fenetre.get_Game()->get_map_id()[10]==0);
  REQUIRE(fenetre.get_Game()->get_map_id()[40]==0);

  fenetre.get_Game()->demande_affichage_carte(40);
  REQUIRE(fenetre.get_Game()->get_map_id()[1]==1);
  REQUIRE(fenetre.get_Game()->get_map_id()[40]==0);

  fenetre.get_Game()->demande_affichage_carte(10);
  REQUIRE(fenetre.get_Game()->get_map_id()[1]==-1);
  REQUIRE(fenetre.get_Game()->get_map_id()[10]==1);

  fenetre.get_Game()->demande_affichage_carte(11);
  REQUIRE(fenetre.get_Game()->get_map_id()[1]==-1);
  REQUIRE(fenetre.get_Game()->get_map_id()[10]==1);
  REQUIRE(fenetre.get_Game()->get_map_id()[11]==1);
  REQUIRE(fenetre.get_Game()->get_map_id()[12]==0);
  REQUIRE(fenetre.get_Game()->get_map_id()[13]==0);


  fenetre.get_Game()->demande_affichage_carte(12);
  REQUIRE(fenetre.get_Game()->get_map_id()[1]==-1);
  REQUIRE(fenetre.get_Game()->get_map_id()[10]==1);
  REQUIRE(fenetre.get_Game()->get_map_id()[11]==1);
  REQUIRE(fenetre.get_Game()->get_map_id()[12]==1);
  REQUIRE(fenetre.get_Game()->get_map_id()[13]==0);


  fenetre.get_Game()->demande_affichage_carte(13);
  REQUIRE(fenetre.get_Game()->get_map_id()[1]==-1);
  REQUIRE(fenetre.get_Game()->get_map_id()[10]==1);
  REQUIRE(fenetre.get_Game()->get_map_id()[11]==1);
  REQUIRE(fenetre.get_Game()->get_map_id()[12]==1);
  REQUIRE(fenetre.get_Game()->get_map_id()[13]==1);
	
  fenetre.get_Game()->demande_affichage_carte(101);

  REQUIRE(fenetre.get_Game()->enigme(13).get_nb_essais()==5);

  fenetre.get_Game()->solution_enigme_valide(13,666);
  REQUIRE(fenetre.get_Game()->get_map_id()[13]==1);
  REQUIRE(fenetre.get_Game()->get_map_id()[14]==0);

  fenetre.get_Game()->solution_enigme_valide(13,87);
  REQUIRE(fenetre.get_Game()->get_map_id()[13]==-1);


  fenetre.get_Game()->demande_affichage_carte(15);
  REQUIRE(fenetre.get_Game()->get_map_id()[13]==-1);
  REQUIRE(fenetre.get_Game()->get_map_id()[14]==-1);
  REQUIRE(fenetre.get_Game()->get_map_id()[15]==1);

  fenetre.get_Game()->demande_affichage_carte(16);
  REQUIRE(fenetre.get_Game()->get_map_id()[13]==-1);
  REQUIRE(fenetre.get_Game()->get_map_id()[14]==-1);
  REQUIRE(fenetre.get_Game()->get_map_id()[15]==-1);
  REQUIRE(fenetre.get_Game()->get_map_id()[16]==1);

  fenetre.get_Game()->demande_affichage_carte(17);
  REQUIRE(fenetre.get_Game()->get_map_id()[20]==-1);
  REQUIRE(fenetre.get_Game()->get_map_id()[17]==1);
}


TEST_CASE("8: Widgets") {
	
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "     8 - WIDGETS : IGNORER LES CRITICAL ET WARNING DE GTK" << endl;
	cout << "     => ILS SONT JUSTE DUS AU NON-PLACEMENT DES WIDGETS DANS UNE FENETRE" << endl;
	cout << "-------------------------------------------------------------------------" << endl << endl;
	
	Image about("Images/about.png");
	REQUIRE(about.get_name() == "Images/about.png");
	
	
	BoutonCarte bouton_about(about);
	REQUIRE(bouton_about.get_column() == -1);
	REQUIRE(bouton_about.get_line() == -1);
	
	bouton_about.set_column(4);
	bouton_about.set_line(5);
	REQUIRE(bouton_about.get_column() == 4);
	REQUIRE(bouton_about.get_line() != -1);
	
	REQUIRE(bouton_about.get_name() == "about");
	REQUIRE(bouton_about.get_name_big_image() == "Images/about_big.jpg");
	bool rep = (bouton_about == "about");
	REQUIRE(rep);
	rep = (bouton_about == "nope");
	REQUIRE(!rep);

	
	BoutonTexte texte("Super bouton");
	REQUIRE(texte.get_name() == "no name");
	
	Image about2("Images/about.png");
	BoutonAccueil accueil(about2);
	REQUIRE(accueil.get_name() == "Images/about.png");
	
	cout << endl << "-------------------------------------------------------------------------" << endl;
	cout << "     8 - WIDGETS : IGNORER LES CRITICAL ET WARNING DE GTK" << endl;
	cout << "     => ILS SONT JUSTE DUS AU NON-PLACEMENT DES WIDGETS DANS UNE FENETRE" << endl;
	cout << "-------------------------------------------------------------------------" << endl << endl;
	
	REQUIRE(1 == 1);
}

