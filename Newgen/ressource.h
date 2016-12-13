#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <iostream>
using std::string;

class ressource{
	public:
		ressource(string nom);
		string nom() const;

	private:
		string d_nomDeLaRessource;								//Le nom de la ressource
};
#endif
