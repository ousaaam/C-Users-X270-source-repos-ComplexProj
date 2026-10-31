#include "Livre.h"
 int Livre::Compteurid = 0;
int Livre::nbInstances = 0;

Livre::Livre(const int id, const string auteur, const string t,const Date par, int* notes, int nbNotes)
	:id(++Compteurid), auteur(auteur), titre(titre),
	parution(par), notes(nullptr), nbNotes(0){
	nbInstances++;

}

Livre::Livre(const Livre& L) {
	id = L.id;
	auteur = L.auteur;
	titre = L.titre;
	parution = L.parution;
	nbNotes = L.nbNotes;
	capacite = L.capacite;
	this->notes = new int[capacite];
	for (int i = 0; i < capacite; i++) {
		notes[i] = L.notes[i];
	}
	nbInstances++;
	Compteurid++;
}

Livre Livre::operator=(const Livre& L) {
	if (this != &L) {
		delete[] notes;
		id = L.id;
		auteur = L.auteur;
		titre = L.titre;
		parution = L.parution;

		nbNotes = L.nbNotes;
		capacite = L.capacite;

		notes = new int[capacite];
	for (int i = 0; i < nbNotes; i++)
			notes[i] = L.notes[i];
	}

	return *this;
}

float Livre::moyenne(float nbNotes){
	if (nbNotes == 0)
		return 0;
	float somme = 0;
	for (int i = 0; i < nbNotes; i++){
		somme = somme+notes[i];
		}
	 return somme/ (float)nbNotes;
}

bool Livre::EnregistrerNotes(int note){
	if (note < 0 || note > 20) {
		cout << "La note doit etre Compris entre 0 et 20:" << endl; 
			return false;
	}else {
		for (int i = 0; i < nbNotes; i++) {
			notes[i] = note;
			return true;
		}
	}
}

void Livre::afficherLivre()const {

	cout << "Livre :" << this->titre << endl;
	cout << "Auteur :" << this->auteur << endl;
	cout << "Date de Parution :" << endl;
	parution.afficherDate();
	cout << "Notes :" << endl;
	for (int i = 0; i < nbNotes; i++){
		cout << notes[i] << " " << endl;
	}
	cout << "Moyenne"  <<moyenne()<< endl;

}

Livre::~Livre(){
	delete[] notes;
	notes = nullptr;
	nbInstances--;
}