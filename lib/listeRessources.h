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
#include "listeCours.h"
#include "cours.h"

class listeRessources{
	public:
		listeRessources();

		//professeur
		void ajouterUnProfesseur(professeur r);
		int nombreDeProfesseurs() const;
		professeur* professeurNumeroP(int i);
		professeur professeurNumero(int i) const;
		int positionProfesseur(std::string nom) const;
		bool professeurAUnCours(const listeCours & listeDeCours, const std::string & nomDuProfesseur);
		void supprimerUnProfesseur(const std::string & nomDuProfesseur);
		
		//salle
		void ajouterUneSalle(salle s);
		int nombreDeSalles() const;
		salle* salleNumeroP(int i);
		salle salleNumero(int i) const;
		int positionSalle(std::string nom) const;
		bool salleAUnCours(const listeCours & listeDeCours, const std::string & nomDeLaSalle);
		void supprimerUneSalle(const std::string & nomDeLaSalle);
		
		//formation
		void ajouterUneFormation(formation f);
		int nombreDeFormations() const;
		formation* formationNumeroP(int i);
		formation formationNumero(int i) const;
		int positionFormation(std::string nom) const;
		bool formationAUnCours(const listeCours & listeDeCours, const std::string & nomDeLaFormation);
		void supprimerUneFormation(const std::string & nomDeLaFormation);
		
	private:
		std::vector <professeur> d_listeDesProfesseurs;
		std::vector <salle> d_listeDesSalles;
		std::vector <formation> d_listeDesFormations;

};
#endif
