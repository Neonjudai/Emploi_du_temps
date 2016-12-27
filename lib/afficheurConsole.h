#ifndef AFFICHEURCONSOLE_H
#define AFFICHEURCONSOLE_H
#include "horaire.h"
#include "cours.h"
#include "professeur.h"
#include "afficheur.h"

using std::ostream;

class afficheurConsole : public afficheur{
    public:
        afficheurConsole()=default;
        virtual ~afficheurConsole();
        virtual void afficheSemaine(const horaire * h, ostream & ost) override;
        virtual void afficheHeure(const horaire * h, ostream & ost)override;
        virtual void afficheJour(const horaire * h, ostream & ost)override;
        virtual void afficheHoraire(const horaire * h, ostream & ost)override;
        virtual void afficheProfesseur(const professeur * p, ostream & ost)override;
        virtual void afficheCours(const cours * c, ostream & ost)override;  // à faire après que les getters de cours ne bug plus
    protected:
    private:
};

#endif // AFFICHEURCONSOLE_H
