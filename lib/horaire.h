#ifndef HORAIRE_H
#define HORAIRE_H

#include <iostream>
#include <iomanip>

class horaire{
	
	public:
		horaire() =delete;
		horaire(int semaine,int jour, int heure);
		horaire(const horaire & unHoraire) =default;
		
		//SET
		void changerSemaine(int semaine);
		void changerJour(int jour);
		void changerheure(int heure);
		
		//GET
		int semaineNumero() const;
		int jourNumero() const;
		int heureNumero() const;
		
		int semaine() const;
		std::string jour() const;
		std::string heure() const;
		
		//OPERATION
		bool operator< (const horaire & unHoraire) const;
		bool operator<=(const horaire & unHoraire) const;
		bool operator==(const horaire & unHoraire) const;
		bool operator>=(const horaire & unHoraire) const;
		bool operator> (const horaire & unHoraire) const;
	
		friend std::ostream& operator<<(std::ostream & ost, const horaire & h);
		
	private:
		int d_semaine;
		int d_jour;
		int d_heure;
};
#endif
