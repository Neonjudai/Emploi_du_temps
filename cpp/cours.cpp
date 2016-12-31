
/**
 * @file cours.cpp
 * @brief Definition des methodes de la classe cours
 * @author Adrien Couchot
 * @version 1.0
 */

#include "../lib/cours.h"

/**
@brief Constructeur de l'objet cours
@param[in] h - un objet de type horaire
@param[in] prof - un objet de type professeur
 */
cours::cours(const horaire & h, professeur* prof):d_horaire{h},d_professeur{prof}
{}

/**
@brief Constructeur de l'objet cours
@param[in] semaine - un entier repr�sentant le num�ro de semaine
@param[in] jour - un entier repr�sentant un jour
@param[in] heure - un entier repr�sentant une plage horaire
@param[in] prof - un objet de type professeur
 */
cours::cours(int semaine,int jour, int heure, professeur* prof):d_horaire{semaine,jour,heure},d_professeur{prof}
{}

//GET
//horaire cours::horaire() const {return d_horaire;}	BUG

/**
@brief Redefinition de l'operateur <<
@param[in] c - un objet de type cours
@param[in, out] ost - un flux de sortie
@return ost - le flux de sortie ost
 */
std::ostream& operator<<(std::ostream & ost, const cours & c)
{
	ost<<c.d_horaire<<" avec "<<*(c.d_professeur);
	return ost;
}
