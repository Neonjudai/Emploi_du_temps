#ifndef FORMATION_H
#define FORMATION_H

class formation{
	public:
		formation(const string & nom, int nombreDEtudiants);
		std::string nom() const;
		int nombreDEtudiants() const;
	private:
		std::string d_nomFormation;
		int d_nombreDEtudiants;
};

#endif
