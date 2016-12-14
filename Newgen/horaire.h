#ifndef HORAIRE_H
#define HORAIRE_H

class horaire{	
	public:
		horaire() =delete;
		horaire(int semaine,int jour, int heure);
		horaire(const horaire & unHoraire);
		
		//SET
		void changerSemaine(int semaine);
		void changerJour(int semaine);
		void changerHeure(int heure);
		
		//GET
		int semaine() const;
		int jour() const;
		int heure() const;
		
		//OPERATION
		bool operator< (const horaire & unHoraire) const;
		bool operator<=(const horaire & unHoraire) const;
		bool operator==(const horaire & unHoraire) const;
		bool operator>=(const horaire & unHoraire) const;
		bool operator> (const horaire & unHoraire) const;
	private:
		int d_semaine;
		int d_jour;
		int d_heure;
};
#endif
