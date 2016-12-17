#include "../lib/horaire.h"

horaire::horaire(int semaine,int jour, int heure):d_semaine{semaine%52+1},d_jour{jour%7},d_heure{heure%4}
{}

//SET
void horaire::changerSemaine(int semaine)	{d_semaine=semaine;}
void horaire::changerJour(int jour)			{d_jour=jour;}
void horaire::changerheure(int heure) 		{d_heure=heure;}

//GET
int 		horaire::semaineNumero()	const {return d_semaine;}
int 		horaire::jourNumero() 	const {return d_jour;}
int 		horaire::heureNumero() 	const {return d_heure;}

int			horaire::semaine()	const {return d_semaine;}
std::string horaire::jour() 	const {
	switch (d_jour)
	{
		case 0:
			return "Lundi   ";
		case 1:
			return "Mardi   ";
		case 2:
			return "Mercredi";
		case 3:
			return "Jeudi   ";
		case 4:
			return "Vendredi";
		case 5:
			return "Samedi  ";
		case 6:
			return "Dimanche";
	}
}
std::string	horaire::heure() 	const{
	switch (d_jour)
	{
		case 0:
			return "8h    a 10h  ";
		case 1:
			return "10h15 a 12h15";
		case 2:
			return "13h30 a 15h30";
		case 3:
			return "15h45 a 17h45";
	}
}

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
	ost<<"Semaine "<<std::setw(2)<<h.semaine()<<" le "<<h.jour()<<" de "<<h.heure();
	return ost;
}
