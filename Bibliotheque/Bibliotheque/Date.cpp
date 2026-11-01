#include "Date.h"

Date::Date(int j, int m, int a) {
    if (estValide(j, m, a)) {
        jour = j;
        mois = m;
        annee = a;
    }
    else {
        
        jour = 1;
        mois = 1;
        annee = 2000;
    }
}

bool Date::estBissextile(int a) {
    return (a % 400 == 0) ||
        (a % 4 == 0 && a % 100 != 0);
}

bool Date::estValide(int j, int m, int a) {
    if (a <= 0 || m < 1 || m > 12 || j < 1)
        return false;

    int joursMois[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (estBissextile(a))
        joursMois[1] = 29;
   
    return j <= joursMois[m - 1];
}

void Date::afficher() const {
    cout << jour << "/" << mois << "/" << annee << endl;
}