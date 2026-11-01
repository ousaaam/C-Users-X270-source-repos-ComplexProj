#pragma once
#include <iostream>
#include <string>
#include "Livre.h"

using namespace std;

class Bibliotheque {
private:
    string nom;
    int capacite;
    int nbLivres;

    Livre** livres;

public:
    Bibliotheque(string n, int c);
    ~Bibliotheque();
    Bibliotheque operator+=(const Livre& );
    Bibliotheque operator=(const Bibliotheque&);
    void ajouterLivre(const Livre& L);
    Livre* rechercherParTitre(string t) const;
    Livre* rechercherParId(int id) const;
    void afficherCatalogue() const;
    void afficherLivre(string t) const;
};


