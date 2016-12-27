#include "../lib/horaire.h"
#include "../lib/afficheurConsole.h"

horaire::horaire(int semaine,int jour, int heure):d_semaine{semaine%52},d_jour{jour%7},d_heure{heure%4}
{}

//SET
void horaire::changerSemaine(int semaine)	{d_semaine=semaine;}
void horaire::changerJour(int jour)			{d_jour=jour;}
void horaire::changerHeure(int heure) 		{d_heure=heure;}

//GET
int 		horaire::semaineNumero()	const {return d_semaine;}
int 		horaire::jourNumero() 	const {return d_jour;}
int 		horaire::heureNumero() 	const {return d_heure;}

int			horaire::semaine()	const {return d_semaine;}
int         horaire::jour() 	const { return d_jour; }
int	        horaire::heure() 	const{ return d_heure; }

//OPERATION
bool horaire::operator< (const horaire & unHoraire) const
{
	if (d_semaine<unHoraire.d_semaine) return true;
	if (d_semaine>unHoraire.d_semaine) return false;
	if (d_jour<unHoraire.d_jour) return true;
	if (d_semaine>unHoraire.d_jour) return false;
	return d_heure<unHoraire.d_heure;
}

bool horaire::operator<=(const horaire & unHoraire) const {return *this<unHoraire || *this==unHoraire;}
bool horaire::operator==(const horaire & unHoraire) const {return d_semaine==unHoraire.d_semaine && d_jour==unHoraire.d_jour && d_heure==unHoraire.d_heure;}
bool horaire::operator>=(const horaire & unHoraire) const {return !(*this<unHoraire);}
bool horaire::operator> (const horaire & unHoraire) const {return !(*this<=unHoraire);}

std::ostream& operator<<(std::ostream & ost, const horaire & h)
{
    afficheurConsole aff;
    horaire * h2 = new horaire (h);
	aff.afficheHoraire(h2,ost);
    delete h2;
	return ost;
}
