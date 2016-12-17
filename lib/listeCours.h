#ifndef LISTECOURS_H
#define LISTECOURS_H

#include <vector>
#include <iostream>
#include "cours.h"

class listeCours{	
	public:
		listeCours();
		
		void ajouterUnCours(const cours & c);
		int nombreDeCours() const;
		
		friend std::ostream& operator<<(std::ostream & ost, const listeCours & l);
		
	private:
		void trier();							//A FAIRE
		std::vector <cours> d_listeDesCours;
		
};
#endif
