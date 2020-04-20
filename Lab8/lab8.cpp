#include <iostream>
#include <math.h>
#include "digital_signal.h"
#include "signal_plot.h"

int main()
{
	std::cout << "===================== Part 1 (2 pts) =====================" << std::endl;
	
	Digital_signal ds_1;

	Digital_signal ds_2(10);

	int s3[20] = {0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5};
	Digital_signal ds_3(20,s3);

	cout << "Empty signal:" << endl;
	cout << ds_1 << endl;
	cout << "Zero signal:" << endl;
	cout << ds_2 << endl;
	cout << "Rectangular signal:" << endl;
	cout << ds_3 << endl;

	std::cout << "===================== Part 2 (2 pts) =====================" << std::endl;

	int s4[20];
	for (int i = 0; i < 20; i++) s4[i] = (int)(10*sin(2*3.14*0.5*i/10));
	Digital_signal ds_4 = Digital_signal(20, s4);

	Digital_signal ds_5(ds_4);
	ds_5 = ds_3 + 5;
	cout << "Sinusoidal signal:" << endl;
	cout << ds_4 << endl;
	cout << "Rectangular signal:" << endl;
	cout << ds_5 << endl;

	std::cout << "===================== Part 3 (2 pts) =====================" << std::endl;
	
	Signal_plot sp_1;

	Signal_plot sp_2(10);

	Signal_plot sp_3(20, s3);
	
	cout << "Empty signal:" << endl;
	cout << sp_1 << endl;
	cout << "Zero signal:" << endl;
	cout << sp_2 << endl;
	cout << "Rectangular signal:" << endl;
	cout << sp_3 << endl;

	std::cout << "===================== Part 4 (2 pts) =====================" << std::endl;

	Signal_plot sp_4(ds_4);

	int s5[50] = { 0, 2, 4, 6, 8, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10,
				  -8, -6, -4, -2, 0, 2, 4, 6, 8, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4 };
	Digital_signal tmp(50, s5);

	Signal_plot sp_5 = tmp;

	sp_2 = sp_1;
	sp_1 = sp_3;

	cout << "Sinusoidal signal:" << endl;
	cout << sp_4 << endl;
	cout << "Triangular signal:" << endl;
	cout << sp_5 << endl;
	cout << "Empty signal:" << endl;
	cout << sp_2 << endl;
	cout << "Rectangular signal:" << endl;
	cout << sp_1 << endl;

	return 0;
}