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
        salle()=delete;
        salle (string d_nomSalle);
        salle(const salle & p) =default;
       // salle (int nombrePlaces, string nomSalle, string nomBatiment);

        //SET
        //void changernombrePlaces( int val);
        //void changernomSalle(string val);
        //void changernomBatiment(string val);

        //GET
        //int nombrePlaces() const { return d_nombrePlaces; }
       // string nomSalle() const;
       // string nomBatiment() const { return d_nomBatiment; }
       friend std::ostream& operator<<(std::ostream & ost, const salle & s);

    private:
        // int d_nombrePlaces;
       // string d_nomSalle;
        //string d_nomBatiment;
};

#endif // SALLE_H
