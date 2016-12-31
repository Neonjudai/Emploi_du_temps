/**
 * @file horaire.cpp
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

/**
@brief Redefinition de l'operateur <<
@param[in] l - un objet de type listeCours
@param[in, out] ost - un flux de sortie
@return ost - un flux de sortie
 */
std::ostream& operator<<(std::ostream & ost, const listeCours & l)
{
	system("cls");
	ost<<"Liste des cours"<<std::endl;
	if (!l.d_listeDesCours.size()) ost<<"...Aucun cours enregistre"<<std::endl;
	else for (int i=0; i<l.d_listeDesCours.size();++i)
	{
		ost<<l.d_listeDesCours[i]<<std::endl;
	}
	ost<<std::endl;
}

void listeCours::trier()
{

}
