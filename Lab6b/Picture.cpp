#include "Picture.h"

//---STAGE 1: implement constructors------
//---destructor and necessary operators---

Picture::Picture(int _h, string* _signs, string _desc) : height(_h), description(_desc), signs(nullptr)
{
	init(height, _signs);
}

Picture::Picture(const Picture& p) : height(p.getHeight()), description(p.description), signs(nullptr)
{
	init(height, p.signs);
}

Picture::~Picture()
{
	if (signs) delete[] signs;
}

Picture& Picture::operator=(const Picture& p)
{
	if (this->signs) delete[] this->signs;
	this->height = p.height;
	this->description = p.description;
	this->init(height, p.signs);
	return *this;
}

void Picture::init(int h, string* st)
{
	signs = new string[h];
	for (int i = 0; i < h; i++)
		signs[i] = st[i];
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
	return this->signs[i];
}

//-----------------------------------
