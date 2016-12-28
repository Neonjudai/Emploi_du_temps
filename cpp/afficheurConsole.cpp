#include "../lib/afficheurConsole.h"

/**
 *\file afficheurConsole.h
 *\brief Classe virtuelle permettant l'affichage en console
 *\author Olivier Ettlin
 *\version 1.0
 */

/**
@brief Destructeur virtuel de l'objet afficheurConsole
 */
afficheurConsole::~afficheurConsole()
{}

/**
@brief Renvoie dans ost le numero de la semaine de l'horaire h
@param[in] h - un objet de type horaire
@param[out] ost - flux de sortie
 */
void afficheurConsole::afficheSemaine(const horaire * h, ostream & ost)
{
    ost<<h->semaine();
}


void afficheurConsole::afficheHeure(const horaire * h, ostream & ost)
{
    switch (h->heure())
	{
		case 0:
			ost<<"8h    a 10h  ";
		case 1:
			ost<<"10h15 a 12h15";
		case 2:
			ost<<"13h30 a 15h30";
		case 3:
			ost<<"15h45 a 17h45";

}
}

void afficheurConsole::afficheJour(const horaire * h, ostream & ost)
{
    switch (h->jour())
	{
		case 0:
			ost<<"Lundi   ";
		case 1:
			ost<<"Mardi   ";
		case 2:
			ost<<"Mercredi";
		case 3:
			ost<<"Jeudi   ";
		case 4:
			ost<<"Vendredi";
		case 5:
			ost<<"Samedi  ";
		case 6:
			ost<<"Dimanche";
	}
}

void afficheurConsole::afficheHoraire(const horaire * h, ostream & ost)
{
    ost<<"Semaine "<<std::setw(2);
    afficheSemaine(h,ost);
    ost<<" le ";
    afficheJour(h,ost);
    ost<<" de ";
    afficheHeure(h,ost);
}

void afficheurConsole::afficheProfesseur(const professeur * p, ostream & ost)
{
    ost<<p->nom();
}

void afficheurConsole::afficheCours(const cours * c, ostream & ost)
{
    // � faire apr�s que le getter de cours ne bug plus
}
