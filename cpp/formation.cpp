/**
	* @file formation.cpp
	* @brief Definition des methodes de la classe formation
	* @autor Hicham Chouhad
	* @version 1.0
*/

#include "../lib/formation.h"
#include "../lib/afficheurConsole.h"

/**
@brief Constructeur de l'objet formation
@param[in] nomFormation - nom de la formation
@param[in] nombreEtudiant - Nombre d'etudiant dans la formation
*/
formation::formation(const string& nomFormation, int nombreEtudiant) : ressource{nomFormation}, d_nombreEtudiant{nombreEtudiant}
{}

/**
@brief Modifie le nombre d'etudiant dans la formation
@param[in] nombreEtudiant - le nombre d'etudiant
*/
void formation::changerNombreEtudiant(int nombreEtudiant)
{
	d_nombreEtudiant = nombreEtudiant;
}

/**
@brief renvoie le nombre d'etudiant dans la formation
@return d_nombreEtudiant - le nombre d'etudiant
*/
int formation::nombreEtudiant() const
{
	return d_nombreEtudiant;
}

/**
@brief Redefinition de l'operateur <<
@param[in, out] ost - flux de sortie
@param[in] f - une formation
*/
std::ostream& operator<<(std::ostream& ost, const formation& f)
{
	/*
	afficheurConsole aff;
	formation * f2 = new formation(f);
	aff.afficheFormation(f2, ost);
	delete f2;
	return ost;
	*/
}
