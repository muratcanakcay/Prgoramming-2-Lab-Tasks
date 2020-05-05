#include "Picture.h"

//---STAGE 1: implement constructors------

Picture::Picture(int _h, string* _signs, string _desc) : height(_h), description(_desc), signs(nullptr)
{
	init(height, _signs);
}

Picture::Picture(const Picture& p) : height(p.getHeight()), description(p.description), signs(nullptr)
{
	init(height, p.signs);
}

void Picture::init(int h, string* s)
{
	signs = new string[height];
	for (int i = 0; i < height; i++)
		signs[i] = s[i];
}

//---destructor and necessary operators---

Picture::~Picture()
{
	if (signs) delete[] signs;
}

Picture& Picture::operator=(const Picture& p)
{
	if (signs) delete[] signs;
	height = p.height;
	description = p.description;
	init(height, p.signs);
	return *this;
}

ostream& operator<<(ostream& out, Picture& p)
{
	out << "Picture: " << p.description << endl;
	out << "Size: " << p.getWidth() << "X" << p.getHeight() << endl;
	return out;
}

//----------------------------------------

//---STAGE 2: implement operator[]---

string Picture::operator[](int i) const
{
	return signs[i];
}

//-----------------------------------
