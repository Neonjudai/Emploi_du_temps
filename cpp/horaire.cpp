#include "../lib/horaire.h"

horaire::horaire(int numeroSemaine, int numeroHeure):d_numeroSemaine{numeroSemaine},d_numeroHeure{numeroHeure},d_professeur{0},d_formation{0},d_salle{0}
{}

horaire::horaire(const horaire & unHoraire):d_numeroSemaine{unHoraire.d_numeroSemaine},d_numeroHeure{unHoraire.d_numeroHeure},d_professeur{unHoraire.d_professeur},d_formation{unHoraire.d_formation},d_salle{unHoraire.d_salle}
{}

void horaire::changerSemaine(int numeroSemaine)		{d_numeroSemaine=numeroSemaine;}
void horaire::changernumeroHeure(int numeroHeure) 	{d_numeroHeure=numeroHeure;}

int 		horaire::numeroSemaine()const {return d_numeroSemaine;}
int 		horaire::numeroHeure() 	const {return d_numeroHeure;}
professeur*	horaire::professeur() 	const {return d_professeur;}
formation* 	horaire::formation() 	const {return d_formation;}
salle* 		horaire::salle() 		const {return d_salle;}

bool horaire::operator<(const horaire & unHoraire) const
{
	if (d_numeroSemaine<unHoraire.numeroSemaine()) return true;
	if (d_numeroSemaine>unHoraire.numeroSemaine()) return false;
	return d_numeroHeure<unHoraire.numeroHeure();
}

bool horaire::operator<=(const horaire & unHoraire) const {return *this<unHoraire || *this==unHoraire;}
bool horaire::operator==(const horaire & unHoraire) const {return d_numeroSemaine==unHoraire.numeroSemaine() && d_numeroHeure==unHoraire.numeroHeure();}
bool horaire::operator>=(const horaire & unHoraire) const {return !(*this<unHoraire);}
bool horaire::operator>(const horaire & unHoraire) const {return !(*this<=unHoraire);}
