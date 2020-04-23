#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Array
{
protected:

	int size;
	int *tab;
	void init(int _size, int *_coef);

public:

	Array(int _size=0, int *_coef=nullptr);
	Array(const Array &a);
	~Array();
	Array& operator=(const Array &a);

	//declare and define in Array.cpp
	void operator*=(int n);
	Array operator+(const Array& a);
	Array operator-(const Array& a);
	
	friend ostream& operator<<(ostream &out, Array &a);
};
