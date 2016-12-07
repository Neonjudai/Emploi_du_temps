#ifndef FORMATION_H
#define FORMATION_H

#include "listeDHoraire.h"

using std::string;

class formation{
	public:
		formation(const string & nom, int nombreDEtudiants);
		string nom() const;
		int nombreDEtudiants() const;
	private:
		string d_nomFormation;								//Le nom de la formation
		int d_nombreDEtudiants;									//Nombre d'Etudiants dans la formation
		listeDHoraire d_listeDesCours;							//Liste des cours suivit par la formation
};

#endif
