#include "../lib/ressource.h"

ressource::ressource(const string & nom):d_nomDeLaRessource{nom} {}

string ressource::nomDeLaRessource() const {return d_nomDeLaRessource;}
