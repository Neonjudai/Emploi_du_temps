/**
 * @file listeDHoraire.cpp
 * @brief Definition des methodes de la classe listeDHoraire
 * @author Adrien Couchot
 * @version 1.0
 */

#include "../lib/listeDHoraire.h"

/**
@brief Constructeur de l'objet listeDHoraire
 */
listeDHoraire::listeDHoraire():d_listeDHoraire{}
{}

/**
@brief Destructeur de l'objet listeDHoraire
 */
listeDHoraire::~listeDHoraire()
{
	for (int i=0; i<d_listeDHoraire.size(); ++i) delete d_listeDHoraire[i];
}

/**
  @brief Ajoute un horaire
  @param[in] horaireAAjouter - un objet de type horaire
*/
void listeDHoraire::ajouterUnHoraire(const horaire & horaireAAjouter)
{
	d_listeDHoraire.push_back(new horaire{horaireAAjouter});
}

/**
@brief Redefinition de l'operateur []
@param[in] placeDeLHoraire - un entier representant la place de l'horaire
 */
horaire listeDHoraire::operator[](int placeDeLHoraire) const
{
	return *(d_listeDHoraire[placeDeLHoraire]);
}

/**
@brief Supprime l'horaire dont le numero est placeDeLHoraire
@param[in] placeDeLHoraire - un entier representant la place de l'horaire
 */
void listeDHoraire::supprimerUnHoraire(int placeDeLHoraire)
{
	//supprimer l'élément
}

/**
@brief Trie la liste
 */
void listeDHoraire::trierLaListe()
{
	//trie la liste des horaires dans l'ordre croissant
}
