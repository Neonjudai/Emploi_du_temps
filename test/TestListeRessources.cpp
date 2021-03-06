/**
* @file TestListeRessources.cpp
* @brief Fichier permettant de tester les methodes de la classe listeRessources
* @author Hicham Chouhad
* @version 1.0
*/


#include "../lib/catch.hpp"
#include "../lib/listeRessources.h"

TEST_CASE("Tests sur les professeurs", "[listeRessources]")
{
	listeRessources lr;
	string nom = "Dupond";
	professeur p{ nom };

	lr.ajouterUnProfesseur(p);
	SECTION("Ajout d'un professeur")
	{
		REQUIRE(lr.nombreDeProfesseurs() > 0);
		REQUIRE(lr.professeurNumero(0) == p);
	}

	listeCours lc;
	horaire h{ 1, 1, 1 };
	professeur * p1 = new professeur{ p };
	salle * s = new salle{ "37", 37 };
	formation * f = new formation{ "L3", 20 };
	cours c{ h, p1, s, f };

	lc.ajouterUnCours(c);

	SECTION("Verification du professeur ayant un cours")
	{
		REQUIRE(lr.professeurAUnCours(lc, p.nom()));
	}
	lr.supprimerUnProfesseur(p.nom());
	SECTION("Suppression d'un professeur")
	{
		REQUIRE(lr.nombreDeProfesseurs() == 0);
	}
}
/** Tests sur l'ajout et suppression de professeurs */

TEST_CASE("Tests sur les salles", "[listeRessources]")
{
	listeRessources lr;
	string nom = "107";
	int taille = 40;
	salle s{ nom, taille };

	lr.ajouterUneSalle(s);
	SECTION("Ajout d'une salle")
	{
		REQUIRE(lr.nombreDeSalles() > 0);
		REQUIRE(lr.salleNumero(0) == s);
	}

	listeCours lc;
	horaire h{ 1, 1, 1 };
	professeur * p = new professeur{ "Dupond" };
	salle * s1 = new salle{ s };
	formation * f = new formation{ "L3", 20 };
	cours c{ h, p, s1, f };

	lc.ajouterUnCours(c);

	SECTION("Verification de cours ayant lieu dans la salle")
	{
		REQUIRE(lr.salleAUnCours(lc, s.nom()));
	}
	lr.supprimerUneSalle(s.nom());
	SECTION("Suppression d'une salle")
	{
		REQUIRE(lr.nombreDeSalles() == 0);
	}

}
/** Tests sur l'ajout et suppression de salle */

TEST_CASE("Tests sur les formations", "[listeRessources]")
{
	listeRessources lr;
	string nom = "Licence 3";
	int nombreEtudiant = 35;
	formation f{ nom, nombreEtudiant };

	lr.ajouterUneFormation(f);
	SECTION("Ajout d'une formation")
	{
		REQUIRE(lr.nombreDeFormations() > 0);
		REQUIRE(lr.formationNumero(0) == f);
	}

	listeCours lc;
	horaire h{ 1, 1, 1 };
	professeur * p = new professeur{ "Dupond" };
	salle * s = new salle{ "37", 37 };
	formation * f1 = new formation{ f };
	cours c{ h, p, s, f1 };

	lc.ajouterUnCours(c);

	SECTION("Verification du professeur ayant un cours")
	{
		REQUIRE(lr.formationAUnCours(lc, f.nom()));
	}

	lr.supprimerUneFormation(f.nom());
	SECTION("Suppression d'une formation")
	{
		REQUIRE(lr.nombreDeFormations() == 0);
	}
}
/** Tests sur l'ajout et suppression de formation */