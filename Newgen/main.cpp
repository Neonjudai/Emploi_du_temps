#include <iostream>

#include "ressource.h"
#include "cours.h"
#include "listeCours.h"

int main()
{
	professeur p1{"M. Le Grand"};
	cours c1{1,2,p1};
	listeCours l;
	l.ajouterUnCours(c1);
	l.ajouterUnCours({1,4,p1});
	l.direConsole(std::cout);
}
