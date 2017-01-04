
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
@param[in] semaine - un entier représentant le numéro de semaine
@param[in] jour - un entier représentant un jour
@param[in] heure - un entier représentant une plage horaire
@param[in] prof - un objet de type professeur
 */
cours::cours(int semaine,int jour, int heure, professeur* prof):d_horaire{semaine,jour,heure},d_professeur{prof}
{}

//GET
horaire cours::horaireDuCours() const {return d_horaire;}
