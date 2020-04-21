#pragma once
#include <iostream>
using namespace std;

const int N = 128;

class Sequence
{
	int n;
	int arr[N];
public:
	
	//fill missing declarations
	
	Sequence();
	Sequence(int l);
	Sequence(int l, int* input);

	int length() const;

	friend ostream& operator<<(ostream& out, const Sequence& s);
	friend istream& operator>>(istream& in, Sequence& s);
	
	int get_idx(int idx) const;
	int& set_idx(int idx);

	bool isArithmetic() const;
};

bool checkArithmetic(const Sequence c );
Sequence nth(const Sequence& c, int n);