/**
 * @file listeRessources.h
 * @brief Classe permettant la gestion des listes de ressources
 * @author Adrien Couchot
 * @version 1.0
 */

#ifndef LISTERESSOURCES_H
#define LISTERESSOURCES_H

#include <vector>
#include <iostream>
#include "professeur.h"

class listeRessources{
	public:
		listeRessources();

		//Concerne les professeurs
		void ajouterUnProfesseur(professeur r);
		int nombreDeProfesseurs() const;
		professeur* professeurNumero(int i);
		int positionDuProfesseur(std::string nom) const;
		void afficherLesProfesseurs(std::ostream & ost) const;

	private:
		void trier();									//A FAIRE
		std::vector <professeur> d_listeDesProfesseurs;
		//std::vector <salle> d_listeDesSalles;
		//std::vector <formation> d_listeDesFormations;

};
#endif
