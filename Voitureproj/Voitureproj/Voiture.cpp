#include "Voiture.h"
#include"Moteur.h"
#include<iostream>
Voiture::Voiture() {};
Voiture::Voiture(int r,char c,int v,char m,Moteur*mot)  {
	ref = r;
	color = c;
	vitesse = v;
	model = m;
	

};
void Voiture::afficher() const {
	std::cout << "ref = " << ref << std::endl;
	std::cout << "color = " << color << std::endl;
	std::cout << "vitesse = " << vitesse << std::endl;
	std::cout << "model = " << model << std::endl;

};
void Voiture::accelerer(int a) {
	vitesse = vitesse + a;
}
Voiture::Voiture(const Voiture&v){
	this->ref = v.ref;
	this->color = v.color;
	this->vitesse = v.vitesse;
	this->model = v.model;
	
};


