#include <iostream>
#include <cstdlib>

#include "../lib/afficheurConsole.h"
#include "../lib/listeCours.h"
#include "../lib/listeRessources.h"

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
	//lire data, remplir lC et lR;
	
	//POUR TESTER SEULEMENT
	lR.ajouterUnProfesseur(professeur{"PT"});
	lR.ajouterUneSalle(salle{"ST",14});
	lR.ajouterUneFormation(formation{"FT",10});
	cours c{{0,0,0},lR.professeurNumeroP(0),lR.salleNumeroP(0),lR.formationNumeroP(0)};
	lC.ajouterUnCours(c);
	//FIN
	
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
				codeErreur=aC.ajouterUnProf(lR,aC);
				if (codeErreur==-1) aC.afficher("Ce nom de professeur est deja utilise.",1);
				break;
			case 4:
				codeErreur=aC.ajouterUneSalle(lR,aC);
				if (codeErreur==-1) aC.afficher("Ce nom de salle est deja utilise.",1);
				break;
			case 5:
				codeErreur=aC.ajouterUneFormation(lR,aC);
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
				else if (codeErreur==-4) 	aC.afficher("Erreur : Une ressource est deja occupee.",1);
				else if (codeErreur==-5) 	aC.afficher("Erreur : Pas assez de place pour les etudiants.",1);
				break;
		}
	if (codeErreur != 0) system("pause");
	}while (choix!=0);
	//sauvegarder lC et lR;
}
