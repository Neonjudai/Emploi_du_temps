#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <iostream>
using std::string;

class ressource{
	public:
		ressource(string nom);
		ressource(const ressource & r) =default;
		//virtual ~ressource()=default;
		string nom() const;

		//virtual std::ostream& operator<<(std::ostream & ost)=0; //, const ressource & r
	private:
		string d_nom;								//Le nom de la ressource
};
#endif
