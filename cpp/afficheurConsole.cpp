#include "../lib/afficheurConsole.h"

/**
 *\file afficheurConsole.cpp
 *\brief Definition des methodes de la classe afficheurConsole
 *\author Olivier Ettlin
 *\version 1.0
 */

/**
@brief Constructeur de l'objet afficheurConsole
@param[out] ost - flux d'écriture
 */
afficheurConsole::afficheurConsole(ostream & ost):d_ost{&ost} {}

/**
@brief Destructeur de l'objet afficheurConsole
 */
afficheurConsole::~afficheurConsole() {d_ost=0;}

void afficheurConsole::afficher(string s, int sautLigne)
{	if (s=="endl") *d_ost<<endl;
	else
	{
		*d_ost<<s;
		if (sautLigne==1) *d_ost<<endl;
	}
}

void afficheurConsole::afficherMenu()
{	system("cls");
	afficher("Menu :");
	afficher("endl");
	afficher("0. Quitter et Sauvegarder",1);
	afficher("1. Afficher les ressources",1);
	afficher("2. Afficher les cours",1);
	afficher("3. Ajouter un professeur",1);
	afficher("4. Ajouter une salle",1);
	afficher("5. Ajouter une formation",1);
	afficher("6. Ajouter un cours",1);
}

//-------------------------------------------------------------------
//--------------------Cours------------------------------------------
//-------------------------------------------------------------------

/**
@brief Renvoie dans ost le .......... du cours c
@param[in] h - un objet de type cours
 */
void afficheurConsole::afficherCours(const cours & c)
{   afficherHoraire(c.horaireDuCours());
    afficherProfesseur(c.professeurDuCours());
    for (int i=0;i<16-c.professeurDuCours().nom().length();i++) *d_ost<<' ';
    *d_ost<<"| ";
    afficherFormation(c.formationDuCours());
    for (int i=0;i<16-c.professeurDuCours().nom().length();i++) *d_ost<<' ';
    *d_ost<<"| ";
}

//-------------------------------------------------------------------
//--------------------Formation--------------------------------------
//-------------------------------------------------------------------

void afficheurConsole::afficherFormation(const formation & f) {*d_ost<<f.nom()<<" avec "<<f.nombreEtudiant()<<" etudiants.";}

//-------------------------------------------------------------------
//--------------------Horaire----------------------------------------
//-------------------------------------------------------------------

/**
@brief Renvoie dans ost le numero de la semaine de l'horaire h
@param[in] h - un objet de type horaire
 */
void afficheurConsole::afficherSemaine(const horaire & h) {*d_ost<<std::setw(2)<<h.semaine();}

/**
@brief Renvoie dans ost la plage horaire de l'horaire h
@param[in] h - un objet de type horaire
 */
void afficheurConsole::afficherHeure(const horaire & h)
{   switch (h.heure())
	{
		case 0:*d_ost<<"8h    a 10h  ";break;
		case 1:*d_ost<<"10h15 a 12h15";break;
		case 2:*d_ost<<"13h30 a 15h30";break;
		case 3:*d_ost<<"15h45 a 17h45";break;
	}*d_ost<<" | ";
}

/**
@brief Renvoie dans ost le nom du jour de la semaine de l'horaire h
@param[in] h - un objet de type horaire
 */
void afficheurConsole::afficherJour(const horaire & h)
{   switch (h.jour())
	{
		case 0:*d_ost<<"Lundi   ";break;
		case 1:*d_ost<<"Mardi   ";break;
		case 2:*d_ost<<"Mercredi";break;
		case 3:*d_ost<<"Jeudi   ";break;
		case 4:*d_ost<<"Vendredi";break;
		case 5:*d_ost<<"Samedi  ";break;
		case 6:*d_ost<<"Dimanche";break;
	}*d_ost<<" | ";
}

/**
@brief Renvoie dans ost l'affichage de la semaine, du jour et de l'heure correspondant à l'horaire h
@param[in] h - un objet de type horaire
 */
void afficheurConsole::afficherHoraire(const horaire & h)
{   *d_ost<<"   ";afficherSemaine(h);*d_ost<<"   | ";
    afficherJour(h);
    afficherHeure(h);
}

//-------------------------------------------------------------------
//--------------------listeCours-------------------------------------
//-------------------------------------------------------------------
void afficheurConsole::afficherLesCours(const listeCours & lC)
{	*d_ost<<"Liste des cours :"<<std::endl;
	if (!lC.nombreDeCours()) *d_ost<<"...Aucun cours enregistre"<<std::endl;
	else
	{
		*d_ost<<"__________________________________________________________________________________________"<<endl;
		*d_ost<<"Semaine | Jour     | Horaire       | Professeur      | Salle           | Formation       |"<<endl;
		*d_ost<<"------------------------------------------------------------------------------------------"<<endl;
		for (int i=0; i<lC.nombreDeCours();++i)
		{
			afficherCours(lC.coursNumero(i));
			*d_ost<<std::endl;
		}
		*d_ost<<"------------------------------------------------------------------------------------------"<<endl;
	}
}

