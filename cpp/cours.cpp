#include "../lib/cours.h"

cours::cours(const horaire & h, professeur* prof):d_horaire{h},d_professeur{prof}
{}

cours::cours(int semaine,int jour, int heure, professeur* prof):d_horaire{semaine,jour,heure},d_professeur{prof}
{}

//GET
//horaire cours::horaire() const {return d_horaire;}	BUG

std::ostream& operator<<(std::ostream & ost, const cours & c)
{
	ost<<c.d_horaire<<" avec "<<*(c.d_professeur);
	return ost;
}
