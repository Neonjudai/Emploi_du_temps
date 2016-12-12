#ifndef FORMATION_H
#define FORMATION_H

#include "ressource.h"

using std::string;

class formation : public ressource{
	public:
		formation(const string & nom, int nombreDEtudiant);
		int nombreDEtudiant() const;
	private:
		int d_nombreDEtudiant;
};

#endif
