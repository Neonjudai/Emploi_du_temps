#ifndef LISTECOURS_H
#define LISTECOURS_H

#include <vector>
#include "cours.h"

class listeCours{	
	public:
		listeCours();
		~listeCours();
		
		void ajouterUnCours(const cours & c);
		int nombreDeCours() const;
		
		void direConsole(std::ostream & ost);
		
	private:
		void trier();
		std::vector <cours*> d_listeDesCours;
		
};
#endif
