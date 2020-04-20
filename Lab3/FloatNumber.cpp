#include "FloatNumber.h"

//#include <cmath>
#include <iostream>

using namespace std;

/* ------------------- DO YOUR FLOATNUMBER CLASS IMPLEMENTATION HERE ------------------- */
FloatNumber::FloatNumber() : integerValue(0), decimalValue(0) {}
FloatNumber::FloatNumber(int a) : integerValue(a), decimalValue(0) {}
FloatNumber::FloatNumber(int a, int b) : integerValue(a), decimalValue(b) {}
FloatNumber::FloatNumber(float a) 
{
	integerValue = a;
	a -= integerValue;
	a *= 1000;
	decimalValue = a;
}

void FloatNumber::WriteToConsole() 
{
	 
	if (integerValue < 10) cout << "  ";
	else if (integerValue < 100) cout << " ";
	cout << integerValue << ".";
	if (decimalValue < 10) cout << "00";
	else if (decimalValue < 100) cout << "0";
	cout << decimalValue << endl; 
	
	// following requires <iomanip>
	// cout << right << setfill(' ') << setw(3) << integerValue
	//	<< "," << right << setfill('0') << setw(3) << decimalValue;
}

void FloatNumber::ReadFromConsole()
{
	integerValue = 0;
	decimalValue = -1;
	while (integerValue <= 0)
	{
		cout << "Provide Integer Value: ";
		cin >> integerValue;
		if (integerValue <= 0) cout << "The value must be greater than zero!\n";
	}
	while (decimalValue < 0 || decimalValue >= MAX_DECIMAL_VALUE)
	{
		cout << "Provide Decimal Value: ";
		cin >> decimalValue;
		if (decimalValue < 0 || decimalValue >= MAX_DECIMAL_VALUE) cout << "The value must be between 0 and 1000!\n";
	}
}
	

bool FloatNumber::Equals(const FloatNumber& other) const 
{
	return (integerValue == other.integerValue) && (decimalValue == other.decimalValue);
}

FloatNumber operator + (const FloatNumber& floatA, const FloatNumber& floatB)
{
	FloatNumber sum;
	sum.integerValue = floatA.integerValue + floatB.integerValue;
	sum.decimalValue = floatA.decimalValue + floatB.decimalValue;
	if (sum.decimalValue >= MAX_DECIMAL_VALUE) 
	{
		sum.decimalValue -= 1000;
		sum.integerValue++;
	}
	return sum;
}

FloatNumber::FloatNumber(string st) 
{
	decimalValue = integerValue = 0;
	bool decimal_flag = 1;
	int pass = 0;
	for (string::reverse_iterator it = st.rbegin(); it != st.rend(); it++)
	{
		if (*it != '.') // assign digits to appropriate places
		{
			int num = *it - '0';
			for (int i = 1; i <= pass; i++) num *= 10;
			if (decimal_flag == 1) decimalValue += num;
			else integerValue += num;
			pass += 1;
		}

		else // reached decimal point
		{
			pass = 0;
			decimal_flag = 0;
		}		
	}
	
	
	/* following requires <sstream>
		
	for (string::iterator it = st.begin(); it != st.end(); it++) 
		if (*it == '.') //replace . with space
			*it = ' ';
	
	stringstream ss;
	ss.str(st); // feed the string into stream
	ss >> integerValue >> decimalValue; // send the sterm to variables
	*/
}