#ifndef HORAIRE_H
#define HORAIRE_H

class horaire{
	public:
		horaire(int numeroSemaine, int numeroHeure);
		int numeroSemaine() const;
		int numeroHeure() const;
	private:
		int d_numeroSemaine;
		int d_numeroHeure;
};

#endif
