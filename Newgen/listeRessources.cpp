#include "listeRessources.h"

listeRessources::listeRessources()
{
}

listeRessources::~listeRessources()
{
	for (int i=0; i<d_listeDesRessources.size();++i)
	{
		delete d_listeDesRessources[i];
	}
}

int listeRessources::nombreDeRessources() const
{return d_listeDesRessources.size();}
