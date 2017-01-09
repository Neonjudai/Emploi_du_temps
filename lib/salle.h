#ifndef SALLE_H
/**
 * @file salle.h
 * @brief Classe permettant la gestion des salles
 * @author Olivier Ettlin
 * @version 1.0
 */

#define SALLE_H
#include <string>
#include "ressource.h"


class salle: public ressource{
    public:
        salle() =delete;
        salle (const string & nomSalle, int taille);
        salle(const salle & s)=default;

        //SET
        void changerNombrePlaces( int val);

        //GET
        int nombrePlaces() const;

    private:
        int d_nombrePlaces;
};

#endif // SALLE_H
