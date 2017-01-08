
/**
 * @file TestCours.cpp
 * @brief Fichier permettant de tester les methodes de la classe cours
 * @author Olivier Ettlin
 * @version 1.0
 */


#include "../lib/catch.hpp"
#include "../lib/cours.h"

const horaire HORAIRE_COURS {2%52, 8%4,1%7};
professeur * PROFESSEUR_COURS = new professeur{"Dupont"};
formation * FORMATION_COURS = new formation {"Miage",30};
salle * SALLE_COURS = new salle {"b2", 40};

TEST_CASE ("Construction des cours", "[cours]")
{
    cours c1 {HORAIRE_COURS, PROFESSEUR_COURS,SALLE_COURS, FORMATION_COURS};
    SECTION("Vérification de l'horaire, du professeur et de la formation du cours")
    {
		REQUIRE(c1.horaireDuCours()==HORAIRE_COURS);
		REQUIRE(c1.professeurDuCours().nom()==PROFESSEUR_COURS->nom());
		REQUIRE(c1.salleDuCours().nom()==SALLE_COURS->nom());
		REQUIRE(c1.formationDuCours().nom()==FORMATION_COURS->nom());
	}
}
/**< Tests verifiant la construction des cours */
