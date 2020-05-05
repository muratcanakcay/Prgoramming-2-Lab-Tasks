#include "ColorPatternBrush.h"

//---STAGE 4: implement constructor-------
//---getAlternateColor and paint methods--

ColorPatternBrush::ColorPatternBrush(string _name, short _color, short _altColor,
	int _clrLen, int _altClrLen, Picture _pic) : ColorBrush(_name, _color, _pic), \
	alternateColor(_altColor), colorLength(_clrLen), alternateColorLength(_altClrLen) {};

short ColorPatternBrush::getAlternateColor() const
{
	return alternateColor;
}

void ColorPatternBrush::paint()
{
	int width = picture.getWidth();
	int height = picture.getHeight();
	int length = colorLength + alternateColorLength;
	int count = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (count++ == length) count = 1;
			useColor((count <= colorLength) ? getColor() : getAlternateColor());
			cout << picture[i][j];
			resetColor();
		}
		cout << endl;
	}
}


//----------------------------------------
