/**
 * @file professeur.cpp
 * @briefDefinition des mthodes de la classe professeur
 * @author Adrien Couchot
 * @version 1.0
 */

#include "../lib/professeur.h"
#include "../lib/afficheurConsole.h"

/**
@brief Constructeur de l'objet professeur
@param[in] nom - une chaine de caractere representant le nom du professeur
 */
professeur::professeur(string nom):ressource{nom}
{
}

/**
@brief Redefinition de l'operateur <<
@param[in] p - un objet de type professeur
@param[in, out] ost - un flux de sortie
@return ost - un flux de sortie
 */
std::ostream& operator<<(std::ostream & ost, const professeur & p)
{
    afficheurConsole aff;
    professeur *p2= new professeur (p);
    aff.afficheProfesseur(p2,ost);
    delete p2;
	return ost;
}
