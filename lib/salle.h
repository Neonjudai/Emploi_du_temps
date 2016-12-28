#ifndef SALLE_H
#define SALLE_H
#include <string>

using std::string;

class salle
{
    public:
        salle()=delete;
        salle (string d_nomSalle);
       // salle (int nombrePlaces, string nomSalle, string nomBatiment);

        //SET
        //void changernombrePlaces( int val);
        void changernomSalle(string val);
        //void changernomBatiment(string val);

        //GET
        //int nombrePlaces() const { return d_nombrePlaces; }
        string nomSalle() const;
       // string nomBatiment() const { return d_nomBatiment; }

    protected:
    private:
        // int d_nombrePlaces;
        string d_nomSalle;
        //string d_nomBatiment;
};

#endif // SALLE_H
