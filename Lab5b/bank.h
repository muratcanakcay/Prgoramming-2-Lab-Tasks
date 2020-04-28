#ifndef BANK_H_
#define BANK_H_
#include <iostream>
using namespace std;
#include "queue.h"

class BankWindow
{
private:
	static const int min_per_hr = 60;
		
	Queue queue_to_window;
	int working_time;					// window working time (in hours)

	long release_time = 0;         // time to release the window (when the client is served by the window)

	long number_returned = 0;        // the number of clients returned from the queue
	long number_accepted = 0;        // number of customers accepted into the queue
	long number_served = 0;           // the number of customers served in the simulation
	

public:
	BankWindow(int queue_size, int working_time);
	void simulation(int time_between_clients);
	friend ostream& operator<<(ostream&, const BankWindow&);
};


#endif

