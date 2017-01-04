/**
 * @file afficheurConsole.h
 * @brief Classe permettant l'affichage en mode console
 * @author Olivier Ettlin
 * @version 1.0
 */

#ifndef AFFICHEURCONSOLE_H
#define AFFICHEURCONSOLE_H

#include "horaire.h"
#include "cours.h"
#include "professeur.h"
#include "afficheur.h"
#include "salle.h"

using std::ostream;

class afficheurConsole{
    public:
        afficheurConsole()=delete;
        afficheurConsole(ostream & ost);
        ~afficheurConsole();
        
        void afficheSemaine	(const horaire & h);
        void afficheHeure	(const horaire & h);
        void afficheJour	(const horaire & h);
        void afficheHoraire	(const horaire & h);
        void afficheProfesseur(const professeur & p);
        void afficheSalle	(const salle & s);
        void afficheCours	(const cours & c);  // à faire après que les getters de cours ne bug plus
    protected:
    private:
    	ostream *d_ost;
};

#endif // AFFICHEURCONSOLE_H
