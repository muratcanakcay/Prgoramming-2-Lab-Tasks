#pragma once
#include <iostream>
using namespace std;

enum class clock_period { am, pm };
enum class time_zone { UTC = 0, WET = 0, CET, EET };
 
class ZoneClock
{
	int hour;
	int min;
	clock_period period;
	time_zone zone = time_zone::UTC;
	static int clock_number;

	bool format = true;	// true - 12h format with am/pm periods
						// false - 24 hours format (am/pm periods are not important - conversion is needed)

public:
	// Part 1
	ZoneClock(int hour = 12 , int min = 0 , clock_period period = clock_period::am);
	friend std::ostream& operator<<(std::ostream& out, const ZoneClock& c);
	// Part 2
	friend std::istream& operator>>(std::istream& in, ZoneClock& c);
	// Part 3
	void add_minute();
	void add_minutes(int minutes);
	// Part 4
	void subtract_minute();
	void subtract_minutes(int minutes);
	// Part 5
	// Part 6
	void set_time_zone(const time_zone& tz);

};


