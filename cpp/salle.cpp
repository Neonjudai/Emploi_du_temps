/**
 *\file salle.cpp
 *\brief Definition des methodes de la classe salle
 *\author Olivier Ettlin
 *\version 1.0
 */

#include "../lib/salle.h"
#include "../lib/afficheurConsole.h"

using std::string;

/**
@brief Constructeur de l'objet salle
@param[in] nomSalle - une chaine de caracteres representant le nom de lasalle
 */
salle::salle (string nomSalle, int taille): ressource{nomSalle}, d_nombrePlaces{taille}
{}

//SET
void salle::changerNombrePlaces( int val) { d_nombrePlaces = val; }

//GET
int salle::nombrePlaces() const { return d_nombrePlaces; }

/**
@brief Redefinition de l'operateur <<
@param[in] s - un objet de type salle
@param[in, out] ost - un flux de sortie
@return ost - un flux de sortie
 */
std::ostream& operator<<(std::ostream & ost, const salle & s)
{
    afficheurConsole aff;
    salle *s2= new salle (s);
    aff.afficheSalle(s2,ost);
    delete s2;
	return ost;
}
