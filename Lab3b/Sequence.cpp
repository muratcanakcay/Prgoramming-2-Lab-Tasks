#include "Sequence.h"

Sequence::Sequence()
{
	n = 0;
}

Sequence::Sequence(int l)
{
	n = l;
	for (int i = 0; i < l; i++)
		arr[i] = 0;
}

Sequence::Sequence(int l, int* input)
{
	n = l;
	for (int i = 0; i < l; i++)
		arr[i] = input[i];
}

int Sequence::length() const
{
	return n;
}

int Sequence::get_idx(int idx) const
{
	return arr[idx];
}

int& Sequence::set_idx(int idx)
{
	return arr[idx];
}

ostream& operator<<(ostream& out, const Sequence& s)
{
	// out << "Fraction : " << u.get_nominator() << "/" << u.get_denominator() << endl;  
	out << "[";
	for (int i = 0; i < s.n; i++)
		out << s.arr[i] << " ";
	out << "]";
	return out;
}

istream& operator>>(istream& in, Sequence& s)
{
	cout << "Give length:";
	in >> s.n;
	cout << "Input terms:";
	for (int i = 0; i < s.n; i++)
	{
		in >> s.arr[i];
	}

	return in;
}

bool Sequence::isArithmetic() const
{
	if (n < 2) return 1;
	int step;
	bool flag = 1;
	step = arr[1] - arr[0];
	for (int i = 2; i < n; i++)
	{
		if (arr[i] - arr[i-1] != step) flag = 0;
	}
	return flag;
}

bool checkArithmetic(const Sequence c)
{
	bool arithmetic = c.isArithmetic();
	
	cout << "Function checkArithmetic: is ";
	if (!arithmetic) cout << "NOT ";
	cout << "arithmetic." << endl;
	return arithmetic;
}

Sequence nth(const Sequence& c, int n)
{
	int length = (c.length() / n );
	if (c.length() % n != 0) length++;
	Sequence ret(length);
	int i = 0;
	int idx = 0;
	while (i < length)
	{
		ret.set_idx(i) = c.get_idx(idx);
		idx += n;
		i++;
	}
		
	return ret;
}


