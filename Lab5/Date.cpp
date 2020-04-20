
#include <iostream>
#include <iomanip>
#include "Date.h"

                       //     0   1   2   3   4   5   6   7   8   9  10  11  12
int Date::monthsLengths[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

                             //      0     1      2      3      4      5      6      7      8      9     10     11     12
const char *Date::monthsNames[] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

const char *Date::daysOfWeek[] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };


Date::Date()
{
	year = month = day = 1;
}
Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
	
	if (!isValid())
		this->year = this->month = this->day = 1;
}
Date::Date(int days)
{
	
	if (days > 0)
	{
		// no leap years
		
		/*year = 1900 + (days / 365);
		month = 12;
		day = days % 365 + 31;

		while (day > monthsLengths[month])
		{
			day -= monthsLengths[month];
			if (++month > 12 && year++) month = 1;
		}*/

		// yes leap years
		
		year = 1900;
		month = 12;
		day = days + 31;
		while (day > ((year%4==0 && month == 2) ? 29 : monthsLengths[month]))
		{
			day -= ((year % 4 == 0 && month == 2) ? 29 : monthsLengths[month]);
			if (++month > 12 && year++) month = 1;
		}
	}

	if (days <= 0 || !isValid())
		this->year = this->month = this->day = 1;
}

bool Date::isValid() const
{
	bool flag = true;
	if (year < 1901 || year > 2099 \
		|| month < 1 || month > 12 || day < 1 \
		|| (day > monthsLengths[month] && (year%4 != 0 || month != 2 || day !=29))) 
		flag = false;
    return flag;
}
int Date::DayFromStart() const
{
	if (year == 1) return -1;
	
	int total = 0;
	total += (year - 1901) * 365;
	for (int m = 1; m < month; m++)
		total += monthsLengths[m];
	total += day;

	// add leap days
	if (year % 4 == 0 && month > 2) total++; //current year
	total += (year - 1901) / 4; // all previous leap years
	
	return total;	
}
const char* Date::DayOfWeek() const
{	
	if (year == 1) return "***";
	
	return daysOfWeek[DayFromStart() % 7];
}

Date& Date::operator=(const Date& other)
{
	day = other.day;
	month = other.month;
	year = other.year;

	return *this;
}
Date& Date::operator+(int days) const
{
	days += this->DayFromStart();
	Date* new_date = new Date(days);
	return *new_date;
}
int Date::operator-(const Date& date) const
{
	if (this->year == 1 || date.year == 1) return INT_MIN;

	int days = this->DayFromStart() - date.DayFromStart();
	return days;
}
Date& Date::operator++()
{
	if (year != 1 && ++day > monthsLengths[month])
		if (day = 1 && ++month > 12)
			if (month = 1 && ++year > 2099)
				day = month = year = 1;
	
	return *this;
}
Date Date::operator++(int)
{
	Date current(DayFromStart());
	
	if (year != 1 && ++day > monthsLengths[month])
		if (day = 1 && ++month > 12)
			if (month = 1 && ++year > 2099)
				day = month = year = 1;

	return current;
}
Date& Date::operator--()
{
	if (year != 1 && --day < 1)
	{
		if (--month == 0) month = 12;
		day = monthsLengths[month];
		if (month == 12 && --year < 1901) day = month = year = 1;
	}
	
	return *this;
}
Date Date::operator--(int)
{
	Date current(DayFromStart()); 
	
	if (year != 1 && --day < 1)
	{
		if (--month == 0) month = 12;
		day = monthsLengths[month];
		if (month == 12 && --year < 1901) day = month = year = 1;
	}	

	return current;
}

ostream& operator <<(ostream& os, const Date& dt)
{
    return os << setfill('0') << setw(2) << dt.day << " " << Date::monthsNames[dt.month] << " " << setw(4) << dt.year \
		<< ", " << dt.DayOfWeek();
}
istream& operator>>(istream& is, Date& dt)
{
	bool repeat;

	do
	{
		repeat = false;
		
		cout << "Enter year: ";
		is >> dt.year;
		cout << "Enter month: ";
		is >> dt.month;
		cout << "Enter day: ";
		is >> dt.day;

		if (!dt.isValid())
		{
			cout << "Wrong date" << endl << endl;
			repeat = true;
		}

	} while (repeat);

	return is;
}
// add Data class members and friend operators implementations
