#include "../lib/listeRessources.h"

listeRessources::listeRessources()
{}

//Concerne les professeurs
void listeRessources::ajouterUnProfesseur(professeur p)		{d_listeDesProfesseurs.push_back(p);}
int listeRessources::nombreDeProfesseurs() const 			{return d_listeDesProfesseurs.size();}
professeur* listeRessources::professeurNumero(int i)
{
	if (i<d_listeDesProfesseurs.size()) return &d_listeDesProfesseurs[i];
	return &d_listeDesProfesseurs[d_listeDesProfesseurs.size()]; //Doit faire crash
}
int listeRessources::positionDuProfesseur(std::string nom) const
{
	int i=0;
	while (i<d_listeDesProfesseurs.size() && d_listeDesProfesseurs[i].nom() != nom) i++;
	if (i==d_listeDesProfesseurs.size()) return -1;
	return i;
}
void listeRessources::afficherLesProfesseurs(std::ostream & ost) const
{
	ost<<"Liste des professeurs :"<<std::endl;
	if (!d_listeDesProfesseurs.size()) ost<<"...Aucun professeur enregistre"<<std::endl;
	else for (int i=0; i<d_listeDesProfesseurs.size();++i)
	{
		ost<<d_listeDesProfesseurs[i]<<std::endl;
	}
}

//Général
std::ostream& operator<<(std::ostream & ost, const listeRessources & l)
{
	system("cls");
	ost<<"Liste des ressources"<<std::endl;
	ost<<"Professeurs :"<<std::endl;
	if (!l.d_listeDesProfesseurs.size()) ost<<"...Aucun professeur enregistre"<<std::endl;
	else for (int i=0; i<l.d_listeDesProfesseurs.size();++i)
	{
		ost<<l.d_listeDesProfesseurs[i]<<std::endl;
	}
	/*ost<<"Salles :"<<std::endl;
	if (!l.l.d_listeDesSalles.size()) ost<<"...Aucune salle enregistree"<<std::endl;
	else for (int i=0; i<l.d_listeDesSalles.size();++i)
	{
		ost<<l.d_listeDesSalles[i]<<std::endl;
	}
	ost<<"Formations :"<<std::endl;
	if (!l.d_listeDesFormations.size()) ost<<"...Aucune formation enregistree"<<std::endl;
	else for (int i=0; i<l.d_listeDesFormations.size();++i)
	{
		ost<<l.d_listeDesFormations[i]<<std::endl;
	}**/
	ost<<std::endl;
}
