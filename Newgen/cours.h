#ifndef COURS_H
#define COURS_H

#include <iostream>

#include "horaire.h"
#include "professeur.h"

class cours{	
	public:
		cours(const horaire & h, professeur p);			// OK
		cours(int semaine,int jour, int heure, professeur p);	// OK
		cours(const cours & c);							// OK
		~cours();										//inutile, listeRessource s'occupe des deletes.
		
		void direConsole(std::ostream & ost);			///Ecrire differement
		void changerHoraire(const horaire & h);			// A FAIRE
		void changerSemaine(int semaine);				// A FAIRE
		void changerHeure(int heure);					// A FAIRE
		
	private:
		horaire d_horaire;
		professeur* d_professeur;
		
};
#endif
