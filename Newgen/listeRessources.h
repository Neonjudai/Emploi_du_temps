#ifndef LISTERESSOURCES_H
#define LISTERESSOURCES_H

#include <vector>
#include "ressource.h"

class listeRessources{	
	public:
		listeRessources();
		~listeRessources();
		
		void ajouterUneRessource(const ressource & r);	//A FAIRE
		int nombreDeRessources() const;
		
		void direConsole(std::ostream & ost);			//A FAIRE
		
	private:
		void trier();									//A FAIRE
		std::vector <ressource*> d_listeDesRessources;
		
};
#endif
