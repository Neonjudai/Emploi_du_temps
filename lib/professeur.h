#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "ressource.h"

class professeur : public ressource{
	friend class ressource;	
	
	public:
		professeur(string nom);
		professeur(const professeur & p) =default;
		
		friend std::ostream& operator<<(std::ostream & ost, const professeur & p);
	private:
};
#endif
