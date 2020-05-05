#pragma once
#include "ColorBrush.h"

class ColorPatternBrush : public ColorBrush //---STAGE 4: derive---
{
protected:
	short alternateColor;
	int colorLength, alternateColorLength;

public:
	ColorPatternBrush(string _name, short _color, short _altColor,
		int _clrLen, int _altClrLen, Picture _pic);

	short getAlternateColor() const;
	void paint();
};