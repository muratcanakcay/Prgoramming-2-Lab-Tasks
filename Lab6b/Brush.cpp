#include "Brush.h"

//---STAGE 2: implement constructor--
//---operator<< and paint method-----

Brush::Brush(string _name, Picture _pic) : picture(_pic), name(_name) {}

ostream& operator<<(ostream& out, Brush& b)
{
	out << "Brush: " << b.name << endl << b.picture;
	return out;
}

void Brush::paint()
{
	for (int i = 0; i < picture.getHeight(); i++)
		cout << picture[i] << endl;
}
//-----------------------------------


//---STAGE 4: implement setPicture---

void Brush::setPicture(Picture p)
{
	this->picture = p;
}

//-----------------------------------