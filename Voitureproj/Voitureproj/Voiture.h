#pragma once
#include "Moteur.h"
class Voiture
{private:
	int ref;
	char color;
	int vitesse;
	char model;
	Moteur* Moteur();
public :
	Voiture();
	Voiture(int, char, int, char);
	void afficher();
	void accelerer(int);
};

