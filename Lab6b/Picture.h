#pragma once
#include <iostream>
#include <string>
using namespace std;

class Picture
{
private:
	int height;
	string* signs;
	string description;

	void init(int, string*);

public:
	Picture(int _h = 0, string* _signs = nullptr, string _desc = nullptr);
	Picture(const Picture&);
	~Picture();

	int getWidth() const { return (signs == nullptr ? 0 : signs[0].length()); }
	int getHeight() const { return height; }
	
	Picture& operator=(const Picture&);
	string operator[](int i) const; //STAGE 2

	friend ostream& operator<<(ostream&, Picture&);
};