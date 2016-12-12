#ifndef HORAIRE_H
#define HORAIRE_H

class professeur;
class formation;
class salle;

class horaire{
	public:
		horaire() =delete;
		horaire(int numeroSemaine, int numeroHeure);	//MaJ
		horaire(const horaire & unHoraire);				//MaJ
		
		//SET
		void changerSemaine(int numeroSemaine);
		void changernumeroHeure(int numeroHeure);
		
		//GET
		int numeroSemaine() const;
		int numeroHeure() const;
		professeur*	professeur() const;					//MaJ
		formation* formation() const;					//MaJ
		salle* salle() const;							//MaJ
		
		//OPERATION
		bool operator<(const horaire & unHoraire) const;
		bool operator<=(const horaire & unHoraire) const;
		bool operator==(const horaire & unHoraire) const;
		bool operator>=(const horaire & unHoraire) const;
		bool operator>(const horaire & unHoraire) const;
	private:
		int d_numeroSemaine;
		int d_numeroHeure;
		professeur* d_professeur;	//MaJ
		 formation* d_formation;	//MaJ
		     salle* d_salle;		//MaJ
};

#endif
