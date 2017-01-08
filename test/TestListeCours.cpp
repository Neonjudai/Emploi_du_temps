/**
* @file TestListeCours.cpp
* @brief Fichier permettant de tester les methodes de la classe listeCours
* @author Hicham Chouhad
* @version 1.0
*/

#include "../lib/catch.hpp"
#include "../lib/listeCours.h"

TEST_CASE("Modification dans listeCours", "[listeCours]")
{
	listeCours lc;
	int semaine = 10, jour = 3, heure = 2, capaciteSalle = 35, nombreEtudiant = 20;
	string nomProfesseur = "Dupond", nomSalle = "100", nomFormation = "L3";
	horaire h{ semaine, jour, heure };
	professeur * p = new professeur{nomProfesseur};
	salle * s = new salle{ nomSalle, capaciteSalle };
	formation * f = new formation{ nomFormation, nombreEtudiant };

	cours c{ h, p, s, f };


	lc.ajouterUnCours(c);
	SECTION("Ajout de cours")
	{
		REQUIRE(lc.estPossible(c) != 0);
		REQUIRE(lc.nombreDeCours() > 0);
		REQUIRE(lc.coursNumero(0).formationDuCours()	== c.formationDuCours());
		REQUIRE(lc.coursNumero(0).horaireDuCours()		== c.horaireDuCours());
		REQUIRE(lc.coursNumero(0).professeurDuCours()	== c.professeurDuCours());
		REQUIRE(lc.coursNumero(0).salleDuCours()	== c.salleDuCours());
	}

	int numCours = lc.numeroDeCours(c.horaireDuCours(), c.professeurDuCours(), c.salleDuCours(), c.formationDuCours());
	lc.supprimerUnCours(numCours);

	SECTION("Suppression de cours")
	{
		REQUIRE(lc.nombreDeCours() == 0);
	}

}
/** Tests sur l'ajout et suppression de cours, tout en verifiant s'ils sont possible */