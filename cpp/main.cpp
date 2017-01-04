

#include <iostream>
#include <cstdlib>

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


//A intégrer à listeRessources.h
int ajouterUnProfConsole(listeRessources &lR)
{
	string nom;
	cout<<"Nom du professeur a ajouter ";
	cin>>nom;
	int dejaPresent=lR.positionDuProfesseur(nom);
	if (-1==dejaPresent)
	{
		lR.ajouterUnProfesseur(professeur{nom});
		return 0;
	}
	return -1;	//Code Erreur : Prof existe deja
}

//A découper et intégrer à listeCours.h
int ajouterUnCoursConsole(listeCours &lC,listeRessources &lR)
{
	system("cls");
	if (!lR.nombreDeProfesseurs()) return -1; //Pas de Professeur
	string nom;
	cout<<"Creation d'un cours"<<endl;
	lR.afficherLesProfesseurs(cout);
	cout<<"Nom du professeur ";
	cin>>nom;
	int profPosition=lR.positionDuProfesseur(nom);
	if (-1==profPosition) return -1; //Code Erreur : Prof inexistant
	int semaine, jour, heure;
	cout<<"Entrer le numero de la semaine : ";
	cin>>semaine;
	cout<<"Entrer le numero du jour : ";
	cin>>jour;
	cout<<"Entrer le numero de l'heure' : ";
	cin>>heure;
	cours CoursaTester{semaine, jour, heure,lR.professeurNumero(profPosition)};
	//if (!lC.estDisponible()) return -4; //Code Erreur : Ressource non disponible
	lC.ajouterUnCours(CoursaTester);
}

//A intégrer à afficheurConsole
void afficherMenuConsole()
{
	system("cls");
	cout<<"Menu :"<<endl;
	cout<<"0. Quitter et Sauvegarder"<<endl;
	cout<<"1. Afficher les ressources"<<endl;
	cout<<"2. Afficher les cours"<<endl;
	cout<<"3. Ajouter un professeur"<<endl;
	//cout<<"4. Ajouter une salle"<<endl;
	//cout<<"5. Ajouter une formation"<<endl;
	cout<<"6. Ajouter un cours"<<endl;
}

//A intégrer à afficheurConsole
void menuConsole()
{
	listeCours lC;
	listeRessources lR;
	//lire data, remplir lC et lR;
	int choix;
	do
	{
		afficherMenuConsole();
		cin>>choix;
		switch (choix)
		{
			case 1:
				//cout<<lR;
				system("pause");
				break;
			case 2:
				cout<<lC;
				system("pause");
				break;
			case 3:
				if (-1==ajouterUnProfConsole(lR))
				{
					cout<<"Ce nom de professeur est deja utilise."<<endl;
					system("pause");
				}
				break;
			case 6:
				ajouterUnCoursConsole(lC,lR);
				break;
		}
	}while (choix!=0);
	//sauvegarder lC et lR;
}

int main()
{
	//afficheurConsole aff;
	//aff.menuConsole();
	menuConsole();
	//lC.ajouterUnCours(0,0,0,lR.professeurNumero(0);
}
