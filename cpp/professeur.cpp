#include "../lib/professeur.h"

professeur::professeur(string nom):ressource{nom}
{
}

std::ostream& operator<<(std::ostream & ost, const professeur & p)
{
	ost<<p.nom();
	return ost;
}
