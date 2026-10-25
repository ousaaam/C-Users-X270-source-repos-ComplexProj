#include "Commande.h"
#include <iostream>
using namespace std;
int static compteur = 0;

Commande::Commande(string name, int size): id(compteur + 1){
	this->sommairePrix = new double[size];
	this->name = name;
	this->compteur++;
	this->taille = size;
	this->nombreArticles = 0;
}

void Commande::ajouterArticle(double prix){
	if (prix > 0 && this->nombreArticles < this->taille) {
		this->sommairePrix[this->nombreArticles] = prix;
		this->nombreArticles++;
	}
}
void Commande::calculerTotal()  {
		total = 0;
		for (int i = 0;i < nombreArticles;i++) {
			total += sommairePrix[i];
		}
	}

void Commande::afficher() const{
	cout << "Votre id:" <<id<< endl;
	cout << "Bonjour Mr:" <<name<< endl;
	cout << "Les Aricles Commandee :" << nombreArticles<< endl;
	for (int i = 0;i < nombreArticles;i++) {
		cout << "Prix d'article" << i + 1 << ":" << sommairePrix[i] << endl;
	}
}

Commande::~Commande(){
	this->compteur--;
	delete[] this->sommairePrix;
	this->sommairePrix = nullptr;
}
