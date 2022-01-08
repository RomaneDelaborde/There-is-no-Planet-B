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

}

TEST_CASE("6: Classe Enigme3"){

}

TEST_CASE("7: Classe Enigme3"){

}
