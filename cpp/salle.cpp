/**
 *\file salle.cpp
 *\brief Definition des methodes de la classe salle
 *\author Olivier Ettlin
 *\version 1.0
 */

#include "../lib/salle.h"
#include "../lib/afficheurConsole.h"

using std::string;

//salle::salle (int nombrePlaces, string nomSalle, string nomBatiment): d_nombrePlaces{nombrePlaces}, d_nomSalle{nomSalle}, d_nomBatiment{nomBatiment}
//{}

/**
@brief Constructeur de l'objet salle
@param[in] nomSalle - une chaine de caracteres representant le nom de lasalle
 */
salle::salle (string nomSalle): ressource{nomSalle}
{}

//SET
//void salle::changernombrePlaces( int val) { d_nombrePlaces = val; }
//void salle::changernomSalle(string val) { d_nomSalle = val; }
//void salle::changernomBatiment(string val) { d_nomBatiment = val; }

//GET
//int salle::nombrePlaces() const { return d_nombrePlaces; }
//string salle::nomSalle() const { return d_nomSalle; }
//string salle::nomBatiment() const { return d_nomBatiment; }

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
