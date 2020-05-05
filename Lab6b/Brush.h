#pragma once
#include <iostream>
#include <string>
#include "Picture.h"


class Brush
{
protected:
	string name;
	Picture picture;

public:
	Brush(string _name, Picture _pic);

	void paint();
	void setPicture(Picture); //STAGE 4

	friend ostream& operator<<(ostream&, Brush&);
};