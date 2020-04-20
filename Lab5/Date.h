
#pragma once

# include <iostream>

using namespace std;

class Date
{
    private:
		int year;
		int month;
		int day;

		static int monthsLengths[];
		static const char *monthsNames[];
		static const char *daysOfWeek[];
		
		bool isValid() const;

    public:
	
		Date();
		Date(int year, int month, int day);
		Date(int days);

		int DayFromStart() const;
		const char* DayOfWeek() const;

		Date& operator=(const Date& other);
		Date& operator+(int days) const;
		int operator-(const Date& date) const;
		Date& operator++();
		Date operator++(int);
		Date& operator--();
		Date operator--(int);
		
		friend ostream& operator<<(ostream& os, const Date& dt);
		friend istream& operator>>(istream& is, Date& dt);

		// add needed public members and friend operators declarations

};
