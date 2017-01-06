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
	trier();
}

/**
  @brief Renvoie le nombre de cours
  @return le nombre de cours
*/
int listeCours::nombreDeCours() const
{
    return d_listeDesCours.size();
}

cours listeCours::coursNumero(int i) const
{
	return d_listeDesCours[i];
}

void listeCours::trier()
{
	QuickSort(0, d_listeDesCours.size());
}

//QuickSort

void listeCours::QuickSort(int gauche, int droite)
{
	int r;
	if (gauche<droite)
	{
		r = partition(gauche, droite);
		QuickSort(gauche, r);
		QuickSort(r + 1, droite);
	}
}

int listeCours::partition(int gauche, int droite)
{
	horaire x = d_listeDesCours[gauche].horaireDuCours();
	int i = gauche;
	for (int j = gauche + 1; j<droite; j++)
		if (d_listeDesCours[j].horaireDuCours() <= x)
		{
			i = i + 1;
			std::swap(d_listeDesCours[i], d_listeDesCours[j]);
		}
	std::swap(d_listeDesCours[i], d_listeDesCours[gauche]);
	return i;
}
