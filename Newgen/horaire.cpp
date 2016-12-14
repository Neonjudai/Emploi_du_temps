#include "horaire.h"

horaire::horaire(int semaine,int jour, int heure):d_semaine{semaine},d_jour{jour},d_heure{heure}								{}
horaire::horaire(const horaire & unHoraire):d_semaine{unHoraire.d_semaine},d_jour{unHoraire.d_jour},d_heure{unHoraire.d_heure}	{}

//SET
void horaire::changerSemaine(int semaine){d_semaine=semaine;}
void horaire::changerJour(int jour)		 {d_jour=jour;}
void horaire::changerHeure(int heure) 	 {d_heure=heure;}

//GET
int 		horaire::semaine()	const {return d_semaine;}
int 		horaire::jour() 	const {return d_jour;}
int 		horaire::heure() 	const {return d_heure;}

//OPERATION
bool horaire::operator< (const horaire & unHoraire) const
{
	if (d_semaine<unHoraire.semaine()) return true;
	if (d_semaine>unHoraire.semaine()) return false;
	return d_heure<unHoraire.heure();
}

bool horaire::operator<=(const horaire & unHoraire) const {return *this<unHoraire || *this==unHoraire;}
bool horaire::operator==(const horaire & unHoraire) const {return d_semaine==unHoraire.semaine() && d_heure==unHoraire.heure();}
bool horaire::operator>=(const horaire & unHoraire) const {return !(*this<unHoraire);}
bool horaire::operator> (const horaire & unHoraire) const {return !(*this<=unHoraire);}
