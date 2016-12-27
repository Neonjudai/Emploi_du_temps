#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../lib/horaire.h"

const int NUM_SEMAINE=2%52;
const int NUM_HEURE=8%4;
const int NUM_JOUR=1%7;


TEST_CASE ("Les horaires sont bien construites", "[horaire]")
{
	horaire h1{NUM_SEMAINE, NUM_JOUR, NUM_HEURE};
	SECTION("Le numéro de semaine, le numéro de jour et le numéro d'heure sont correctes")
    {
		REQUIRE(h1.semaine()==NUM_SEMAINE);
		REQUIRE(h1.heure()==NUM_HEURE);
		REQUIRE(h1.jour()==NUM_JOUR);
	}
	horaire h2{h1};
	SECTION("Le numéro de semaine, le numéro de jour et le numéro d'heure sont correctes")
    {
		REQUIRE(h2.semaine()== h1.semaine());
		REQUIRE(h2.jour()==h1.jour());
		REQUIRE(h2.heure()==h1.heure());
	}
}

TEST_CASE ("Changement paramètres horaires", "[horaire]")
{
	int numSemaine = 3%52;
	int numJour = 4%7;
	int numHeure = 9%4;
	horaire h1{NUM_SEMAINE, NUM_JOUR, NUM_HEURE};
	h1.changerSemaine(numSemaine);
	SECTION("Changer numéro semaine")
    {
		REQUIRE(h1.semaine()==numSemaine);
	}
	horaire h2{NUM_SEMAINE, NUM_JOUR, NUM_HEURE};
	h2.changerJour(numJour);
	SECTION("Changer numéro jour")
    {
		REQUIRE(h2.jour()== numJour);
	}
	horaire h3{NUM_SEMAINE, NUM_JOUR, NUM_HEURE};
	h3.changerHeure(numHeure);
	SECTION("Changer numéro heure")
    {
		REQUIRE(h3.heure()== numHeure);
	}
}

TEST_CASE ("Opérateurs", "[horaire]")
{
	int numSemaine = 3;
	int numJour = 4;
	int numHeure = 9;
	horaire h1{NUM_SEMAINE, NUM_JOUR, NUM_HEURE};
	horaire h2{numSemaine,numJour, numHeure};
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
	h2.changerSemaine(h1.semaine());
	h2.changerJour(h1.jour());
	h2.changerHeure(h1.heure());
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
