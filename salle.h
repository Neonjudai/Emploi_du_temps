#ifndef SALLE_H
#define SALLE_H

class salle{
	public:
		salle(const string & nom, int nombreDePlace);
		std::string nom() const;
		int nombreDePlace() const;
	private:
		std::string d_nomSalle;
		int d_nombreDePlace;
};

#endif
