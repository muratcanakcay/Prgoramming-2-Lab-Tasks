#pragma once
#include <iostream> 
using namespace std;
#include "digital_signal.h"

class Signal_plot
{
private:
	Digital_signal signal;
	int no_of_rows;
	int no_of_columns;
	char** plot;

	void init_plot();
	void update_plot();
	void clean_plot();

public:
	Signal_plot(int no_of_samples = 0, int* samples = nullptr);
	~Signal_plot();

	Signal_plot(const Digital_signal&);
	Signal_plot(const Signal_plot&);
	Signal_plot& operator=(const Signal_plot&);

	friend ostream& operator<<(ostream&, const Signal_plot&);
};