#include "../lib/afficheurConsole.h"

/**
 *\file afficheurConsole.cpp
 *\brief Definition des methodes de la classe afficheurConsole
 *\author Olivier Ettlin
 *\version 1.0
 */

/**
@brief Constructeur de l'objet afficheurConsole
@param[out] ost - flux d'écriture
 */
afficheurConsole::afficheurConsole(ostream & ost):d_ost{&ost}
{}

/**
@brief Destructeur de l'objet afficheurConsole
 */
afficheurConsole::~afficheurConsole()
{delete d_ost;}

/**
@brief Renvoie dans ost le numero de la semaine de l'horaire h
@param[in] h - un objet de type horaire
 */
void afficheurConsole::afficheSemaine(const horaire & h)
{
    *d_ost<<h.semaine();
}

/**
@brief Renvoie dans ost la plage horaire de l'horaire h
@param[in] h - un objet de type horaire
 */
void afficheurConsole::afficheHeure(const horaire & h)
{
    switch (h.heure())
	{
		case 0:
			*d_ost<<"8h    a 10h  ";
		case 1:
			*d_ost<<"10h15 a 12h15";
		case 2:
			*d_ost<<"13h30 a 15h30";
		case 3:
			*d_ost<<"15h45 a 17h45";

}
}

/**
@brief Renvoie dans ost le nom du jour de la semaine de l'horaire h
@param[in] h - un objet de type horaire
 */
void afficheurConsole::afficheJour(const horaire & h)
{
    switch (h.jour())
	{
		case 0:
			*d_ost<<"Lundi   ";
		case 1:
			*d_ost<<"Mardi   ";
		case 2:
			*d_ost<<"Mercredi";
		case 3:
			*d_ost<<"Jeudi   ";
		case 4:
			*d_ost<<"Vendredi";
		case 5:
			*d_ost<<"Samedi  ";
		case 6:
			*d_ost<<"Dimanche";
	}
}

/**
@brief Renvoie dans ost l'affichage de la semaine, du jour et de l'heure correspondant à l'horaire h
@param[in] h - un objet de type horaire
 */
void afficheurConsole::afficheHoraire(const horaire & h)
{
    *d_ost<<"Semaine "<<std::setw(2);
    afficheSemaine(h);
    *d_ost<<" le ";
    afficheJour(h);
    *d_ost<<" de ";
    afficheHeure(h);
}

/**
@brief Renvoie dans ost le nom du professeur du professeur p
@param[in] p - un objet de type professeur
 */
void afficheurConsole::afficheProfesseur(const professeur & p)
{
    *d_ost<<p.nom();
}

/**
@brief Renvoie dans ost le .......... du cours c
@param[in] h - un objet de type cours
 */
void afficheurConsole::afficheCours(const cours & c)
{
    // à faire après que le getter de cours ne bug plus
}

/**
@brief Renvoie dans ost le nom de salle de la salle s
@param[in] s - un objet de type salle
 */
void afficheurConsole::afficheSalle(const salle & s)
{
    *d_ost<<s.nom();
}