int afficheurConsole::ajouterUnCours(listeCours &lC,listeRessources &lR)
{	system("cls");
	//Test initial
	if (!lR.nombreDeProfesseurs()) 	return 1; 				//Code Erreur : Pas de Professeur
	if (!lR.nombreDeSalles()) 		return 2; 				//Code Erreur : Pas de Salle
	if (!lR.nombreDeFormations()) 	return 3; 				//Code Erreur : Pas de Formation
	afficher("Creation d'un cours",1);
	string nom;
	//Professeur
	afficherLesProfesseurs(lR);
	afficher("Nom du professeur ");
	cin>>nom;
	int professeurPosition=lR.positionProfesseur(nom);
	if (-1==professeurPosition) return -1; 					//Code Erreur : Professeur inexistant
	//Salle
	afficherLesSalles(lR);
	afficher("Nom de la Salle ");
	cin>>nom;
	int sallePosition=lR.positionSalle(nom);
	if (-1==sallePosition) return -2; 						//Code Erreur : Salle inexistante
	//Formation
	afficherLesFormations(lR);
	afficher("Nom de la Formation ");
	cin>>nom;
	int formationPosition=lR.positionFormation(nom);
	if (-1==formationPosition) return -3; 					//Code Erreur : Formation inexistante
	//Horaire
	int semaine, jour, heure;
	afficher("Entrer le numero de la semaine : ");
	cin>>semaine;
	afficher("Entrer le numero du jour       : ");
	cin>>jour;
	afficher("Entrer le numero de l'heure    : ");
	cin>>heure;
	//Création du cours
	cours CoursaTester{{semaine, jour, heure},lR.professeurNumeroP(professeurPosition),lR.salleNumeroP(sallePosition),lR.formationNumeroP(formationPosition)};
	//Teste
	if (lC.estPossible(CoursaTester)) return -4; 			//Code Erreur : Ressource non disponible
	//Ajout du cours
	lC.ajouterUnCours(CoursaTester);
}

//-------------------------------------------------------------------
//--------------------listeRessources--------------------------------
//-------------------------------------------------------------------

void afficheurConsole::afficherLesRessources(const listeRessources & lR)
{	afficherLesProfesseurs(lR);
	afficherLesSalles(lR);
	afficherLesFormations(lR);
}

void afficheurConsole::afficherLesProfesseurs(const listeRessources & lR)
{	*d_ost<<"Liste des professeurs :"<<std::endl;
	if (!lR.nombreDeProfesseurs()) *d_ost<<"...Aucun professeur enregistre"<<std::endl;
	else for (int i=0; i<lR.nombreDeProfesseurs();++i)
	{
		*d_ost<<'\t';
		afficherProfesseur(lR.professeurNumero(i));
		*d_ost<<std::endl;
	}
}

void afficheurConsole::afficherLesSalles(const listeRessources & lR)
{	*d_ost<<"Liste des salles :"<<std::endl;
	if (!lR.nombreDeSalles()) *d_ost<<"...Aucune salle enregistree"<<std::endl;
	else for (int i=0; i<lR.nombreDeSalles();++i)
	{
		*d_ost<<'\t';
		afficherSalle(lR.salleNumero(i));
		*d_ost<<std::endl;
	}
}

void afficheurConsole::afficherLesFormations(const listeRessources & lR)
{	*d_ost<<"Liste des formations :"<<std::endl;
	if (!lR.nombreDeFormations()) *d_ost<<"...Aucune formation enregistree"<<std::endl;
	else for (int i=0; i<lR.nombreDeFormations();++i)
	{
		*d_ost<<'\t';
		afficherFormation(lR.formationNumero(i));
		*d_ost<<std::endl;
	}
}

int afficheurConsole::ajouterUnProf(listeRessources &lR, afficheurConsole & aC)
{	string nom;
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

int afficheurConsole::ajouterUneSalle(listeRessources &lR, afficheurConsole & aC)
{	string nom;
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

int afficheurConsole::ajouterUneFormation(listeRessources &lR, afficheurConsole & aC)
{	string nom;
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

//-------------------------------------------------------------------
//--------------------professeur-------------------------------------
//-------------------------------------------------------------------

/**
@brief Renvoie dans ost le nom du professeur du professeur p
@param[in] p - un objet de type professeur
 */
void afficheurConsole::afficherProfesseur(const professeur & p) {*d_ost<<p.nom();}

//-------------------------------------------------------------------
//--------------------salle------------------------------------------
//-------------------------------------------------------------------

/**
@brief Renvoie dans ost le nom de salle de la salle s
@param[in] s - un objet de type salle
 */
void afficheurConsole::afficherSalle(const salle & s) {*d_ost<<s.nom()<<" avec "<<s.nombrePlaces()<<" places.";}
