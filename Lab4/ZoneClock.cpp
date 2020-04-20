#include <iostream>
using namespace std;
#include "ZoneClock.h"

int ZoneClock::clock_number = 0;


ZoneClock::ZoneClock(int hour, int min, clock_period period) // c-tor
{
	clock_number++;

	if (!(clock_number % 3)) format = false; // for every third clock created
	else format = true;

	this->hour = hour;
	this->min = min;
	this->period = period;		
}

std::ostream& operator<<(std::ostream& out, const ZoneClock& c)
{
	int hour;
	
	if (c.format) // don't convert
		hour = c.hour;
	else // convert to 24h
	{
		if (c.period == clock_period::pm && c.hour < 12)
			hour = c.hour + 12;
		else if (c.period == clock_period::am && c.hour == 12)
			hour = 0;
		else hour = c.hour;
	}
	
	if (hour < 10) out << '0';
	out << hour << ':';

	if (c.min < 10) out << '0';
	out << c.min;
	
	if (c.format) // add am/pm
		out << (c.period == clock_period::pm ? "pm" : "am");
	
	switch(c.zone) // add time zone
	{
		case time_zone::CET :
			cout << " UTC + 1";
			break;
		case time_zone::EET :
			cout << " UTC + 2";
			break;
		default :
			cout << " UTC + 0";			
	}
	
	out << endl;

	return out;
}
std::istream& operator>>(std::istream& in, ZoneClock& c)
{
	int hour, min;
	bool repeat;
	char period[3];
		
	do
	{
		repeat = false;
		
		cout << "Enter hour: ";
		in >> hour;
		cout << "Enter minutes: ";
		in >> min;
		cout << "Enter (am/pm): ";
		in >> period;
				
		if (hour <= 0 || hour >= 13 \
		   || min < 0 || min > 59   \
		   || (strcmp(period, "am") != 0 && strcmp(period, "pm") != 0))
		{
			repeat = true;
			cout << "Wrong time!!" << endl;
		}
		
	} while (repeat);

	c.hour = hour;
	c.min = min;
	
	c.period = (strcmp(period, "am") == 0 ? clock_period::am : clock_period::pm);
	
	return in;
}

void ZoneClock::add_minute()
{
	min += 1;
	
	if (min == 60) // increase hour
	{
		min = 0;
		hour += 1;

		if (hour == 12) // change time period
			period = (period == clock_period::am ? clock_period::pm : period = clock_period::am);
		
		else if (hour == 13) // hour must be between 1 and 12
			hour = 1;
		
	}
}
void ZoneClock::add_minutes(int minutes)
{
	while (minutes-- > 0)
		add_minute();			
}

void ZoneClock::subtract_minute()
{
	min -= 1;

	if (min == -1) // decrease hour
	{
		min = 59;
		hour -= 1;

		if (hour == 11) // change time period
			period = (period == clock_period::am ? clock_period::pm : period = clock_period::am);
		
		else if (hour == 0) // hour must be between 1 and 12
			hour = 12;
	}
}
void ZoneClock::subtract_minutes(int minutes)
{
	while (minutes-- > 0)
		subtract_minute();
}

void ZoneClock::set_time_zone(const time_zone& tz)
{
	if (zone == tz) return; 
	
	int diff = static_cast<int>(tz) - static_cast<int>(zone); // find difference in time zones
	
	// convert to minutes, add if positive, subtract if negative
	if (diff > 0) add_minutes(diff * 60); 
	else if (diff < 0) subtract_minutes(-1 * diff * 60);

	zone = tz;
}