#ifndef GESTIONFICHIER_H
#define GESTIONFICHIER_H

#include <iostream>
#include "listeCours.h"
#include "listeDHoraire.h"
#include "listeRessources.h"
#include <fstream>
using namespace std;

class gestionFichier
{
public:
	gestionFichier(const string &nomFichier);

	void viderLeFichier();
	bool lectureDesDonnees(listeCours &LC, listeRessources &LR);
	bool ecritureDesDonnees(const listeCours &LC,const listeRessources &LR);

private:
	string d_nomFichier;

	bool lectureDesCours		(listeCours &LC, listeRessources &LR, ifstream &lecture);
	bool lectureDesRessources	(listeRessources &LR, ifstream &lecture);

	bool ecritureDesCours		(const listeCours & LC, ofstream &ecriture);
	bool ecritureDesRessources	(const listeRessources & LR, ofstream &ecriture);
};

#endif
