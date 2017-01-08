
/**
 * @file TestProfesseur.cpp
 * @brief Fichier permettant de tester les methodes de la classe professeur
 * @author Olivier Ettlin
 * @version 1.0
 */


#include "../lib/catch.hpp"
#include "../lib/professeur.h"


using std::string;

const string NOM_PROFESSEUR="Dupont";


TEST_CASE ("Construction des professeurs", "[professeur]")
{
    professeur p1{NOM_PROFESSEUR};
    REQUIRE(p1.nom()==NOM_PROFESSEUR);
}
/**< Tests verifiant la construction des professeurs */
