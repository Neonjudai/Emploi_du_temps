#include <iostream>

#include "ressource.h"
#include "cours.h"
#include "listeCours.h"

int main()
{
	listeCours l;
	
	professeur p1{"M. Le Grand"};
	cours c1{1,2,3,p1};
	
	l.ajouterUnCours(c1);
	l.ajouterUnCours({1,2,4,p1});
	
	l.direConsole(std::cout);
}
