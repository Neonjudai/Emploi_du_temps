/**
 * @file formation.h
 * @brief Classe permettant la gestion des formations
 * @author Hicham Chouhad
 * @version 1.1
 */

#ifndef FORMATION_H
#define FORMATION_H

#include "ressource.h"

using std::string;

class formation : public ressource{
	public:
		formation(const string & nomFormation, int nombreEtudiant);
		formation() = delete;
		formation(const formation &f) = default;
		
		//SET
		void changerNombreEtudiant(int nombreEtudiant);
		
		//GET
		int nombreEtudiant() const;
		
		friend std::ostream& operator<<(std::ostream& ost, const formation& f);
	private:
		int d_nombreEtudiant;
};

#endif
