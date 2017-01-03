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

using std::string;

class salle: public ressource{
	friend class ressource;
    public:
        salle() =delete;
        salle (string nomSalle, int taille);
        salle(const salle & p) =default;

        //SET
        void changerNombrePlaces( int val);

        //GET
        int nombrePlaces() const;
        
		friend std::ostream& operator<<(std::ostream & ost, const salle & s);

    private:
        int d_nombrePlaces;
};

#endif // SALLE_H
