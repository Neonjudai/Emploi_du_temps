#include "cours.h"

cours::cours(const horaire & h, professeur p):d_horaire{h},d_professeur{&p}
{}

cours::cours(int semaine, int heure, professeur p):d_horaire{semaine,heure},d_professeur{&p}
{}

cours::cours(const cours & c):d_horaire{c.d_horaire},d_professeur{c.d_professeur}
{}

cours::~cours(){//inutile, listeRessource s'occupe des deletes.
	//delete d_professeur;
}

void cours::direConsole(std::ostream & ost)
{//Ecrire differement
	ost<<"Cours semaine "<<d_horaire.numeroSemaine()<<" a "<<d_horaire.numeroHeure()<<" avec "<<d_professeur->nom()<<std::endl;
}
