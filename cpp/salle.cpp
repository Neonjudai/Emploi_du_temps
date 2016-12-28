#include "../lib/salle.h"

using std::string;

//salle::salle (int nombrePlaces, string nomSalle, string nomBatiment): d_nombrePlaces{nombrePlaces}, d_nomSalle{nomSalle}, d_nomBatiment{nomBatiment}
//{}

salle::salle (string nomSalle): d_nomSalle{nomSalle}
{}

//SET
//void salle::changernombrePlaces( int val) { d_nombrePlaces = val; }
void salle::changernomSalle(string val) { d_nomSalle = val; }
//void salle::changernomBatiment(string val) { d_nomBatiment = val; }

//GET
//int salle::nombrePlaces() const { return d_nombrePlaces; }
string salle::nomSalle() const { return d_nomSalle; }
//string salle::nomBatiment() const { return d_nomBatiment; }
