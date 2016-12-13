#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "ressource.h"

class professeur : public ressource{
	friend class ressource;	
	
	public:
		professeur(string nom);
	private:
};
#endif
