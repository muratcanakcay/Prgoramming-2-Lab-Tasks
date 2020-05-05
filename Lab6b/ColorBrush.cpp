#include "ColorBrush.h"

//---STAGE 3: implement constructor--

ColorBrush::ColorBrush(string _name, short _color, Picture _pic) : Brush(_name, _pic), color(_color) {};

//---getColor and paint methods------

short ColorBrush::getColor() const
{
	return color;
}

void ColorBrush::paint()
{
	useColor(getColor());
	Brush::paint();
	resetColor();
}

//-----------------------------------

//---already implemented---
void ColorBrush::useColor(short clr)
{
	switch (clr)
	{
	case 1:
		cout << "\x1b[31m";
		break;
	case 2:
		cout << "\x1b[32m";
		break;
	case 3:
		cout << "\x1b[33m";
		break;
	case 4:
		cout << "\x1b[34m";
		break;
	case 5:
		cout << "\x1b[35m";
		break;
	case 6:
		cout << "\x1b[36m";
		break;
	case 7:
		cout << "\x1b[37m";
		break;
	}
}

void ColorBrush::resetColor()
{
	cout << "\x1b[0m";
}
//-------------------------
