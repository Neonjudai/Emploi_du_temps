#include "../lib/gestionFichier.h"

gestionFichier::gestionFichier(const std::string &nomFichier) : d_nomFichier{nomFichier}
{}


void gestionFichier::viderLeFichier()
{
	ofstream ecriture;
	ecriture.open(d_nomFichier.c_str(), std::ofstream::out | std::ofstream::trunc);
	ecriture.close();
}

bool gestionFichier::lectureDesDonnees(listeCours &LC, listeRessources &LR)
{
	bool fonctionne;
	ifstream lecture(d_nomFichier.c_str());
	if (lecture.good())
		fonctionne = lectureDesRessources(LR, lecture);
	lecture.close();
	lecture.open(d_nomFichier.c_str());
	if (lecture.good())
		fonctionne = lectureDesCours(LC,LR, lecture);
	if (lecture.is_open())
		lecture.close();
	return fonctionne;
}

bool gestionFichier::lectureDesRessources(listeRessources &LR, ifstream &lecture)
{
	char curseur;
	string lectureMot = "";
	int valeurSupplementaire;
	if (lecture.good())
		while (lecture.good())
		{
			lecture >> lectureMot;
			if (lectureMot == "formation")
			{
				lecture >> lectureMot >> valeurSupplementaire;
				LR.ajouterUneFormation({ lectureMot,valeurSupplementaire });
			}
			else if (lectureMot == "professeur")
			{
				lecture >> lectureMot;
				LR.ajouterUnProfesseur({ lectureMot });
			}
			else if (lectureMot == "salle")
			{
				lecture >> lectureMot >> valeurSupplementaire;
				LR.ajouterUneSalle({ lectureMot, valeurSupplementaire });
			}
		}
	else
		return false;
	return true;
}

bool gestionFichier::lectureDesCours(listeCours &LC, listeRessources &LR, ifstream &lecture)
{
	string lectureMot = "", nomformation, nomprofesseur, nomsalle;
	int semaine, jour, heure;
	if (lecture.good())
	{
		lecture >> lectureMot;
		while (lecture.good() && !(lecture.eof()))
		{
			
			if (lectureMot == "cours")
			{
				lecture >> semaine >> jour >> heure >> nomformation >> nomprofesseur >> nomsalle;
				LC.ajouterUnCours({ {semaine,jour,heure},
									LR.professeurNumeroP(LR.positionProfesseur(nomprofesseur)),
									LR.salleNumeroP(LR.positionSalle(nomsalle)),
									LR.formationNumeroP(LR.positionFormation(nomformation))
								});
			}
			lecture >> lectureMot;
		}
	}
		
	else
		return false;
	return true;
}


bool gestionFichier::ecritureDesCours(const listeCours & LC, ofstream &ecriture)
{
	ecriture << "//Cours Nsemaine Njour(0-6) Nheure(1-4) 'nomformation' 'nomprofesseur' 'nomsalle'" << endl;
	for (int CoursN = 0; CoursN < LC.nombreDeCours(); CoursN++)
	{
		ecriture << "cours " << LC.coursNumero(CoursN).horaireDuCours().semaine() << ' ' << LC.coursNumero(CoursN).horaireDuCours().jour() << ' ' << LC.coursNumero(CoursN).horaireDuCours().heure() << ' ';
		ecriture << " " << LC.coursNumero(CoursN).formationDuCours().nom() << " " << LC.coursNumero(CoursN).professeurDuCours().nom() << " " << LC.coursNumero(CoursN).salleDuCours().nom() << " " << endl;
	}
	return ecriture.good();
}

bool gestionFichier::ecritureDesRessources(const listeRessources & LR, ofstream &ecriture)
{
	ecriture << "//Formation 'nomformation' NbEleve" << endl;
	for (int FormationN = 0; FormationN < LR.nombreDeFormations(); FormationN++)
	{
		ecriture << "formation " << LR.formationNumero(FormationN).nom() << " " << LR.formationNumero(FormationN).nombreEtudiant() << endl;
	}
	ecriture << endl << "//Professeur 'nomprofesseur'" << endl;
	for (int ProfesseurN = 0; ProfesseurN < LR.nombreDeProfesseurs(); ProfesseurN++)
	{
		ecriture << "professeur " << LR.professeurNumero(ProfesseurN).nom() << " " << endl;
	}
	ecriture << endl << "//Salle 'nomsalle' NbPlaces" << endl;
	for (int SalleN = 0; SalleN < LR.nombreDeSalles(); SalleN++)
	{
		ecriture << "salle " << LR.salleNumero(SalleN).nom() << " " << LR.salleNumero(SalleN).nombrePlaces() << endl;
	}
	return ecriture.good();
}

bool gestionFichier::ecritureDesDonnees(const listeCours & LC, const  listeRessources & LR)
{
	bool fonctionne;
	viderLeFichier();
	ofstream ecriture(d_nomFichier.c_str());
	if (ecriture.good())
	{
		ecriture << "// INFO : Stockage des données" << endl;
		fonctionne = ecritureDesRessources(LR, ecriture);
		ecriture << endl;
		fonctionne = fonctionne && ecritureDesCours(LC, ecriture);
	}
	if (ecriture.is_open())
		ecriture.close();
	return fonctionne;
}
