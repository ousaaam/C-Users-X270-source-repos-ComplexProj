#include "Bibliotheque.h"
int Bibliotheque::nbLivres=0;
int Bibliotheque::capacite = 10;

Bibliotheque::Bibliotheque(const Bibliotheque& B){
	this->nom = B.nom;
	this->capacite = B.capacite;
	this->nbLivres = B.nbLivres;
	Livres = new Livre*[capacite];

	for (int i = 0; i < capacite; i++){
		Livres[i] = B.Livres[i];
	}
}

Bibliotheque Bibliotheque::operator=(const Bibliotheque& B){
	if (this != &B) {
		for (int i = 0; i < capacite; i++)
			delete Livres[i];
		
		delete[] Livres;

		nom = B.nom;
		capacite = B.capacite;
		nbLivres = B.nbLivres;

		Livres = new Livre * [capacite];

		for (int i = 0; i < nbLivres; i++)
			Livres[i] = new Livre(*B.Livres[i]);
		}

		return *this;
}

Bibliotheque Bibliotheque::operator+=(const Livre& L){
	ajouterLivre(L);
	return *this;
}

Livre Bibliotheque::ajouterLivre(const Livre& L)
{
	if (nbLivres == capacite){
		capacite *= 2;

		Livre** nouveau = new Livre * [capacite];

		for (int i = 0; i < nbLivres; i++)
			nouveau[i] = Livres[i];

		delete[] Livres;
		Livres = nouveau;
	}

	Livres[nbLivres] = new Livre(L);

	nbLivres++;

	return *Livres[nbLivres - 1];
}

Bibliotheque::~Bibliotheque(){
	for (int i = 0; i < nbLivres; i++)
	{
		delete Livres[i];
	}
	delete[] Livres;
}
