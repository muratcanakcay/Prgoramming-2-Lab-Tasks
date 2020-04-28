#include <iostream>
using namespace std;
#include "bank.h"


BankWindow::BankWindow(int queue_size, int working_time) 
{
	queue_to_window.qsize = queue_size;
	this->working_time = working_time;
}

ostream& operator<<(ostream& out, const BankWindow& bw)
{
	out << "The number of customers accepted into the queue: " \
		<< bw.number_accepted << endl;

	out << "The number of customers served by the window: " \
		<< bw.number_served << endl;

	out << "The number of clients returned from the queue : " \
		<< bw.number_returned << endl;

	return out; 
}

void BankWindow::simulation(int time_between_clients)
{
	int cycle = 0;
	Client currentClient;

	while (cycle++ <= working_time * 60) 
	{
		if (cycle % time_between_clients == 0) // new client
		{
			if (queue_to_window.isfull())
			{
				number_returned++;
			}
			else
			{
				Client newClient;
				newClient.set(cycle);
				queue_to_window.enqueue(newClient);
				number_accepted++;
			}
		}

		if (release_time <= 0 && !(queue_to_window.isempty()))
		{
			if (queue_to_window.dequeue(currentClient))
			{
				release_time = currentClient.how_long();
				if (number_accepted) number_served++;
			}
		}
		
		release_time--;
	}
}