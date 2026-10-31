#pragma once
#include"Bibliotheque.h"
class Date
{
private:
	int jour, mois, annee;
public:
	bool estBissextile(int);
	bool estValide(int, int, int);
	bool operator==(const Date&)const;
	Date operator<(const Date&)const;
	void afficherDate()const;
	Date(int, int, int);
	Date();
};

