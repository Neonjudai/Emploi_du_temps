/**
 * @file professeur.h
 * @brief Classe permettant la gestion des professeurs
 * @author Adrien Couchot
 * @version 1.0
 */

#ifndef PROFESSEUR_H
#define PROFESSEUR_H


#include "ressource.h"

class professeur : public ressource{
	public:
		professeur(const string & nom);
		professeur(const professeur & p) =default;
	private:
};
#endif
