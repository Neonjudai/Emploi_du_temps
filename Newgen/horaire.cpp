#include "horaire.h"

horaire::horaire(int numeroSemaine, int numeroHeure):d_numeroSemaine{numeroSemaine},d_numeroHeure{numeroHeure}
{}

horaire::horaire(const horaire & unHoraire):d_numeroSemaine{unHoraire.d_numeroSemaine},d_numeroHeure{unHoraire.d_numeroHeure}
{}

//SET
void horaire::changerSemaine(int numeroSemaine)		{d_numeroSemaine=numeroSemaine;}
void horaire::changernumeroHeure(int numeroHeure) 	{d_numeroHeure=numeroHeure;}

//GET
int 		horaire::numeroSemaine()const {return d_numeroSemaine;}
int 		horaire::numeroHeure() 	const {return d_numeroHeure;}

//OPERATION
bool horaire::operator< (const horaire & unHoraire) const
{
	if (d_numeroSemaine<unHoraire.numeroSemaine()) return true;
	if (d_numeroSemaine>unHoraire.numeroSemaine()) return false;
	return d_numeroHeure<unHoraire.numeroHeure();
}

bool horaire::operator<=(const horaire & unHoraire) const {return *this<unHoraire || *this==unHoraire;}
bool horaire::operator==(const horaire & unHoraire) const {return d_numeroSemaine==unHoraire.numeroSemaine() && d_numeroHeure==unHoraire.numeroHeure();}
bool horaire::operator>=(const horaire & unHoraire) const {return !(*this<unHoraire);}
bool horaire::operator> (const horaire & unHoraire) const {return !(*this<=unHoraire);}
