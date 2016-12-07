#include "../lib/listeDHoraire.h"

listeDHoraire::listeDHoraire():d_listeDHoraire{}
{}

listeDHoraire::~listeDHoraire()
{
	for (int i=0; i<d_listeDHoraire.size(); ++i) delete d_listeDHoraire[i];
}

void listeDHoraire::ajouterUnHoraire(const horaire & horaireAAjouter)
{
	d_listeDHoraire.push_back(new horaire{horaireAAjouter});
}

horaire listeDHoraire::operator[](int placeDeLHoraire) const
{
	return *(d_listeDHoraire[placeDeLHoraire]);
}

void listeDHoraire::supprimerUnHoraire(int placeDeLHoraire)
{
	//supprimer l'élément
}

void listeDHoraire::trierLaListe()
{
	//trie la liste des horaires dans l'ordre croissant
}
