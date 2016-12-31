/**
 * @file listeDHoraire.h
 * @brief Classe permettant la gestion de listes d'horaires
 * @author Adrien Couchot
 * @version 1.0
 */

#ifndef LISTEDHORAIRE_H
#define LISTEDHORAIRE_H

#include <vector>
#include "horaire.h"

class listeDHoraire{
	public:
		listeDHoraire();
		~listeDHoraire();
		void ajouterUnHoraire(const horaire & horaireAAjouter);
		horaire operator[](int placeDeLHoraire) const;
		void supprimerUnHoraire(int placeDeLHoraire);//A faire
	private:
		std::vector<horaire*> d_listeDHoraire;
		void trierLaListe();//A faire
};

#endif
