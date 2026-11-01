#include "Bibliotheque.h"

Bibliotheque::Bibliotheque(string n, int c) {
    nom = n;

    if (c > 0)
        capacite = c;
    else
        capacite = 1;

    nbLivres = 0;

    livres = new Livre * [capacite];

    cout << "Creation de la bibliotheque : "
        << nom << endl;
}

Bibliotheque::~Bibliotheque() {
    for (int i = 0; i < nbLivres; i++) {
        delete livres[i];
    }

    delete[] livres;

    cout << "Destruction de la bibliotheque : "
        << nom << endl;
}

void Bibliotheque::ajouterLivre(const Livre& L) {
    if (nbLivres >= capacite) {
        cout << "Capacite maximale atteinte !"
            << endl;
        return;
    }

    livres[nbLivres] = new Livre(L);

    nbLivres++;

    cout << "Livre ajoute a la bibliotheque."
        << endl;
}

Livre* Bibliotheque::rechercherParTitre(string t) const {
    for (int i = 0; i < nbLivres; i++) {
        if (livres[i]->getTitre() == t) {
            return livres[i];
        }
    }

    return nullptr;
}

Livre* Bibliotheque::rechercherParId(int id) const {
    for (int i = 0; i < nbLivres; i++) {
        if (livres[i]->getId() == id) {
            return livres[i];
        }
    }

    return nullptr;
}

void Bibliotheque::afficherCatalogue() const {
    cout << "\n========== CATALOGUE =========="
        << endl;

    cout << "Bibliotheque : " << nom << endl;

    cout << "Nombre de livres : "
        << nbLivres << "/" << capacite << endl;

    for (int i = 0; i < nbLivres; i++) {
        livres[i]->afficher();
    }

    cout << "================================"
        << endl;
}

void Bibliotheque::afficherLivre(string t) const {
    Livre* L = rechercherParTitre(t);

    if (L != nullptr) {
        L->afficher();
    }
    else {
        cout << "Livre introuvable !" << endl;
    }
}

Bibliotheque Bibliotheque::operator+=(const Livre& L) {

    if (nbLivres >= capacite) {

        cout << "Capacite maximale atteinte !" << endl;

        return *this;
    }

    livres[nbLivres] = new Livre(L);

    nbLivres++;

    cout << "Livre ajoute avec succes." << endl;

    return *this;
}
Bibliotheque Bibliotheque::operator=(const Bibliotheque& B) {

    if (this != &B) {

        for (int i = 0; i < nbLivres; i++) {
            delete livres[i];
        }

        delete[] livres;

        nom = B.nom;
        capacite = B.capacite;
        nbLivres = B.nbLivres;

        livres = new Livre * [capacite];

        for (int i = 0; i < nbLivres; i++) {
            livres[i] = new Livre(*B.livres[i]);
        }
    }

    return *this;
}