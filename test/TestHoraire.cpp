#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../lib/horaire.h"

const int NUM_SEMAINE=2;
const int NUM_HEURE=8;


//Suites de tests

TEST_CASE ("Les horaires sont bien construites", "[horaire]")
{
	horaire h1{NUM_SEMAINE, NUM_HEURE};
	SECTION("Le numéro de semaine et le numéro d'heure sont correctes")
    {
		REQUIRE(h1.numeroSemaine()==NUM_SEMAINE);
		REQUIRE(h1.numeroHeure()==NUM_HEURE);
	}
	horaire h2{h1};
	SECTION("Le numéro de semaine et le numéro d'heure sont correctes")
    {
		REQUIRE(h2.numeroSemaine()== h1.numeroSemaine());
		REQUIRE(h2.numeroHeure()==h1.numeroHeure());
	}
}

TEST_CASE ("Changement paramètres horaires", "[horaire]")
{
	int numSemaine = 3;
	int numHeure = 9;
	horaire h1{NUM_SEMAINE, NUM_HEURE};
	h1.changerSemaine(numSemaine);
	SECTION("Changer numéro semaine")
    {
		REQUIRE(h1.numeroSemaine()==numSemaine);
	}
	horaire h2{NUM_SEMAINE, NUM_HEURE};
	h2.changernumeroHeure(numHeure);
	SECTION("Changer numéro heure")
    {
		REQUIRE(h2.numeroHeure()== numHeure);
	}
}

TEST_CASE ("Opérateurs", "[horaire]")
{
	int numSemaine = 3;
	int numHeure = 9;
	horaire h1{NUM_SEMAINE, NUM_HEURE};
	horaire h2{numSemaine, numHeure};
	bool verif1= h1.operator<(h2);
	SECTION("Operateur <")
    {
		REQUIRE(verif1==true);
	}
	bool verif2= h1.operator>(h2);
	SECTION("Operateur >")
    {
		REQUIRE(verif2==false);
	}
	h2.changerSemaine(h1.numeroSemaine());
	h2.changernumeroHeure(h1.numeroHeure());
	bool verif3= h1.operator==(h2);
	SECTION("Operateur ==")
    {
		REQUIRE(verif3==true);
	}
	bool verif4= h1.operator<=(h2);
	SECTION("Operateur <=")
    {
		REQUIRE(verif4==true);
	}
	bool verif5= h1.operator>=(h2);
	SECTION("Operateur >=")
    {
		REQUIRE(verif5==true);
	}
}
