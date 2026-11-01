
#include <iostream>
#include "Date.h"
#include "Livre.h"
#include "Bibliotheque.h"

using namespace std;

int main() {

    cout << "========== DEBUT DU PROGRAMME =========="<< endl;

    Bibliotheque B("Bibliotheque Universitaire", 5);
 
    Date d1(15, 3, 2020);
    Date d2(20, 7, 2022);
    Date d3(10, 12, 2024);
    Date d4(31, 2, 2023);

    cout << "\n--- Creation des livres ---" << endl;

    Livre L1("Book1", "Author1 ", d1);

    Livre L2("Book2", "Author2", d2);

    Livre L3("Book3", "Author3 ", d3);

    cout << "\nNombre de livres existants : "
        << Livre::getNombreLivres() << endl;

    cout << "\n--- Ajout des livres ---" << endl;

    B.ajouterLivre(L1);
    B.ajouterLivre(L2);
    B.ajouterLivre(L3);

    cout << "\n--- Ajout des notes ---" << endl;

    L1.ajouterNote(15);
    L1.ajouterNote(18);
    L1.ajouterNote(12);

    L2.ajouterNote(14);
    L2.ajouterNote(16);

    L3.ajouterNote(19);
    L3.ajouterNote(17);

    cout << "\n--- Recherche par titre ---" << endl;

    B.afficherLivre("Book1");

    B.afficherLivre("Book2");

    cout << "\n--- Recherche par identifiant ---" << endl;

    Livre* resultat = B.rechercherParId(2);

    if (resultat != nullptr)
        resultat->afficher();
    else
        cout << "Livre introuvable !" << endl;

    cout << "\n--- Affichage du catalogue ---" << endl;

    B.afficherCatalogue();

    cout << "\n--- Nombre de livres existants ---" << endl;

    cout << Livre::getNombreLivres() << endl;

    cout << "\n========== FIN DU PROGRAMME =========="
        << endl;

    return 0;
}
