#include "Array.h"

void Array::init(int _size, int *_coef) 
{
	size = _size;
	if (size)
	{
		tab = new int[size];
		for (int i = 0; i < size; i++)
			tab[i] = (_coef ? _coef[i] : 0);
	}
	else tab = nullptr;
}

//fill missing constructors, destructor, operator= (if needed)

Array::Array(int _size, int* _coef) // parametrized c-tor
{
	init(_size, _coef);
}
Array::Array(const Array& a) // copy c-tor
{
	init(a.size, a.tab);
}
Array::~Array() // d-tor
{
	if (tab) delete[] tab;
}
Array& Array::operator=(const Array& a) // assignment operator
{
	if (tab) delete[] tab;
	init(a.size, a.tab);

	return *this;
}

//fill missing operator+ operator- operator*

void Array::operator*=(int n)
{
	for (int i = 0; i < size; i++)
		tab[i] *= n;
}
Array Array::operator+(const Array& a)
{
	if (size != a.size) return *this; 
	
	Array temp(size, tab);
	
	for (int i = 0; i < size; i++)
		temp.tab[i] += a.tab[i];

	return temp;
}
Array Array::operator-(const Array& a)
{
	if (size != a.size) return *this;

	Array temp(size, tab);

	for (int i = 0; i < size; i++)
		temp.tab[i] -= a.tab[i];

	return temp;
}

ostream& operator<<(ostream &out, Array &a)
{
	if (a.size < 1) out << "Empty Array";

	for (int i = 0; i < a.size; i++)
		out << showpos << *(a.tab+i) << "  ";
	return out;
}
