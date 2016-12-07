#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "listeDHoraire.h"

using std::string;

class professeur{
	public:
		professeur(const string & nom);
		sstring nom() const;
	private:
		string d_nomProfesseur;
		listeDHoraire d_listeDesCours;
};

#endif
