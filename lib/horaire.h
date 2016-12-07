#ifndef HORAIRE_H
#define HORAIRE_H

class horaire{
	public:
		horaire() =delete;
		horaire(int numeroSemaine, int numeroHeure);
		horaire(const horaire & unHoraire);
		
		void changerSemaine(int numeroSemaine);
		void changernumeroHeure(int numeroHeure);
		
		int numeroSemaine() const;
		int numeroHeure() const;
		
		bool operator<(const horaire & unHoraire) const;
		bool operator<=(const horaire & unHoraire) const;
		bool operator==(const horaire & unHoraire) const;
		bool operator>=(const horaire & unHoraire) const;
		bool operator>(const horaire & unHoraire) const;
	private:
		int d_numeroSemaine;
		int d_numeroHeure;
};

#endif
