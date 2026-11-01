#pragma once
#include <string>
#include "Date.h"


class Livre {
private:
    const int idLivre;

    string titre;
    string auteur;
    Date dateParution;

    int* notes;
    int nbNotes;

    static int prochainId;
    static int nbLivres;

public:
    Livre(string t, string a, Date d);
    Livre(const Livre& L);
    ~Livre();
    Livre operator=(const Livre& L);
    void ajouterNote(int note);
    float calculerMoyenne() const;
    void afficher() const;
    int getId() const;
    string getTitre() const;
    static int getNombreLivres();
};

