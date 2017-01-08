
/**
 * @file TestSalle.cpp
 * @brief Fichier permettant de tester les methodes de la classe salle
 * @author Olivier Ettlin
 * @version 1.0
 */


#include "../lib/catch.hpp"
#include "../lib/salle.h"


using std::string;

const string NOM_SALLE="b2";
const int TAILLE_SALLE=40;


TEST_CASE ("Construction des salles", "[salle]")
{
    salle s1{NOM_SALLE,TAILLE_SALLE};
    REQUIRE(s1.nom()==NOM_SALLE);
    REQUIRE(s1.nombrePlaces()==TAILLE_SALLE);

}
/**< Tests verifiant la construction des salles */

TEST_CASE ("Changement paramètres salle", "[salle]")
{
    salle s1{NOM_SALLE,TAILLE_SALLE};
    int taille=5;
    s1.changerNombrePlaces(taille);
    REQUIRE(s1.nombrePlaces()==5);

}
/**< Tests verifiant le changement de parametres des salles */
