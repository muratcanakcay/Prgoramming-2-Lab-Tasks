#include <iostream>
#include "Array.h"
#include "Polynomial.h"

int main()
{
	int arr1[] = {1, 2, 3};
	int arr2[] = {-8, -2, 1};
	int arr3[] = { 2, -3, 1 };

	cout << "****** Part 1 - (2 points ) *****" << endl << endl;

	Array t0;
	Array t1(3);
	Array t2(3, arr1);
	Array t3(t2);
	Array t4;
	t4 = t3;

	cout << t0 << endl;
	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;
	cout << t4 << endl;

	cout << endl << "****** Part 2 - (2 points) *****" << endl << endl;

	t3 = Array(3, arr3);
	t0 = t0 + t3; // empty Array - not equal sizes
	t4 = t2 + t3;
	t4 = t4 - t1;
	t2 *= 2;

	cout << t0 << endl;
	cout << t4 << endl;
	cout << t2 << endl;

	cout << endl << "****** Part 3 - (1 point) *****" << endl << endl;

	Polynomial p0;
	Polynomial p1(2);				
	Polynomial p2(2, arr1);		
	Polynomial p3(p2);			
	Polynomial p4;
	p4 = p3;			

	cout << p0 << endl;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	cout << p4 << endl;

	Polynomial *arr[2] = { new Polynomial(2, arr1), new Polynomial(2, arr2) };
	cout << "Dynamic allocation : " << endl;
	for (int i = 0; i < 2; i++)
		cout << *arr[i] << endl;

	for (int i = 0; i < 2; i++)
		delete arr[i];


	cout << endl << "****** Part 4 - (1 point)  *****" << endl << endl;

	p2 *= 2;
	cout << p2 << endl;

	p0 = p0 + p3; //give empty polynomial - not equal degree
	p4 = p2 + p2;
	p4 = p4 - p1;

	cout << p0 << endl;
	cout << p4 << endl;
	
	//cout << endl << "****** Part 5 - (2 points)  *****" << endl << endl;

	//int it;
	//Polynomial p5(2, arr3);
	//cout << "p5 = " << p5 << endl;
	//cout << "p5' = " << p5.derivtive() << endl;
	//double x;
	//x = 0.5; cout << "p5(" << x << ") = " << p5(x) << endl;
	//x = 1; cout << "p5(" << x << ") = " << p5(x) << endl;
	//x = 1.5; cout << "p5(" << x << ") = " << p5(x) << endl;
	////x = 2; cout << "p5(" << x << ") = " << w5(x) << endl;
	////x = 2.5; cout << "p5(" << x << ") = " << w5(x) << endl;
	//
	//cout << "root p5(x0=0) = " <<  poly_root(p5, 0, it) << endl;
	//cout << "root p5(x0=1.3) = " << poly_root(p5, 1.3, it) << endl;
	//cout << "root p5(x0=1.6) = " << poly_root(p5, 1.6, it) << endl;

	system("pause");
	return 0;
}

