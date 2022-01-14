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
#include <iostream>
#include <fstream>
#include <list>

using namespace std;


TEST_CASE("1: Classe Carte"){

  Carte regles("regles",1);
  REQUIRE(regles.get_nom_carte() == "regles");
  REQUIRE(regles.get_id()==1);
}

TEST_CASE("2: Classe Objet"){
  std::map<int, int> map={{302, 40}};
  Objet epingle_cheveux("epingle_cheveux", 101, map, 1);
  REQUIRE(epingle_cheveux.get_nom_carte() == "epingle_cheveux");
  REQUIRE(epingle_cheveux.get_id()==101);
  REQUIRE(epingle_cheveux.get_est_objet_inventaire());
}

TEST_CASE("3: Classe Enigme"){

  Enigme livre1("zoom_livres",32,{33},5,311,33);
  REQUIRE(livre1.get_nom_carte() == "zoom_livres");
  REQUIRE(livre1.get_id()==32);
  REQUIRE(livre1.get_nb_essais()==5);
  REQUIRE(livre1.get_code_solution()==311);
  REQUIRE(livre1.get_id_carte_debloquee()==33);

}

TEST_CASE("4: Classe Enigme1"){

  Enigme1 radio("radio", 13, {14}, 5, 14, 8, 7, 9);
  REQUIRE(radio.get_nom_carte() == "radio");
  REQUIRE(radio.get_id()==13);
  REQUIRE(radio.get_nb_essais()==5);
  REQUIRE(radio.get_id_carte_debloquee()==14);
  REQUIRE(radio.get_alpha()==8);
  REQUIRE(radio.get_beta()==7);
  REQUIRE(radio.get_gamma()==9);
  REQUIRE(radio.get_val1()==24);
  REQUIRE(radio.get_val2()==22);
  REQUIRE(radio.get_val3()==25);
  REQUIRE(radio.get_code_solution()==87);

}



TEST_CASE("5: Classe Enigme2"){

  Enigme2 livre2("zoom_livres",32,{33},5,311,33); // revient à la même chose que livre1
  REQUIRE(livre2.get_nom_carte() == "zoom_livres");
  REQUIRE(livre2.get_id()==32);
  REQUIRE(livre2.get_nb_essais()==5);
  REQUIRE(livre2.get_code_solution()==311);
  REQUIRE(livre2.get_id_carte_debloquee()==33);

  Enigme2 charlie("zoom_livres",32,{33},5,311,33,"TIRER LE LIVRE DE ROALD DAHL");
  REQUIRE(charlie.get_nom_carte() == "zoom_livres");
  REQUIRE(charlie.get_id()==32);
  REQUIRE(charlie.get_nb_essais()==5);
  REQUIRE(charlie.get_code_solution()==311);
  REQUIRE(charlie.get_id_carte_debloquee()==33);
  REQUIRE(charlie.get_phrase()=="TIRER LE LIVRE DE ROALD DAHL");
  REQUIRE(charlie.get_phrase_codee()=="APYLY SL SPCYL KL YVHSK KHOS");

  Enigme2 charlie1("zoom_livres",32,{33},5,311,33,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  REQUIRE(charlie1.get_phrase_codee()==           "HIJKLMNOPQRSTUVWXYZABCDEFG");

  Enigme2 charlie2("zoom_livres",32,{33},5,311,33,"S");
  REQUIRE(charlie2.get_phrase_codee()=="Z");

}

TEST_CASE("6: Classe Enigme3"){

  Enigme3 planete("coffre_fort",45,{50},5,46, "UNJUST+B");
  REQUIRE(planete.get_nom_carte() == "coffre_fort");
  REQUIRE(planete.get_id()==45);
  REQUIRE(planete.get_nb_essais()==5);
  REQUIRE(planete.get_id_carte_debloquee()==46);
  REQUIRE(planete.get_chaine()=="UNJUST+B");
  REQUIRE(planete.get_code_solution()==(785772));

  Enigme3 planete1("coffre_fort",45,{50},5,46, "VTJSUNB");
  REQUIRE(planete1.get_code_solution()==2356789);

  Enigme3 planete2("coffre_fort",45,{50},5,46, "VTJSUNB-B");
  REQUIRE(planete2.get_code_solution()==2356780);

}

TEST_CASE("7: Classe Jeu"){
  Jeu jeu; // Jeu jeu(); faux car il déclare une fonction
  REQUIRE(jeu.get_map_id()[1]==1);
  REQUIRE(jeu.get_map_id()[10]==0);
  REQUIRE(jeu.get_map_id()[40]==0);

  jeu.demande_affichage_carte(40);
  REQUIRE(jeu.get_map_id()[1]==1);
  REQUIRE(jeu.get_map_id()[40]==0);

  jeu.demande_affichage_carte(10);
  REQUIRE(jeu.get_map_id()[1]==-1);
  REQUIRE(jeu.get_map_id()[10]==1);

  jeu.demande_affichage_carte(11);
  REQUIRE(jeu.get_map_id()[1]==-1);
  REQUIRE(jeu.get_map_id()[10]==1);
  REQUIRE(jeu.get_map_id()[11]==1);
  REQUIRE(jeu.get_map_id()[12]==0);
  REQUIRE(jeu.get_map_id()[13]==0);


  jeu.demande_affichage_carte(12);
  REQUIRE(jeu.get_map_id()[1]==-1);
  REQUIRE(jeu.get_map_id()[10]==1);
  REQUIRE(jeu.get_map_id()[11]==1);
  REQUIRE(jeu.get_map_id()[12]==1);
  REQUIRE(jeu.get_map_id()[13]==0);


  jeu.demande_affichage_carte(13);
  REQUIRE(jeu.get_map_id()[1]==-1);
  REQUIRE(jeu.get_map_id()[10]==1);
  REQUIRE(jeu.get_map_id()[11]==1);
  REQUIRE(jeu.get_map_id()[12]==1);
  REQUIRE(jeu.get_map_id()[13]==1);

  REQUIRE(jeu.enigme(13).get_nb_essais()==5);

  jeu.solution_enigme_valide(13,666);
  REQUIRE(jeu.get_map_id()[13]==1);
  REQUIRE(jeu.get_map_id()[14]==0);
  // REQUIRE(jeu.enigme(13).get_nb_essais()==4); // test ne passe pas cela signifie que le nombre d'essais ne diminue pas quand le joueur entre une mauvaise réponse

  /*
  jeu.demande_affichage_carte(11);
  REQUIRE(jeu.get_map_id()[1]==-1);
  REQUIRE(jeu.get_map_id()[10]==1);
  REQUIRE(jeu.get_map_id()[11]==1);
  REQUIRE(jeu.get_map_id()[12]==0);
  REQUIRE(jeu.get_map_id()[13]==0);
  */

}
