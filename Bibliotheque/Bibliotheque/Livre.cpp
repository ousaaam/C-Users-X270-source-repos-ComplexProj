#include "Livre.h"

int Livre::prochainId = 1;
int Livre::nbLivres = 0;

Livre::Livre(string t, string a, Date d)
    : idLivre(prochainId++), dateParution(d) {

    titre = t;
    auteur = a;

    notes = nullptr;
    nbNotes = 0;

    nbLivres++;

    cout << "Construction du livre : " << titre << endl;
}

Livre::Livre(const Livre& L)
    : idLivre(prochainId++), dateParution(L.dateParution) {

    titre = L.titre;
    auteur = L.auteur;

    nbNotes = L.nbNotes;

    if (nbNotes > 0) {
        notes = new int[nbNotes];

        for (int i = 0; i < nbNotes; i++) {
            notes[i] = L.notes[i];
        }
    }
    else {
        notes = nullptr;
    }

    nbLivres++;

    cout << "Copie du livre : " << titre << endl;
}

Livre::~Livre() {
    delete[] notes;

    nbLivres--;

    cout << "Destruction du livre : " << titre << endl;
}

Livre Livre::operator=(const Livre& L) {

    if (this != &L) {

        titre = L.titre;
        auteur = L.auteur;
        dateParution = L.dateParution;

        int* nouveau = nullptr;

        if (L.nbNotes > 0) {

            nouveau = new int[L.nbNotes];

            for (int i = 0; i < L.nbNotes; i++) {
                nouveau[i] = L.notes[i];
            }
        }

        delete[] notes;

        notes = nouveau;
        nbNotes = L.nbNotes;
    }

    return *this;
}
void Livre::ajouterNote(int note) {
    if (note < 0 || note > 20) {
        cout << "Note invalide ! Elle doit etre entre 0 et 20."
            << endl;
        return;
    }

    int* nouveau = new int[nbNotes + 1];

    for (int i = 0; i < nbNotes; i++) {
        nouveau[i] = notes[i];
    }

    nouveau[nbNotes] = note;

    delete[] notes;

    notes = nouveau;

    nbNotes++;

    cout << "Note ajoutee avec succes." << endl;
}

float Livre::calculerMoyenne() const {
    if (nbNotes == 0)
        return 0;

    float somme = 0;

    for (int i = 0; i < nbNotes; i++) {
        somme += notes[i];
    }

    return somme / nbNotes;
}

void Livre::afficher() const {
    cout << "\n---------- INFORMATIONS DU LIVRE ----------"
        << endl;

    cout << "ID : " << idLivre << endl;
    cout << "Titre : " << titre << endl;
    cout << "Auteur : " << auteur << endl;

    cout << "Date de parution : ";
    dateParution.afficher();
    cout << endl;

    cout << "Notes : ";

    if (nbNotes == 0) {
        cout << "Aucune note";
    }
    else {
        for (int i = 0; i < nbNotes; i++) {
            cout << notes[i] << " ";
        }
    }

    cout << endl;

    cout << "Moyenne : " << calculerMoyenne() << endl;

    cout << "------------------------------------------"
        << endl;
}

int Livre::getId() const {
    return idLivre;
}

string Livre::getTitre() const {
    return titre;
}

int Livre::getNombreLivres() {
    return nbLivres;
}
