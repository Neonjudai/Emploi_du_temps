#ifndef PROFESSEUR_H
#define PROFESSEUR_H

class professeur{
	public:
		professeur(const string & nom);
		std::string nom() const;
	private:
		std::string d_nomProfesseur;
};

#endif
