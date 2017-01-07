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
listeCours::listeCours() {}

/**
  @brief Ajoute un cours
  @param[in] c - un objet de type cours
*/
void listeCours::ajouterUnCours(const cours & c)
{	d_listeDesCours.push_back(c);
	trier();
}

/**
  @brief Renvoie le nombre de cours
  @return le nombre de cours
*/
int listeCours::nombreDeCours() const {return d_listeDesCours.size();}

/**
  @brief Renvoie le cours dont le numero correspond a l'entier entre en parametre
  @return d_listeDesCours[i] - un objet de type cours
*/
cours listeCours::coursNumero(int i) const {return d_listeDesCours[i];}

/**
  @brief Verifie si le cours peut etre ajoute a d_listeDesCours
  @return true - le cours peut etre ajoute
*/
bool listeCours::estPossible(const cours & c) const
{	int i=0;
	while (i<d_listeDesCours.size() && d_listeDesCours[i].horaireDuCours()<=c.horaireDuCours()) i++;
	while (i<d_listeDesCours.size() && d_listeDesCours[i].horaireDuCours()==c.horaireDuCours())
	{
		if (d_listeDesCours[i].professeurDuCours() 	== c.professeurDuCours()) 	return false;
		if (d_listeDesCours[i].salleDuCours() 		== c.salleDuCours()) 		return false;
		if (d_listeDesCours[i].formationDuCours()	== c.formationDuCours()) 	return false;
		i++;
	}return true;
}

//QuickSort

/**
  @brief Trie la liste de cours via la methode QuickSort(int gauche, int droite)
*/
void listeCours::trier() {QuickSort(0, d_listeDesCours.size());}

/**
  @brief Algorithme de trie QuickSort adapte a listeCours
  @param[in] gauche - entier
  @param[in] droite - entier
*/
void listeCours::QuickSort(int gauche, int droite)
{	int r;
	if (gauche<droite)
	{	r = partition(gauche, droite);
		QuickSort(gauche, r);
		QuickSort(r + 1, droite);
	}
}

/**
  @brief Partitionne d_listeDesCours
  @param[in] gauche - entier
  @param[in] droite - entier
*/
int listeCours::partition(int gauche, int droite)
{	horaire x = d_listeDesCours[gauche].horaireDuCours();
	int i = gauche;
	for (int j = gauche + 1; j<droite; j++)
		if (d_listeDesCours[j].horaireDuCours() <= x)
		{	i = i + 1;
			std::swap(d_listeDesCours[i], d_listeDesCours[j]);
		}
	std::swap(d_listeDesCours[i], d_listeDesCours[gauche]);
	return i;
}
