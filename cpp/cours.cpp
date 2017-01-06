
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
cours::cours(const horaire & h, professeur * prof):d_horaire{h},d_professeur{prof}
{}

//GET
horaire cours::horaireDuCours() const {return d_horaire;}
professeur cours::professeurDuCours() const {return *d_professeur;}
//salle* cours::salleDuCours() const {return d_salle;}
//formation* cours::formationDuCours() const {return d_formation;}
