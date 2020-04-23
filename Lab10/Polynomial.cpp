#include "Polynomial.h"
#include <cmath>

//define missing constructor(s)
Polynomial::Polynomial(int _deg, int* _coef) : Array(_deg + 1, _coef)
{
	degree = _deg;	   
}
Polynomial::Polynomial(const Polynomial& p) : Array(p.size, p.tab)
{
	degree = p.degree;
}
Polynomial::~Polynomial() {}; // Parent's d-tor is enough
Polynomial& Polynomial::operator=(const Polynomial& p)
{
	Array::operator=(p);
	degree = p.degree;

	return *this;
}

void Polynomial::operator*=(int n)
{
	Array::operator*=(n);
}
Polynomial Polynomial::operator+(const Polynomial& p)
{
	if (degree != p.degree) return *this;
	
	Polynomial temp(degree);
	
	// (Array&)temp = Array::operator+(p); same as below:
	(Array&)temp = (Array)(*this) + p;
	
	return temp;
}
Polynomial Polynomial::operator-(const Polynomial& p)
{
	if (degree != p.degree) return *this;

	Polynomial temp(degree);
	
	// (Array&)temp = Array::operator-(p); same as below:
	(Array&)temp = (Array)(*this) - p;
	
	return temp;
}

ostream& operator<<(ostream& out,const Polynomial& w)
{
	if (w.degree < 1) out << "Empty Polynomial";

	for (int i = w.degree; i > 0; i--)
		if (*(w.tab + i) != 0) 
			out << showpos << *(w.tab + i) << "x^" << noshowpos << i;
	if (*(w.tab) != 0) out << showpos << *(w.tab);
	return out;
}



double Polynomial::operator()(double x) const
{
	//add missing code
	return 0.0;
}


Polynomial Polynomial::derivtive() const
{
	//add missing code
	return* this;	
}

double poly_root(const Polynomial &w, double x, int& it)
{
	double eps = 1e-3;    // epsilon value
	int max_it = 100;	  // maximum iteration count

	for (it = 0; it<max_it; it++)	// actual number of iterations 
	{
		//implement Newton's method

	}
	
	cout << "not convergent" << endl;
	return x;
}
