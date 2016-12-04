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
		void supprimerUnHoraire(int placeDeLHoraire);
	private:
		std::vector<horaire*> d_listeDHoraire;
		void trierLaListe();
};

#endif
