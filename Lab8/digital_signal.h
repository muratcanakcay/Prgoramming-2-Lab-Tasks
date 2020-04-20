#pragma once
#include <iostream> 
using namespace std;

static constexpr int DEBUG = 0;

class Digital_signal
{
private:
	int* samples;
	int no_of_samples;


public:
	Digital_signal(int no_of_samples = 0, int* samples = nullptr); //c-tor
	Digital_signal(const Digital_signal& ds); // copy c-tor
	~Digital_signal(); //d-tor
	
	int min_val() const;
	int max_val() const;	

	Digital_signal& operator=(const Digital_signal& other); 
	
	friend ostream& operator<<(ostream& out, const Digital_signal& ds);
	friend Digital_signal operator+(const Digital_signal& ds, int c);
	
	friend class Signal_plot;
};