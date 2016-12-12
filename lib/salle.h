#ifndef SALLE_H
#define SALLE_H

#include "listeDHoraire.h"

using std::string;

class salle : public ressource{
	public:
		salle(const string & nom, int nombreDePlace);
		int nombreDePlace() const;
	private:
		int d_nombreDePlace;
};

#endif
