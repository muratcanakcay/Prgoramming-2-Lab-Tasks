#include <iostream>
using namespace std;
#include "client.h"

Client::Client()
{
	arrival_time = 0;
	service_time = 0;
}

void Client::set(long arrival_time)
{
	this->arrival_time = arrival_time;
	service_time = 10;
}

ostream& operator<<(ostream& out, const Client& c)
{
	out << "Arrival Time: " << c.what_time() << " Service Time: " << c.how_long() << endl;
	return out;
}
