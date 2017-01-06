/**
 * @file afficheurConsole.h
 * @brief Classe permettant l'affichage en mode console
 * @author Olivier Ettlin
 * @version 1.0
 */

#ifndef AFFICHEURCONSOLE_H
#define AFFICHEURCONSOLE_H

#include "cours.h"
#include "formation.h"
#include "horaire.h"
#include "listeCours.h"
#include "listeDHoraire.h"
#include "listeRessources.h"
#include "professeur.h"
#include "salle.h"

using std::ostream;
using std::endl;

class afficheurConsole{
    public:
        afficheurConsole()=delete;
        afficheurConsole(ostream & ost);
        ~afficheurConsole();
        
        void afficher(string s, int sautLigne = 0);
        
        //Cours
        void afficherCours	(const cours & c);  // Requiert get de cours
        
        //Formation
        void afficherFormation(const formation & f);
        
        //Horaire
        void afficherSemaine	(const horaire & h);
        void afficherHeure	(const horaire & h);
        void afficherJour	(const horaire & h);
        void afficherHoraire	(const horaire & h);
        
        //listeCours
        void afficherLesCours(const listeCours & lC);
        
        //listeDHoraire
                
        //listeRessources
        void afficherLesRessources(const listeRessources & lR);
        void afficherLesProfesseurs(const listeRessources & lR);
        void afficherLesSalles(const listeRessources & lR);
        void afficherLesFormations(const listeRessources & lR);
		        
        //professeur
        void afficherProfesseur(const professeur & p);
        
        //salle
        void afficherSalle	(const salle & s);
    
	protected:
    private:
    	ostream *d_ost;
};

#endif // AFFICHEURCONSOLE_H
