#include "listeCours.h"

listeCours::listeCours()
{
}

listeCours::~listeCours()
{
	for (int i=0; i<d_listeDesCours.size();++i)
	{
		delete d_listeDesCours[i];
	}
}
		
void listeCours::ajouterUnCours(const cours & c)
{
	d_listeDesCours.push_back(new cours{c});
}

int listeCours::nombreDeCours() const
{return d_listeDesCours.size();}

void listeCours::direConsole(std::ostream & ost)
{
	for (int i=0; i<d_listeDesCours.size();++i)
	{
		d_listeDesCours[i]->direConsole(ost);
	}
}

void listeCours::trier()
{
	
}
