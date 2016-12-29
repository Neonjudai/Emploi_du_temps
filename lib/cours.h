
/**
 * @file cours.h
 * @brief Classe permettant la gestion des cours
 * @author Adrien Couchot
 * @version 1.0
 */

#ifndef COURS_H
#define COURS_H

#include <iostream>

#include "horaire.h"
#include "professeur.h"

class cours{
	public:
		cours(const horaire & h, professeur* prof);				// OK
		cours(int semaine,int jour, int heure, professeur* prof);	// OK
		cours(const cours & c) =default;						// OK
		//~cours();												//inutile, listeRessource s'occupe des deletes.

		//GET
		//horaire horaire() const;								//BUG ?

		//SET
		//void changerHoraire(const horaire & h);		//TODO
		//void changerSemaine(int semaine);				//TODO
		//void changerHeure(int heure);					//TODO

		friend std::ostream& operator<<(std::ostream & ost, const cours & c);

	private:
		horaire d_horaire;
		professeur* d_professeur;

};
#endif
