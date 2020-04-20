
#include <iostream>
#include "Date.h"

using namespace std;

int main()
    {

    cout << endl << "***** Part I *****" << endl << endl ;

    const Date date11(2019,3,19);
    Date date12(2019,4,1);
    Date date13(1901,1,1);
    Date date14(2099,12,31);
    Date date15(2100,1,1);
    Date date16(1900,12,31);
    Date date17(2000,13,13);
    Date date18(2000,12,32);
    const Date date19;
    cout << date11 << endl;
    cout << date12 << endl;
    cout << date13 << endl;
    cout << date14 << endl;
    cout << date15 << endl;
    cout << date16 << endl;
    cout << date17 << endl;
    cout << date18 << endl;
    cout << date18 << endl;

    cout << endl << "***** Part II *****" << endl << endl ;

    /*Date date2;
    cin >> date2;
    cout << date2 << endl;*/

    cout << endl << "***** Part III *****" << endl << endl ;

    Date date31(1);
    Date date32(32);
    Date date33(366);
    Date date34(777);  // 1903-02-16
    Date date35(0);
    Date date36(-10);
    Date date37(100000);
    cout << date31 << endl;
    cout << date32 << endl;
    cout << date33 << endl;
    cout << date34 << endl;
    cout << date35 << endl;
    cout << date36 << endl;
    cout << date37 << endl;
    cout << date31.DayFromStart() << endl;
    cout << date32.DayFromStart() << endl;
    cout << date33.DayFromStart() << endl;
    cout << date34.DayFromStart() << endl;
    cout << date35.DayFromStart() << endl;
    cout << date36.DayFromStart() << endl;
    cout << date37.DayFromStart() << endl;

    cout << endl << "***** Part IV *****" << endl << endl ;

    Date date4a(1901,1,1);
    cout << date4a << endl;
    cout << date4a+90 << endl;
    cout << date4a+100000 << endl;
    cout << date4a+-1 << endl;

    cout << endl;

    Date date4s(1901,4,1);
    cout << date4s-date4a << endl;
    cout << date4a-date4s << endl;
    Date date4e;
    cout << date4e-date4s << endl;
    cout << date4s-date4e << endl;

    cout << endl;

    Date date41i(2019,3,19);
    Date date42i(2019,3,19);
    Date date43i, date44i;
    cout << date41i << endl;
    cout << date42i << endl;
    date43i = ++date41i;
    date44i = date42i++;
    cout << date43i << endl;
    cout << date44i << endl;
    Date date45i(2099,12,31);
    cout << date45i++ << endl;
    cout << date45i << endl;
    cout << ++date45i << endl;
    cout << --date45i << endl;
    ++date43i = date44i;
    cout << date43i << endl;

    cout << endl;

    Date date41d(2019,3,19);
    Date date42d(2019,3,19);
    Date date43d, date44d;
    cout << date41d << endl;
    cout << date42d << endl;
    date43d = --date41d;
    date44d = date42d--;
    cout << date43d << endl;
    cout << date44d << endl;
    Date date45d(1901,1,1);
    cout << date45d-- << endl;
    cout << date45d << endl;
    cout << --date45d << endl;
    cout << ++date45d << endl;
    --date43d = date44d;
    cout << date43d << endl;

    cout << endl << "***** Part V *****" << endl << endl ;

    Date date51(2020,2,29);
    cout << date51 << endl;
    Date date52(2020,2,28);
    cout << date52+1 << endl;
    cout << date52+1 << endl;
    cout << date52+2 << endl;
    cout << date52+3 << endl;

    cout << endl << "***** Part VI *****" << endl << endl ;

    Date date61(1901,1,1);
    Date date62(2019,3,19);
    Date date63;
    cout << date61.DayOfWeek() << endl;
    cout << date62.DayOfWeek() << endl;
    cout << date63.DayOfWeek() << endl;
    cout << date61 << endl;
    cout << date62 << endl;
    cout << date63 << endl;

    return 0;
    }
