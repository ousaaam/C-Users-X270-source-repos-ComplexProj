#pragma once
#include <iostream>
using namespace std;
class Date{
private:
	int jour, mois, annee;
public:
    Date(int j, int m, int a);
    static bool estBissextile(int a);
    static bool estValide(int j, int m, int a);
    void afficher() const;
};

