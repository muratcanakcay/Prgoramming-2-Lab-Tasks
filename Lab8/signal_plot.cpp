#include <iostream> 
#include <iomanip> 
#include <cmath>
#include "signal_plot.h"
using namespace std;

Signal_plot::Signal_plot(int no_of_samples, int* samples) // c-tor from parameters
{
	if (DEBUG) cout << " -----> plot c-tor (from parameters)" << endl; 
	
	signal = Digital_signal(no_of_samples, samples);
	init_plot();
	update_plot();
}
Signal_plot::Signal_plot(const Digital_signal& ds) // c-tor from signal
{
	if (DEBUG) cout << " -----> plot c-tor (from signal)" << endl;

	signal = Digital_signal(ds);
	init_plot();
	update_plot();
}
Signal_plot::Signal_plot(const Signal_plot& sp) // copy c-tor
{
	if (DEBUG) cout << " -----> plot copy c-tor" << endl;
	
	this->signal = Digital_signal(sp.signal);

	init_plot();
	update_plot();
}
Signal_plot::~Signal_plot() // d-tor
{
	if (DEBUG) cout << " -----> plot d-tor" << endl;
	clean_plot();
}

void Signal_plot::init_plot()
{
	if (DEBUG) cout << " -----> init_plot()" << endl;
	
	no_of_columns = signal.no_of_samples;
	no_of_rows = signal.max_val() - signal.min_val() + 1;
	
	plot = new (nothrow) char*[no_of_rows]; // allocate memory for rows
	for (int i = 0; i < no_of_rows; i++)
		plot[i] = new (nothrow) char[no_of_columns]; // allocate memory for columns
}
void Signal_plot::update_plot()
{
	if (DEBUG) cout << " -----> update_plot()" << endl;
	for (int j = 0; j < no_of_columns; j++) // for each column (each sample)
	{
		int mark = signal.max_val() - signal.samples[j]; // find which row to mark
		
		for (int i = 0; i < no_of_rows; i++)
			plot[i][j] = (i == mark) ? '*' : ' '; // mark appropriate row with * others with space
	}
}
void Signal_plot::clean_plot()
{
	if (DEBUG) cout << " -----> clean_plot()" << endl;
	
	for (int i = 0; i < no_of_rows; i++)
		delete[] plot[i]; // free memory allocated to columns
	delete[] plot; // free memory allocated to rows

	no_of_rows = no_of_columns = 0; 
}

Signal_plot& Signal_plot::operator=(const Signal_plot& other) // assignment operator
{
	if (DEBUG) cout << " -----> plot assignment" << endl;

	clean_plot();
	this->signal = other.signal;
	init_plot();
	update_plot();

	return *this;
}

ostream& operator<<(ostream& out, const Signal_plot& s)
{
	for (int j = 0; j < s.no_of_columns; j++)
		out << '-';
	out << endl;

	for (int i = 0; i < s.no_of_rows; i++)
	{
		for (int j = 0; j < s.no_of_columns; j++)
		{
			out << s.plot[i][j];
		}
		out << endl;
	}

	for (int j = 0; j < s.no_of_columns; j++)
		out << '-';
	out << endl;

	return out;
}

