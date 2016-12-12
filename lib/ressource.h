#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <iostream>
#include "../lib/listeDHoraire.h"

using std::string;

class ressource{
	public:
		ressource(const string & nom);
		string nomDeLaRessource() const;

	private:
		string d_nomDeLaRessource;								//Le nom de la formation
		listeDHoraire d_listeDesCours;							//Liste des cours dans laquelle la ressource est utilisée
};
#endif
