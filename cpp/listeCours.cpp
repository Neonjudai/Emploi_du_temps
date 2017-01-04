/**
 * @file listeCours.cpp
 * @brief Definition des methodes de la classe listeCours
 * @author Adrien Couchot
 * @version 1.0
 */

#include "../lib/listeCours.h"
#include <cstdlib>

/**
@brief Constructeur de l'objet listeCours
 */
listeCours::listeCours()
{
}

/**
  @brief Ajoute un cours
  @param[in] c - un objet de type cours
*/
void listeCours::ajouterUnCours(const cours & c)
{
	d_listeDesCours.push_back(c);
}

/**
  @brief Renvoie le nombre de cours
  @return le nombre de cours
*/
int listeCours::nombreDeCours() const
{
    return d_listeDesCours.size();
}

void listeCours::trier()
{

}
