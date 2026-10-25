#include "Complex.h"
#include <iostream>
using namespace std;
Complex::Complex(double real, double img)
	:re(real), im(img)
{}

void Complex::afficher()const
{
	if (im >= 0) {
		std::cout << re << "+" << im <<"i"<< std::endl;
	}
	else {
		std::cout << re << "-" << -im <<"i" << std::endl;
	}
}

Complex::Complex(const Complex& c)
{
	this->re = c.re;
	this->im = c.im;
}

Complex Complex::operator-(Complex& c)const
{
	Complex* res = new Complex(0.0, 0.0);
	res->re = re - c.re;
	res->im= im - c.im;
	return *res;
}

Complex Complex::operator-(double a) const
{
	Complex* res = new Complex(0.0, 0.0);
	res->re = re - a;
	res->im = im - 0.0;
	return *res;
}

Complex Complex::operator+(Complex& c) const
{
	Complex* res = new Complex(0.0, 0.0);
	res->re = re + c.re;
	res->im = im + c.im;
	return *res;
}

Complex Complex::operator+(double b) const
{
	Complex* res = new Complex(0.0, 0.0);
	res->re = re + b;
	res->im = im + 0.0;
	return *res;
}

Complex Complex::operator*(Complex&c) const {
	Complex* prod1 = new Complex(0,0);
	Complex* prod2 = new Complex(0,0);
	Complex* result = new Complex(0, 0);
	prod1->re = this->re * c.re;
	prod1->im = this->re * c.im;
	prod2->re = this->im * c.re;
	prod2->im = -(this->im * c.im);
	result->re = prod1->re + prod2->im;
	result->im= prod1->im + prod2->re;
	return *result;
}

Complex Complex::operator/(Complex& c) const
{	
	double denom;
	denom = (c.im * c.im) + (c.re * c.re);
	if (denom == 0) {
		std::cout << "Divison par zero est Impossible" << std::endl;
	}
	double r = (re * c.re + im * c.im) / denom;
	double i = (im * c.re - re * c.im) / denom;
	return Complex(r, i);

}

bool Complex::operator==( Complex& c) const{	
	double result;
	result=(re == c.re && im == c.im);
	if (result==1)
	{
		cout<< "Les deux nombres sont egaux" ;
		return result;
	}

}

bool Complex::operator!=( Complex& c) const
{	

	return re != c.re || im != c.im;
}

bool Complex::operator<( Complex& c)const {
	
	return (re * re + im * im) < (c.re * c.re + c.im * c.im);
}

bool Complex::operator>(Complex& c)const {

	return (re * re + im * im) > (c.re * c.re + c.im * c.im);
}

Complex::~Complex(){	

}


