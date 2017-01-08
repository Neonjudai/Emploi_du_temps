
/**
* @file TestRessource.cpp
* @brief Fichier permettant de tester les methodes de la classe ressource
* @author Hicham Chouhad
* @version 1.0
*/


#include "../lib/catch.hpp"
#include "../lib/ressource.h"


TEST_CASE("Construction d'une ressource", "[ressource]")
{
	std::string nom = "nom de ressource";
	ressource r1{ nom };
	SECTION("Construction avec variable en parametre")
	{
		REQUIRE(r1.nom() == nom);
	}

	ressource r2{ r1 };
	SECTION("Construction par recopie")
	{
		REQUIRE(r2.nom() == r1.nom());
	}
}
/** Tests sur les constructeurs */

TEST_CASE("Modification de variable", "[ressource]")
{
	std::string nom1 = "Un nom de ressource";
	std::string nom2 = "Un autre nom de ressource";

	ressource r{ nom1 };
	r.changernom(nom2);
	SECTION("Modification du nom")
	{
		REQUIRE(r.nom() == nom2);
	}
}
/** Tests sur la modification du nom */

TEST_CASE("Operateur egal", "[ressource]")
{
	std::string nom1 = "Un nom de ressource";
	std::string nom2 = "Un autre nom de ressource";

	ressource r1{ nom1 };
	ressource r2{ nom2 };

	SECTION("Comparaison entre deux ressources")
	{
		REQUIRE_FALSE(r1 == r2);
		r2.changernom(nom1);
		REQUIRE(r1 == r2);
	}
}
/** Tests sur l'operateur egal */
