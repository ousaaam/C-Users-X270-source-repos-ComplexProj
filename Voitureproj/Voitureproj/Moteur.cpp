#include "Moteur.h"
#include<iostream>
Moteur::Moteur(int p, int a) {
	this->puissance = p;
	this->anne = a;

};

void Moteur::afficher()const {
	std::cout << "puissance = " << this->puissance << std::endl;
	std::cout << "anne = " << this->anne << std::endl;
}

Moteur::~Moteur() {	

}