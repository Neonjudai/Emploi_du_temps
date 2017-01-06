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
//Faire les méthodes de tri des classe listeCours et listeRessources
//Faire une vérification lors d'un rajout d'un cours à l'aide des tableaux TRIER !
//Etape 3
//Faire lecture du fichier
//Faire Sauvegarde du fichier
//Etape 4
//Permettre affichage de liste du type Prof Union Salle Inter Formation (Et / Ou logique)
//Etape 5
//Affichage Graphique


//A découper et intégrer à afficheurConsole
int ajouterUnProf(listeRessources &lR, afficheurConsole & aC)
{
	string nom;
	aC.afficher("Nom du professeur a ajouter ");
	cin>>nom;
	int dejaPresent=lR.positionProfesseur(nom);
	if (-1==dejaPresent)
	{
		lR.ajouterUnProfesseur(professeur{nom});
		return 0;
	}
	return -1;	//Code Erreur : Prof existe deja
}

//A découper et intégrer à afficheurConsole
int ajouterUneSalle(listeRessources &lR, afficheurConsole & aC)
{
	string nom;
	aC.afficher("Nom de la salle a ajouter ");
	cin>>nom;
	int dejaPresent=lR.positionSalle(nom);
	if (-1==dejaPresent)
	{
		int taille;
		aC.afficher("Taille de la salle ");
		cin>>taille;
		lR.ajouterUneSalle(salle{nom,taille});
		return 0;
	}
	return -1;	//Code Erreur : Salle existe deja
}

//A découper et intégrer à afficheurConsole
int ajouterUneFormation(listeRessources &lR, afficheurConsole & aC)
{
	string nom;
	aC.afficher("Nom de la formation a ajouter ");
	cin>>nom;
	int dejaPresent=lR.positionFormation(nom);
	if (-1==dejaPresent)
	{
		int taille;
		aC.afficher("Nombre d'etudiants dans la formation ");
		cin>>taille;
		lR.ajouterUneFormation(formation{nom,taille});
		return 0;
	}
	return -1;	//Code Erreur : Formation existe deja
}

//A découper et intégrer à afficheurConsole
int ajouterUnCours(listeCours &lC,listeRessources &lR, afficheurConsole & aC)
{
	system("cls");
	if (!lR.nombreDeProfesseurs()) return 1; //Pas de Professeur
	string nom;
	aC.afficher("Creation d'un cours",1);
	aC.afficherLesProfesseurs(lR);
	aC.afficher("Nom du professeur ");
	cin>>nom;
	int profPosition=lR.positionProfesseur(nom);
	if (-1==profPosition) return -1; //Code Erreur : Prof inexistant
	int semaine, jour, heure;
	aC.afficher("Entrer le numero de la semaine : ");
	cin>>semaine;
	aC.afficher("Entrer le numero du jour       : ");
	cin>>jour;
	aC.afficher("Entrer le numero de l'heure    : ");
	cin>>heure;
	cours CoursaTester{{semaine, jour, heure},lR.professeurNumeroP(profPosition)};
	//if (!lC.estDisponible()) return -4; //Code Erreur : Ressource non disponible
	lC.ajouterUnCours(CoursaTester);
}

//A intégrer à afficheurConsole
void afficherMenu(afficheurConsole & aC)
{
	system("cls");
	aC.afficher("Menu :");
	aC.afficher("endl");
	aC.afficher("0. Quitter et Sauvegarder",1);
	aC.afficher("1. Afficher les ressources",1);
	aC.afficher("2. Afficher les cours",1);
	aC.afficher("3. Ajouter un professeur",1);
	aC.afficher("4. Ajouter une salle",1);
	aC.afficher("5. Ajouter une formation",1);
	aC.afficher("6. Ajouter un cours",1);
}

//A intégrer à afficheurConsole
void menu(afficheurConsole & aC)
{
	int codeErreur;
	listeCours lC;
	listeRessources lR;
	//lire data, remplir lC et lR;
	int choix;
	do
	{
		codeErreur=0;
		afficherMenu(aC);
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
				codeErreur=ajouterUnProf(lR,aC);
				if (codeErreur==-1) aC.afficher("Ce nom de professeur est deja utilise.",1);
				break;
			case 4:
				codeErreur=ajouterUneSalle(lR,aC);
				if (codeErreur==-1) aC.afficher("Ce nom de salle est deja utilise.",1);
				break;
			case 5:
				codeErreur=ajouterUneFormation(lR,aC);
				if (codeErreur==-1) aC.afficher("Ce nom de formation est deja utilise.",1);
				break;
			case 6:
				codeErreur=ajouterUnCours(lC,lR,aC);
				if (codeErreur==1) aC.afficher("Vous devez d'abord ajouter un professeur.",1);
				if (codeErreur==2) aC.afficher("Vous devez d'abord ajouter une salle.",1);
				if (codeErreur==3) aC.afficher("Vous devez d'abord ajouter une formation.",1);
				if (codeErreur==-1) aC.afficher("Ce professeur n'existe pas.",1);
				if (codeErreur==-2) aC.afficher("Cette salle n'existe pas.",1);
				if (codeErreur==-3) aC.afficher("Cette formation n'existe pas.",1);
				if (codeErreur==-4) aC.afficher("Une ressource est deja occupee.",1);
				break;
		}
	if (codeErreur != 0) system("pause");
	}while (choix!=0);
	//sauvegarder lC et lR;
}

int main()
{
	afficheurConsole aC{cout};
	menu(aC);
}
