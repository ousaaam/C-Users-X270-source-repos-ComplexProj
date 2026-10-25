#pragma once
using namespace std;

class Commande{
private:
	const int id;
	string name;
    double *sommairePrix;
	static int compteur;
	double total,taille;
	int nombreArticles;
public:
	Commande(string ,int );
	void ajouterArticle(double);
	void calculerTotal();
	void afficher() const;
	~Commande();

};

