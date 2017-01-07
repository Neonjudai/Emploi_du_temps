#include <iostream>
#include <cstdlib>

#include "../lib/afficheurConsole.h"
#include "../lib/listeCours.h"
#include "../lib/listeRessources.h"
#include "../lib/gestionFichier.h"

using std::cout;
using std::cin;
using std::endl;

//TODO list
//Etape 2
//Faire une tape sécurisé des entiers avec des strings
//Faire une vérification lors d'un rajout d'un cours à l'aide des tableaux TRIER !
//Etape 3
//Faire lecture du fichier
//Faire Sauvegarde du fichier
//Etape 4
//Permettre affichage de liste du type Prof Union Salle Inter Formation (Et / Ou logique)

void menu(afficheurConsole & aC);

int main()
{
	afficheurConsole aC{cout};
	menu(aC);
}

void menu(afficheurConsole & aC)
{
	int codeErreur;
	listeCours lC;
	listeRessources lR;
	gestionFichier gF("Donnees/data.txt");
	
	if(!gF.lectureDesDonnees(lC, lR))
	{
		aC.afficher("Erreur lors de la lecture du fichier.",1);
		system("pause");
	}
	
	int choix;
	do
	{
		codeErreur=0;
		aC.afficherMenu();
		cin>>choix;
		switch (choix)
		{
			case 1:
				aC.afficherLesRessources(lR);
				system("pause");
				break;
			case 2:
				aC.afficherLesCours(lC);
				system("pause");
				break;
			case 3:
				codeErreur=aC.ajouterUnProf(lR);
				if (codeErreur==-1) aC.afficher("Ce nom de professeur est deja utilise.",1);
				break;
			case 4:
				codeErreur=aC.ajouterUneSalle(lR);
				if (codeErreur==-1) aC.afficher("Ce nom de salle est deja utilise.",1);
				break;
			case 5:
				codeErreur=aC.ajouterUneFormation(lR);
				if (codeErreur==-1) aC.afficher("Ce nom de formation est deja utilise.",1);
				break;
			case 6:
				codeErreur=aC.ajouterUnCours(lC,lR);
				if (codeErreur==1) 			aC.afficher("Erreur : Vous devez d'abord ajouter un professeur.",1);
				else if (codeErreur==2) 	aC.afficher("Erreur : Vous devez d'abord ajouter une salle.",1);
				else if (codeErreur==3) 	aC.afficher("Erreur : Vous devez d'abord ajouter une formation.",1);
				else if (codeErreur==-1) 	aC.afficher("Erreur : Ce professeur n'existe pas.",1);
				else if (codeErreur==-2) 	aC.afficher("Erreur : Cette salle n'existe pas.",1);
				else if (codeErreur==-3) 	aC.afficher("Erreur : Cette formation n'existe pas.",1);
				else if (codeErreur==-4) 	aC.afficher("Erreur : Pas assez de place pour les etudiants.",1);
				else if (codeErreur==-5) 	aC.afficher("Erreur : Professeur deja occupe.",1);
				else if (codeErreur==-6) 	aC.afficher("Erreur : Salle deja occupe.",1);
				else if (codeErreur==-7) 	aC.afficher("Erreur : Formation deja occupe.",1);
				break;
			case 7:
				codeErreur=aC.supprimerUnProf(lR,lC);
				if (codeErreur==-1) aC.afficher("Ce professeur n'existe pas.",1);
				if (codeErreur==-2) aC.afficher("Ce professeur est requis pour un cours.",1);
				break;
			case 8:
				codeErreur=aC.supprimerUneSalle(lR,lC);
				if (codeErreur==-1) aC.afficher("Cette salle n'existe pas.",1);
				if (codeErreur==-2) aC.afficher("Cette salle est requise pour un cours.",1);
				break;
			case 9:
				codeErreur=aC.supprimerUneFormation(lR,lC);
				if (codeErreur==-1) aC.afficher("Cette formation n'existe pas.",1);
				if (codeErreur==-2) aC.afficher("Cette formation est requise pour un cours.",1);
				break;
			case 10:
				codeErreur=aC.supprimerUnCours(lC,lR);
				if (codeErreur==-1) 		aC.afficher("Erreur : Ce professeur n'existe pas.",1);
				else if (codeErreur==-2) 	aC.afficher("Erreur : Cette salle n'existe pas.",1);
				else if (codeErreur==-3) 	aC.afficher("Erreur : Cette formation n'existe pas.",1);
				else if (codeErreur==1) 	aC.afficher("Il n'y a aucun cours a supprimer.",1);
				else if (codeErreur==2) 	aC.afficher("Ce cours n'existe pas.",1);
				break;
		}
	if (codeErreur != 0) system("pause");
	}while (choix!=0);
	
	if(!gF.ecritureDesDonnees(lC, lR))
	{
		aC.afficher("Erreur lors de l'ecriture du fichier.",1);
		system("pause");
	}
}
