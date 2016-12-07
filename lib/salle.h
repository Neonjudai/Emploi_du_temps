#ifndef SALLE_H
#define SALLE_H

#include "listeDHoraire.h"

using std::string;

class salle{
	public:
		salle(const string & nom, int nombreDePlace);
		string nom() const;
		int nombreDePlace() const;
	private:
		string d_nomSalle;
		int d_nombreDePlace;
		listeDHoraire d_listeDesCours;
};

#endif
