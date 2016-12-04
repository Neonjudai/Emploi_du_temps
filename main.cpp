#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

//Il manque une classe qui gère :
//-des vecteurs de prof
//-des vecteurs de formation
//-des vecteur de salles

//Lors de l'utilisation du programme, on utilisera 4 vectors
//Un qui conservera TOUT les horaires (est-ce qu'on lui ajoutera des pointeurs sur les profs, formation et salles utilisées ? pour gagner en efficacité)
//Un qui conservera TOUT les profs et donc les horaires de chacun
//Un qui conservera TOUTES les formations et donc les horaires de chacune
//Un qui conservera TOUTES les salles et donc les horaires de chacune

//La liste d'horaire sera agrandi avec des new horaire()
//Les horaires du prof/salle/formation seront des pointeurs sur l'horaire dans cette liste d'horaire.

//Exemple d'utilisation :
//Je demande l'affichage de tout les cours d'une formation.
//Je trouve la formation (si elle existe) dans la liste de formation
//Grace au pointeur vers les horaires le programme sort pour chaque horaire (rapidement si on ajoute pointeurs sur les profs, formation et salles SINON il faut rechercher dans chacune des autres listes)
//			la salle, le prof et la formation de cette horaire

//En version plus proche du programme
//listeDesFormations.coutLaFormation(nomFormation)
//		if (nomFormation existe) for (i=<leNombreDHoraire) coutLeCours[i]
//				coutLeCours[i]->nomprof coutLeCours[i]->nomformation coutLeCours[i]->nomsalle coutLeCours[i]->horaire 

int main(int argc, char** argv)
{

}
