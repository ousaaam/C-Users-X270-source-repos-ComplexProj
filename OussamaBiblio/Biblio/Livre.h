#pragma once
#include"Bibliotheque.h"
#include"Date.h"
class Livre:Date{
private:
    int id;
    string auteur, titre;
    Date parution;
	int* notes; 
	int nbNotes;
	int capacite;
	static int Compteurid, nbInstances;
public:
	Livre(const int, string,string,Date,int *,int );
	Livre(const Livre&);
	Livre operator=(const Livre&);
	float moyenne(float );
	bool EnregistrerNotes(int note);
	void afficherLivre()const;
	~Livre();
};

