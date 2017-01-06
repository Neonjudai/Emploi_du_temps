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
#include "salle.h"
#include "formation.h"

class listeRessources{
	public:
		listeRessources();

		//professeur
		void ajouterUnProfesseur(professeur r);
		int nombreDeProfesseurs() const;
		professeur* professeurNumeroP(int i);
		professeur professeurNumero(int i) const;
		int positionProfesseur(std::string nom) const;
		
		//salle
		void ajouterUneSalle(salle s);
		int nombreDeSalles() const;
		salle* salleNumeroP(int i);
		salle salleNumero(int i) const;
		int positionSalle(std::string nom) const;
		
		//formation
		void ajouterUneFormation(formation f);
		int nombreDeFormations() const;
		formation* formationNumeroP(int i);
		formation formationNumero(int i) const;
		int positionFormation(std::string nom) const;
		
	private:
		void trier();									//A FAIRE
		std::vector <professeur> d_listeDesProfesseurs;
		std::vector <salle> d_listeDesSalles;
		std::vector <formation> d_listeDesFormations;

};
#endif
