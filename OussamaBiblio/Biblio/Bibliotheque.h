#pragma once
#include<iostream>
#include"Livre.h"
using namespace std;
class Bibliotheque:Livre {
private:
	string nom;
	Livre** Livres;
	static int nbLivres, capacite;
public:
	Bibliotheque(const Bibliotheque&);
	Bibliotheque operator=(const Bibliotheque&);
	Bibliotheque operator+=(const Livre&);
	void rechercher(string);
	Livre ajouterLivre(const Livre&);
	~Bibliotheque();
	
};

