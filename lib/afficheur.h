#ifndef AFFICHEUR_H
#define AFFICHEUR_H
#include "horaire.h"
#include "cours.h"
#include "professeur.h"

using std::ostream;

class afficheur
{
    public:
        afficheur()=default;
        virtual ~afficheur();
        virtual void afficheSemaine(const horaire * h, ostream & ost)=0;
        virtual void afficheHeure(const horaire * h, ostream & ost)=0;
        virtual void afficheJour(const horaire * h, ostream & ost)=0;
        virtual void afficheHoraire(const horaire * h, ostream & ost)=0;
        virtual void afficheProfesseur(const professeur * p, ostream & ost)=0;
        virtual void afficheCours(const cours * c, ostream & ost)=0;
    protected:
    private:
};

#endif // AFFICHEUR_H
