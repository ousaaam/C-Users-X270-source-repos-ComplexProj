#pragma once
class Complex{
private:
	double re;
	double im;
public:
	Complex(double r , double i );
	void afficher()const;
	Complex operator-(Complex& c)const;
	Complex operator-(double c)const;
	Complex operator+(Complex& c)const;
	Complex operator+(double c)const;
	Complex operator*(Complex& c) const;
	Complex operator/(Complex& c) const;
	bool operator==(Complex& c)const;
	bool operator!=( Complex& c)const;
	bool operator<( Complex& c)const;
	bool operator>( Complex& c)const;


	Complex(const Complex&);

	~Complex();
};

