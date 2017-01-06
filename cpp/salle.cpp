/**
 *\file salle.cpp
 *\brief Definition des methodes de la classe salle
 *\author Olivier Ettlin
 *\version 1.0
 */

#include "../lib/salle.h"
#include "../lib/afficheurConsole.h"

using std::string;

/**
@brief Constructeur de l'objet salle
@param[in] nomSalle - une chaine de caracteres representant le nom de lasalle
 */
salle::salle (string nomSalle, int taille): ressource{nomSalle}, d_nombrePlaces{taille} {}

//SET
void salle::changerNombrePlaces(int val) {d_nombrePlaces = val;}

//GET
int salle::nombrePlaces() const {return d_nombrePlaces;}
