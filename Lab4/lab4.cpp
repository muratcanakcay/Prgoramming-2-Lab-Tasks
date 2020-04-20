#include <iostream>
using namespace std;
#include "ZoneClock.h"

int main()
{
	cout << "--------------- Part 1 ---------------" << endl;	

	ZoneClock c1(7, 34);
	ZoneClock c2(7, 34, clock_period::pm);
	ZoneClock c3;
	ZoneClock c4(12, 00, clock_period::am);
	ZoneClock c5(11, 57, clock_period::pm);
	ZoneClock c6(12, 00, clock_period::pm);
	ZoneClock c7(12, 12, clock_period::am);
	ZoneClock c8(1, 23, clock_period::pm);
	ZoneClock c9(9, 9, clock_period::pm);

	cout << c1 << c2 << c3 << c4 << c5 << c6 << c7 << c8 << c9;

	cout << "--------------- Part 2 ---------------" << endl;

	ZoneClock c10, c11, c12;
	cin >> c10 >> c11 >> c12;
	cout << c10 << c11 << c12;

	cout << "--------------- Part 3 ---------------" << endl;

	cout << c4;
	c4.add_minutes(720);
	cout << c4;
	c4.add_minutes(720);
	cout << c4;
	c4.add_minutes(90);
	cout << c4;
	cout << endl;
	cout << c3;
	c3.add_minutes(720);
	cout << c3;
	c3.add_minutes(720);
	cout << c3;
	c3.add_minutes(90);
	cout << c3;
	c3.add_minutes(720);
	cout << c3;

	cout << "--------------- Part 4 ---------------" << endl;

	cout << c4;
	c4.subtract_minutes(90);
	cout << c4;
	c4.subtract_minutes(720);
	cout << c4;
	c4.subtract_minutes(720);
	cout << c4;
	cout << endl;
	cout << c3;
	c3.subtract_minutes(720);
	cout << c3;
	c3.subtract_minutes(90);
	cout << c3;
	c3.subtract_minutes(720);
	cout << c3;
	c3.subtract_minutes(720);
	cout << c3;

	cout << "--------------- Part 5 ---------------" << endl;

	cout << c3 << c4 << c5 << c9 << endl;

	cout << "--------------- Part 6 ---------------" << endl;

	c3.set_time_zone(time_zone::UTC);
	c4.set_time_zone(time_zone::WET);
	c5.set_time_zone(time_zone::CET);
	c9.set_time_zone(time_zone::EET);

	cout << c3 << c4 << c5 << c9 << endl;
	c3.set_time_zone(time_zone::EET);
	c4.set_time_zone(time_zone::CET);
	c5.set_time_zone(time_zone::UTC);
	c9.set_time_zone(time_zone::CET);
	cout << c3 << c4 << c5 << c9 << endl;

	return 0;
}
