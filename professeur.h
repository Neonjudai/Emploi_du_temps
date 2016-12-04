#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "listeDHoraire.h"

class professeur{
	public:
		professeur(const string & nom);
		std::string nom() const;
	private:
		std::string d_nomProfesseur;
		listeDHoraire d_listeDesCours;
};

#endif
