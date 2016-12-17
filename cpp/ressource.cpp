#include "../lib/ressource.h"

ressource::ressource(const string nom):d_nom{nom} {}

string ressource::nom() const {return d_nom;}
