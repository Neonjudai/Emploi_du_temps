#ifndef SALLE_H
#define SALLE_H

#include "listeDHoraire.h"

class salle{
	public:
		salle(const string & nom, int nombreDePlace);
		std::string nom() const;
		int nombreDePlace() const;
	private:
		std::string d_nomSalle;
		int d_nombreDePlace;
		listeDHoraire d_listeDesCours;
};

#endif
