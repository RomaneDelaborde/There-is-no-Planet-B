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


TEST_CASE("1: TEST"){
  Carte c("coucou",10);
  REQUIRE(c.get_nom_carte() == "coucou");
  REQUIRE(c.get_id()==10);
}
