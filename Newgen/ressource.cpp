#include "ressource.h"

ressource::ressource(const string nom):d_nomDeLaRessource{nom} {}

string ressource::nom() const {return d_nomDeLaRessource;}
