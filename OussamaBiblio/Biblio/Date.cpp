#include "Date.h"

bool Date::estBissextile(int a){	
	return ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0));	
}

bool Date::estValide(int j, int m, int a){
	int mois[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if (j<1 || j>31 || m<1 || m>12 || a < 0 || a> 2026) {
		return false;
	}else if(estBissextile(a)){
		mois[1] = 29;
	}else if(j>mois[m-1]){
		return false;
	}
	return true;
}


bool Date::operator==(const Date&c) const{
	if (this->jour == c.jour && this->mois == c.mois && this->annee == c.annee) {
		return true;
	}else {
		return false;
	}

}

Date Date::operator<(const Date& d) const
{	
	if (this->annee != d.annee) {
		return annee<d.annee ;
	}
	else if (this->mois!=d.mois) {
		return mois<d.mois;
	}
	return jour < d.jour;
}

void Date::afficherDate() const{
	cout<<this->jour<< "/"<<this->mois<<"/"<<this->annee<< endl;
}

Date::Date(int j, int m, int a) {
	this->jour = j;
	this->mois = m;
	this->annee = a;
}

Date::Date()
{
	jour = 1;
	mois = 1;
	annee = 2000;
}



