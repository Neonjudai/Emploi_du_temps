
/**
* @file TestFormation.cpp
* @brief Fichier permettant de tester les methodes de la classe formation
* @author Hicham Chouhad
* @version 1.0
*/


#include "../lib/catch.hpp"
#include "../lib/formation.h"


TEST_CASE("Construction d'une formation", "[formation]")
{
	string nomDeFormation	= "Licence 3 MIAGE";
	int nombreDEtudiants = 35;
	formation f1{nomDeFormation, nombreDEtudiants};

	SECTION("Construction d'une formation avec variables en parametres")
	{
		REQUIRE(f1.nom()			== nomDeFormation);
		REQUIRE(f1.nombreEtudiant() == nombreDEtudiants);
	}

	formation f2{ f1 };
	SECTION("Constructeur par recopie")
	{
		REQUIRE(f2.nom()			== f1.nom());
		REQUIRE(f2.nombreEtudiant() == f1.nombreEtudiant());
	}
}
/** Tests sur le constructeur */


TEST_CASE("Modification de variable dans une formation", "[formation]")
{
	string nomFormation1 = "Licence 3 MIAGE";
	string nomFormation2 = "Licence 3 INFO";

	int nombreDEtudiants1 = 17;
	int nombreDEtudiants2 = 25;

	formation f{ nomFormation1, nombreDEtudiants1 };

	f.changernom(nomFormation2);
	SECTION("Modification du nom")
	{
		REQUIRE(f.nom() == nomFormation2);
	}

	f.changerNombreEtudiant(nombreDEtudiants2);
	SECTION("Modification du nombre d'etudiant")
	{
		REQUIRE(f.nombreEtudiant() == nombreDEtudiants2);
	}
}
/** Tests sur les modifications de variables prives */
