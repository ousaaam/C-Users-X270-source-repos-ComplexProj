#pragma once
#include "Voiture.h"
class Moteur {
private:
	int puissance;
	int anne;
public:
	Moteur(int, int);
	void afficher() const ;
	~Moteur();
};


