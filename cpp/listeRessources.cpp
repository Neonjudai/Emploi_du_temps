/**
 * @file listeRessources.cpp
 * @brief Definition des methodes de la classe listeRessources
 * @author Adrien Couchot
 * @version 1.0
 */

#include "../lib/listeRessources.h"
#include <cstdlib>

/**
@brief Constructeur de l'objet listeRessources
 */
listeRessources::listeRessources() {}

//-------------------------------------------------------------------
//--------------------professeur-------------------------------------
//-------------------------------------------------------------------

/**
  @brief Ajoute un professeur
  @param[in] p - un objet de type professeur
*/
void listeRessources::ajouterUnProfesseur(professeur p) {d_listeDesProfesseurs.push_back(p);}

/**
  @brief Renvoie le nombre de professeurs
  @return le nombre de professeur
*/
int listeRessources::nombreDeProfesseurs() const {return d_listeDesProfesseurs.size();}

/**
  @brief Renvoie le professeur dont le numero est entre en parametre
  @param[in] i - le numero du professeur
  @return le professeur* dont le numero est entre en parametre
*/
professeur* listeRessources::professeurNumeroP(int i)
{	if (i<d_listeDesProfesseurs.size()) return &d_listeDesProfesseurs[i];
	return &d_listeDesProfesseurs[d_listeDesProfesseurs.size()]; //Doit faire crash, n'est jamais appelé
}

/**
  @brief Renvoie le professeur dont le numero est entre en parametre
  @param[in] i - le numero du professeur
  @return le professeur dont le numero est entre en parametre
*/
professeur listeRessources::professeurNumero(int i) const
{	if (i<d_listeDesProfesseurs.size()) return d_listeDesProfesseurs[i];
	return d_listeDesProfesseurs[d_listeDesProfesseurs.size()]; //Doit faire crash, n'est jamais appelé
}

/**
  @brief Renvoie la position du professeur dont le nom est entre en parametre
  @param[in] nom - le nom du professeur
  @return la position du professeur dont le nom est entre en parametre
*/
int listeRessources::positionProfesseur(std::string nom) const
{	int i=0;
	while (i<d_listeDesProfesseurs.size() && d_listeDesProfesseurs[i].nom() != nom) i++;
	if (i==d_listeDesProfesseurs.size()) return -1;
	return i;
}

//-------------------------------------------------------------------
//--------------------salle------------------------------------------
//-------------------------------------------------------------------

/**
  @brief Ajoute une salle
  @param[in] s - un objet de type salle
*/
void listeRessources::ajouterUneSalle(salle s) {d_listeDesSalles.push_back(s);}

/**
  @brief Renvoie le nombre de salles
  @return le nombre de salle
*/
int listeRessources::nombreDeSalles() const {return d_listeDesSalles.size();}

/**
  @brief Renvoie la salle dont le numero est entre en parametre
  @param[in] i - le numero de la salle
  @return la salle* dont le numero est entre en parametre
*/
salle* listeRessources::salleNumeroP(int i)
{	if (i<d_listeDesSalles.size()) return &d_listeDesSalles[i];
	return &d_listeDesSalles[d_listeDesSalles.size()]; //Doit faire crash, n'est jamais appelé
}

/**
  @brief Renvoie la salle dont le numero est entre en parametre
  @param[in] i - le numero de la salle
  @return la salle dont le numero est entre en parametre
*/
salle listeRessources::salleNumero(int i) const
{	if (i<d_listeDesSalles.size()) return d_listeDesSalles[i];
	return d_listeDesSalles[d_listeDesSalles.size()]; //Doit faire crash, n'est jamais appelé
}

/**
  @brief Renvoie la position de la salle dont le nom est entre en parametre
  @param[in] nom - le nom de la salle
  @return la position de la salle dont le nom est entre en parametre
*/
int listeRessources::positionSalle(std::string nom) const
{	int i=0;
	while (i<d_listeDesSalles.size() && d_listeDesSalles[i].nom() != nom) i++;
	if (i==d_listeDesSalles.size()) return -1;
	return i;
}

//-------------------------------------------------------------------
//--------------------formation--------------------------------------
//-------------------------------------------------------------------

/**
  @brief Ajoute une formation
  @param[in] f - un objet de type formation
*/
void listeRessources::ajouterUneFormation(formation f) {d_listeDesFormations.push_back(f);}

/**
  @brief Renvoie le nombre de formations
  @return le nombre de formation
*/
int listeRessources::nombreDeFormations() const {return d_listeDesFormations.size();}

/**
  @brief Renvoie la formation dont le numero est entre en parametre
  @param[in] i - le numero de la formation
  @return la formation* dont le numero est entre en parametre
*/
formation* listeRessources::formationNumeroP(int i)
{	if (i<d_listeDesFormations.size()) return &d_listeDesFormations[i];
	return &d_listeDesFormations[d_listeDesFormations.size()]; //Doit faire crash, n'est jamais appelé
}


/**
  @brief Renvoie la formation dont le numero est entre en parametre
  @param[in] i - le numero de la formation
  @return la formation dont le numero est entre en parametre
*/
formation listeRessources::formationNumero(int i) const
{	if (i<d_listeDesFormations.size()) return d_listeDesFormations[i];
	return d_listeDesFormations[d_listeDesFormations.size()]; //Doit faire crash, n'est jamais appelé
}

/**
  @brief Renvoie la position de la formation dont le nom est entre en parametre
  @param[in] nom - le nom de la formation
  @return la position de la formation dont le nom est entre en parametre
*/
int listeRessources::positionFormation(std::string nom) const
{	int i=0;
	while (i<d_listeDesFormations.size() && d_listeDesFormations[i].nom() != nom) i++;
	if (i==d_listeDesFormations.size()) return -1;
	return i;
}
