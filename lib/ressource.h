/**
 * @file ressource.h
 * @brief Classe permettant la gestion des ressources
 * @author Adrien Couchot
 * @version 1.0
 */

#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <iostream>
using std::string;

class ressource{
	public:
		ressource(string nom);
		ressource(const ressource & r) =default;
		//virtual ~ressource()=default;
		string nom() const;
		void changernom (const string nom);
	private:
		string d_nom;								//Le nom de la ressource
};
#endif
