#include "../lib/afficheurConsole.h"
#include <cstdlib>

/**
 *\file afficheurConsole.cpp
 *\brief Definition des methodes de la classe afficheurConsole
 *\author Olivier Ettlin
 *\version 1.0
 */

const int T_AFFICHAGE = 119;

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

/**
@brief Affichage des menus
 */
void afficheurConsole::afficherMenu()
{	system("cls");
	afficher("Menu :");
	afficher("endl");
	afficher("1. Afficher les ressources",1);
	afficher("2. Afficher les cours",1);
	afficher("3. Ajouter un professeur",1);
	afficher("4. Ajouter une salle",1);
	afficher("5. Ajouter une formation",1);
	afficher("6. Ajouter un cours",1);
	afficher("7. Supprimer un professeur",1);
	afficher("8. Supprimer une salle",1);
	afficher("9. Supprimer une formation",1);
	afficher("10. Supprimer un cours",1);
	afficher("11. Afficher les cours du professeur",1);
	afficher("12. Afficher les cours de la salle",1);
	afficher("13. Afficher les cours de la formation",1);
	afficher("0. Quitter et Sauvegarder",1);
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
    for (unsigned int i=0;i<16-c.professeurDuCours().nom().length();i++) *d_ost<<' ';
    *d_ost<<"| ";
    afficherFormation(c.formationDuCours());
    for (unsigned int i=0;i<15-c.formationDuCours().nom().length();i++) *d_ost<<' ';
    *d_ost<<"| ";
    afficherSalle(c.salleDuCours());
    for (unsigned int i=0;i<11-c.salleDuCours().nom().length();i++) *d_ost<<' ';
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

/**
@brief Renvoie dans ost les cours de la liste de ressources
@param[in] lC - un objet de type listeCours
*/
void afficheurConsole::afficherLesCours(const listeCours & lC)
{	*d_ost<<"Liste des cours :"<<std::endl;
	if (!lC.nombreDeCours()) *d_ost<<"...Aucun cours enregistre"<<std::endl;
	else
	{
		for (int i=0;i<T_AFFICHAGE;i++) *d_ost<<"_";
		*d_ost<<endl;
		*d_ost<<"Semaine | Jour     | Horaire       | Professeur      | Formation                         | Salle                      |"<<endl;
		for (int i=0;i<T_AFFICHAGE;i++) *d_ost<<"-";
		*d_ost<<endl;
		for (int i=0; i<lC.nombreDeCours();++i)
		{
			afficherCours(lC.coursNumero(i));
			*d_ost<<std::endl;
		}
		for (int i=0;i<T_AFFICHAGE;i++) *d_ost<<"-";
		*d_ost<<endl;
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
	int succes = lC.estPossible(CoursaTester); 			//Code Erreur : Ressource non disponible
	if (succes !=0) return succes;
	//Ajout du cours
	lC.ajouterUnCours(CoursaTester);
	return 0;
}

int afficheurConsole::supprimerUnCours(listeCours &lC,listeRessources &lR)
{	if (lC.nombreDeCours()<1) return 1;						//Code Erreur : Aucun cours
	system("cls");
	afficherLesCours(lC);
	afficher("Choisissez le cours a supprimer",1);
	string nom;
	//Professeur
	afficher("Nom du professeur ");
	cin>>nom;
	int professeurPosition=lR.positionProfesseur(nom);
	if (-1==professeurPosition) return -1; 					//Code Erreur : Professeur inexistant
	//Salle
	afficher("Nom de la Salle ");
	cin>>nom;
	int sallePosition=lR.positionSalle(nom);
	if (-1==sallePosition) return -2; 						//Code Erreur : Salle inexistante
	//Formation
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
	int numero=lC.numeroDeCours(	{semaine,jour,heure},
									lR.professeurNumero(professeurPosition),
									lR.salleNumero(sallePosition),
									lR.formationNumero(formationPosition));
	if (numero==-1) return 2;
	lC.supprimerUnCours(numero);							//Code Erreur : Cours non existant
	return 0;
}

//-------------------------------------------------------------------
//--------------------listeRessources--------------------------------
//-------------------------------------------------------------------

/**
@brief Affiches les professeurs, les salles et les formations liés à la liste de ressources
@param[in] lR - un objet de type listeRessources
*/
void afficheurConsole::afficherLesRessources(const listeRessources & lR)
{	afficherLesProfesseurs(lR);
	afficherLesSalles(lR);
	afficherLesFormations(lR);
}

/**
@brief Renvoie dans ost les professeurs de la liste de ressources
@param[in] lR - un objet de type listeRessources
*/
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

/**
@brief Renvoie dans ost les salles de la liste de ressources
@param[in] lR - un objet de type listeRessources
*/
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

/**
@brief Renvoie dans ost les formations de la liste de ressources
@param[in] lR - un objet de type listeRessources
*/
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

int afficheurConsole::ajouterUnProf(listeRessources &lR)
{	string nom;
	afficher("Nom du professeur a ajouter ");
	cin>>nom;
	int dejaPresent=lR.positionProfesseur(nom);
	if (-1==dejaPresent)
	{
		lR.ajouterUnProfesseur(professeur{nom});
		return 0;
	}
	return -1;	//Code Erreur : Prof existe deja
}

int afficheurConsole::supprimerUnProf(listeRessources &lR, const listeCours & lC)
{	string nom;
	afficherLesProfesseurs(lR);
	afficher("Nom du professeur a supprimer ");
	cin>>nom;
	int position=lR.positionProfesseur(nom);
	if (-1==position) 					return -1;	//Code Erreur : Prof n'existe pas
	if (lR.professeurAUnCours(lC,nom))	return -2;	//Code Erreur : Le prof est requis pour un cours
	lR.supprimerUnProfesseur(nom);
	return 0;
}

int afficheurConsole::ajouterUneSalle(listeRessources &lR)
{	string nom;
	afficher("Nom de la salle a ajouter ");
	cin>>nom;
	int dejaPresent=lR.positionSalle(nom);
	if (-1==dejaPresent)
	{
		int taille;
		afficher("Taille de la salle ");
		cin>>taille;
		lR.ajouterUneSalle(salle{nom,taille});
		return 0;
	}
	return -1;	//Code Erreur : Salle existe deja
}

int afficheurConsole::supprimerUneSalle(listeRessources &lR, const listeCours & lC)
{	string nom;
	afficherLesSalles(lR);
	afficher("Nom de la salle a supprimer ");
	cin>>nom;
	int position=lR.positionSalle(nom);
	if (-1==position) 					return -1;	//Code Erreur : Salle n'existe pas
	if (lR.salleAUnCours(lC,nom))	return -2;	//Code Erreur : Salle est requis pour un cours
	lR.supprimerUneSalle(nom);
	return 0;
}

int afficheurConsole::ajouterUneFormation(listeRessources &lR)
{	string nom;
	afficher("Nom de la formation a ajouter ");
	cin>>nom;
	int dejaPresent=lR.positionFormation(nom);
	if (-1==dejaPresent)
	{
		int taille;
		afficher("Nombre d'etudiants dans la formation ");
		cin>>taille;
		lR.ajouterUneFormation(formation{nom,taille});
		return 0;
	}
	return -1;	//Code Erreur : Formation existe deja
}

int afficheurConsole::supprimerUneFormation(listeRessources &lR, const listeCours & lC)
{	string nom;
	afficherLesFormations(lR);
	afficher("Nom de la formation a supprimer ");
	cin>>nom;
	int position=lR.positionFormation(nom);
	if (-1==position) 					return -1;	//Code Erreur : Formation n'existe pas
	if (lR.formationAUnCours(lC,nom))	return -2;	//Code Erreur : Formation est requis pour un cours
	lR.supprimerUneFormation(nom);
	return 0;
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

/**
@brief Renvoie dans ost les cours concernant le professeur
@param[in] professeur - un objet de type professeur
@param[in] lC - un objet de type listeCours
@param[in] semaine - un objet de type int
*/
void afficheurConsole::afficherParProfesseur(const professeur& professeur, const listeCours& lC, int semaine = -1)
{
	*d_ost << "Liste des cours du professeur " << professeur.nom();
	if (semaine > 0)
		*d_ost << " pour la semaine " << semaine;
	*d_ost << std::endl;
	if (!lC.nombreDeCours()) *d_ost << "...Aucun cours enregistre pour cette personne" << std::endl;
	else
	{
		for (int i = 0; i < T_AFFICHAGE; i++) *d_ost << "_";
		*d_ost << endl;
		*d_ost << "Semaine | Jour     | Horaire       | Professeur      | Formation                         | Salle                      |" << endl;
		for (int i = 0; i<T_AFFICHAGE; i++) *d_ost << "-";
		*d_ost << endl;
		for (int i = 0; i<lC.nombreDeCours(); ++i)
		{
			if (lC.coursNumero(i).professeurDuCours() == professeur)
			{
				if (semaine == -1 || lC.coursNumero(i).horaireDuCours().semaine() == semaine)
				{
					afficherCours(lC.coursNumero(i));
					*d_ost << std::endl;
				}
			}
		}
		for (int i = 0; i<T_AFFICHAGE; i++) *d_ost << "-";
		*d_ost << endl;
	}
}

/**
@brief Renvoie dans ost les cours concernant la formation
@param[in] formation - un objet de type formation
@param[in] lC - un objet de type listeCours
@param[in] semaine - un objet de type int
*/
void afficheurConsole::afficherParFormation(const formation& formation, const listeCours& lC, int semaine)
{
	*d_ost << "Liste des cours de la formation " << formation.nom();
	if (semaine > 0)
		*d_ost << " pour la semaine " << semaine;
	*d_ost << std::endl;
	if (!lC.nombreDeCours()) *d_ost << "...Aucun cours enregistre pour cette formation" << std::endl;
	else
	{
		for (int i = 0; i < T_AFFICHAGE; i++) *d_ost << "_";
		*d_ost << endl;
		*d_ost << "Semaine | Jour     | Horaire       | Professeur      | Formation                         | Salle                      |" << endl;
		for (int i = 0; i<T_AFFICHAGE; i++) *d_ost << "-";
		*d_ost << endl;
		for (int i = 0; i<lC.nombreDeCours(); ++i)
		{
			if (lC.coursNumero(i).formationDuCours() == formation)
			{
				if (semaine == -1 || lC.coursNumero(i).horaireDuCours().semaine() == semaine)
				{
					afficherCours(lC.coursNumero(i));
					*d_ost << std::endl;
				}
			}
		}
		for (int i = 0; i<T_AFFICHAGE; i++) *d_ost << "-";
		*d_ost << endl;
	}
}

/**
@brief Renvoie dans ost les cours concernant la salle
@param[in] salle - un objet de type salle
@param[in] lC - un objet de type listeCours
@param[in] semaine - un objet de type int
*/
void afficheurConsole::afficherParSalle(const salle& salle, const listeCours& lC, int semaine)
{
	*d_ost << "Liste des cours de la salle " << salle.nom();
	if (semaine > 0)
		*d_ost << " pour la semaine " << semaine;
	*d_ost << std::endl;
	if (!lC.nombreDeCours()) *d_ost << "...Aucun cours enregistre pour cette salle" << std::endl;
	else
	{
		for (int i = 0; i < T_AFFICHAGE; i++) *d_ost << "_";
		*d_ost << endl;
		*d_ost << "Semaine | Jour     | Horaire       | Professeur      | Formation                         | Salle                      |" << endl;
		for (int i = 0; i<T_AFFICHAGE; i++) *d_ost << "-";
		*d_ost << endl;
		for (int i = 0; i<lC.nombreDeCours(); ++i)
		{
			if (lC.coursNumero(i).salleDuCours() == salle)
			{
				if (semaine == -1 || lC.coursNumero(i).horaireDuCours().semaine() == semaine)
				{
					afficherCours(lC.coursNumero(i));
					*d_ost << std::endl;
				}
			}
		}
		for (int i = 0; i<T_AFFICHAGE; i++) *d_ost << "-";
		*d_ost << endl;
	}
}

int afficheurConsole::afficherCoursDuProf(const listeRessources &lR,const listeCours& lC)
{	string nom;
	afficherLesProfesseurs(lR);
	afficher("Nom du professeur dont on veut afficher l'emploi du temps ");
	cin>>nom;
	int position=lR.positionProfesseur(nom);
	if (-1==position) 					return -1;	//Code Erreur : Prof n'existe pas
	if (lC.nombreDeCours()<1)			return -2;	//Code Erreur : Pas de cours
	afficher("Semaine a afficher (-1 pour toutes) ");
	int semaine;
	cin>>semaine;
	afficherParProfesseur(lR.professeurNumero(position),lC,semaine);
	system("pause");
	return 0;
}

int afficheurConsole::afficherCoursDeSalle(const listeRessources &lR,const listeCours& lC)
{	string nom;
	afficherLesSalles(lR);
	afficher("Nom de la salle dont on veut afficher l'emploi du temps ");
	cin>>nom;
	int position=lR.positionSalle(nom);
	if (-1==position) 					return -1;	//Code Erreur : Salle n'existe pas
	if (lC.nombreDeCours()<1)			return -2;	//Code Erreur : Pas de cours
	afficher("Semaine a afficher (-1 pour toutes) ");
	int semaine;
	cin>>semaine;
	afficherParSalle(lR.salleNumero(position),lC,semaine);
	system("pause");
	return 0;
}

int afficheurConsole::afficherCoursDeFormation(const listeRessources &lR,const listeCours& lC)
{	string nom;
	afficherLesFormations(lR);
	afficher("Nom de la formation dont on veut afficher l'emploi du temps ");
	cin>>nom;
	int position=lR.positionFormation(nom);
	if (-1==position) 					return -1;	//Code Erreur : Formation n'existe pas
	if (lC.nombreDeCours()<1)			return -2;	//Code Erreur : Pas de cours
	afficher("Semaine a afficher (-1 pour toutes) ");
	int semaine;
	cin>>semaine;
	afficherParFormation(lR.formationNumero(position),lC,semaine);
	system("pause");
	return 0;
}

/**
@brief Renvoie dans ost les cours concernant toutes les ressources mises en paramètre
@param[in] r - un objet de type vecteur de ressource
@param[in] lC - un objet de type listeCours
*/
void afficheurConsole::afficherParRessources(const std::vector<ressource> &r, const listeCours &lC)
{
	bool conditions;
	if (r.size() != 0)
	{
		*d_ost << "Liste des cours avec les conditions :";
		for (int i = 0; i < r.size(); i++)
			*d_ost << " - " << r[i].nom();
		*d_ost << std::endl;

		for (int i = 0; i < T_AFFICHAGE; i++) *d_ost << "_";
		*d_ost << endl;
		*d_ost << "Semaine | Jour     | Horaire       | Professeur      | Formation                         | Salle                      |" << endl;
		for (int i = 0; i<T_AFFICHAGE; i++) *d_ost << "-";
		*d_ost << endl;
		for (int i = 0; i<lC.nombreDeCours(); ++i)
		{
			conditions = true;
			for (int j = 0; j < r.size() && conditions; j++)
			{
				if (r[j] != lC.coursNumero(i).formationDuCours() && r[j] != lC.coursNumero(i).professeurDuCours() && r[j] != lC.coursNumero(i).salleDuCours())
					conditions = false;
			}
			if (conditions)
			{
				afficherCours(lC.coursNumero(i));
				*d_ost << std::endl;
			}
		}
		for (int i = 0; i<T_AFFICHAGE; i++) *d_ost << "-";
		*d_ost << endl;
	}
}
