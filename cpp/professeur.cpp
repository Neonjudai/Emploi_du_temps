#include "../lib/professeur.h"
#include "../lib/afficheurConsole.h"

professeur::professeur(string nom):ressource{nom}
{
}


std::ostream& operator<<(std::ostream & ost, const professeur & p)
{
    afficheurConsole aff;
    professeur *p2= new professeur (p);
    aff.afficheProfesseur(p2,ost);
    delete p2;
	return ost;
}
