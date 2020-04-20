#include <iostream> 
#include <iomanip> 
#include <cmath>
#include "digital_signal.h"
using namespace std;

Digital_signal::Digital_signal(int no_of_samples, int* samples) // c-tor
{
	if (DEBUG) cout << " -----> signal c-tor" << endl;
	
	this->no_of_samples = no_of_samples; 
			
	if (!no_of_samples) this->samples = nullptr; // if zero samples
	else // if more than zero samples 
	{
		this->samples = new int[this->no_of_samples]; // create array
		
		if (!samples) // if no sample values are given set all to zero
			for (int i = 0; i < this->no_of_samples; i++)
				this->samples[i] = 0;
		else	// if sample values are given enter them into array
			for (int i = 0; i < this->no_of_samples; i++)
				this->samples[i] = samples[i];
	}
	
}
Digital_signal::Digital_signal(const Digital_signal& ds) // copy c-tor
{
	if (DEBUG) cout << " -----> signal copy c-tor" << endl;
	this->no_of_samples = ds.no_of_samples;
	this->samples = new int[this->no_of_samples];
	for (int i = 0; i < this->no_of_samples; i++)
		this->samples[i] = ds.samples[i];
}
Digital_signal::~Digital_signal() // d-tor
{
	if (DEBUG) cout << " -----> signal d-tor" << endl;
	if (this->samples) delete[] this->samples; // free memory
}

int Digital_signal::min_val() const
{
	if (!samples) return 0;
	
	int min = INT_MAX;
	for (int i = 0; i < no_of_samples; i++)
		if (samples[i] < min) min = samples[i];
	
	return min;
}
int Digital_signal::max_val() const
{
	if (!samples) return 0;

	int max = 0;
	for (int i = 0; i < no_of_samples; i++)
		if (samples[i] > max) max = samples[i];

	return max;
}


ostream& operator<<(ostream& out, const Digital_signal& ds)
{
	out << "[ ";
	if (ds.samples)
		for (int i = 0; i < ds.no_of_samples; i++)
			out << ds.samples[i] << " ";
	out << "]" << endl;

	out << "Signal min: " << ds.min_val() << "  Signal max: " << ds.max_val() << endl;

	return out;
}
Digital_signal& Digital_signal::operator=(const Digital_signal& other) // assignment operator
{
	if (DEBUG) cout << " -----> signal assignment" << endl;
	this->no_of_samples = other.no_of_samples;
	if (this->samples) delete[] samples;
	this->samples = new int[this->no_of_samples];
	for (int i = 0; i < this->no_of_samples; i++)
		this->samples[i] = other.samples[i];
	return *this;
}
Digital_signal operator+(const Digital_signal& ds, int c)
{
	if (DEBUG) cout << " -----> signal operator+" << endl;
	Digital_signal temp(ds); // make copy of original signal
	
	for (int i = 0; i < temp.no_of_samples; i++) // modify values on the copy
		temp.samples[i] += c;

	return temp; // return modified copy
}





