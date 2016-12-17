#include "../lib/listeCours.h"

listeCours::listeCours()
{
}
		
void listeCours::ajouterUnCours(const cours & c)
{
	d_listeDesCours.push_back(c);
}

int listeCours::nombreDeCours() const
{return d_listeDesCours.size();}

std::ostream& operator<<(std::ostream & ost, const listeCours & l)
{
	system("cls");
	ost<<"Liste des cours"<<std::endl;
	if (!l.d_listeDesCours.size()) ost<<"...Aucun cours enregistre"<<std::endl;
	else for (int i=0; i<l.d_listeDesCours.size();++i)
	{
		ost<<l.d_listeDesCours[i]<<std::endl;
	}
	ost<<std::endl;
}

void listeCours::trier()
{
	
}
