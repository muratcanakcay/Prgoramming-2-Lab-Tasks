#pragma once
#include "Brush.h"

class ColorBrush : public Brush//---STAGE 3: derive---
{
protected:
	short color;
	
	const short DEFAULT_COLOR = 7;

public:
	ColorBrush(string _name, short _color, Picture _pic);

	short getColor() const;
	void paint();

	//---already implemented---
	void useColor(short);
	void resetColor();
	//-------------------------
};