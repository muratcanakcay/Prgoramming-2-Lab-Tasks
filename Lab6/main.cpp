//#include "stdafx.h"
#include <iostream>
#include "matrix.h"

using namespace std;

const double matrix::eps = 1e-4f;

//---------------------------------------------------
int main()
{
	cout << " ---- PART 1 (2 points) ----" << endl;
	matrix A,       
			B(3),	
			C(4,10); 
		
	cout << "A - empty matrix:" << endl << A << endl;
	cout << "B - zero 3x3 matrix:" << endl << B << endl;
	cout << "C- 4x4 matrix filled with 10:" << endl << C << endl;

	cout << " ---- PART 2 (1 point) ----" << endl;
		const matrix D(C);
	cout << "D - const copy of C:" << endl << D << endl;		

	cout << "Element D(2,2): " << D(2, 2) << endl;
	C(1, 2) = 5;
	cout << "matrix C after setting C(1,2)=5:" << endl << C << endl;

	cout << " ---- PART 3 (2 points) ----" << endl;
	A = C;
	A.random(-10, 10); 
	cout << "random matrix with values [-10, 10]:" << endl << A << endl;
	cout<<"Transpose A:"<< A.transpose() << endl;
	cout << "A after transpose (not affected):" <<endl<< A << endl;

	B.random(0,3);
	cout << "B random [0,3]:" << endl << B << endl;

	cout << "Matrix 4x4 - eye:" <<endl<< matrix::eye(4) << endl;
	cout << "norm of the eye: " << C.eye(4).norm() << endl << endl;
	
	cout << " ---- PART 4 (2 points) ----" << endl;
	// operator+, opertor-, operator== 
		
	cout << "C = A+A = " << (C = A+A) << endl;
	cout << "C = C-A = " << (C= C-A) << endl;
	cout << "A==C? " << (A==C? "YES" : "NO") << endl;
	cout << endl;
	
	// oprator*
	double d = 1.5;
	cout << d<<"*C=" << (d*C) << endl;
	B = C;
	cout << "B = " << B << endl;
	cout << "A*B = " << (A*B) << endl;
	cout<<"norm B="<<B.norm()<<endl;
	cout<<"transpose B="<<B.transpose()<<endl;
		
	//---------------------------------------------------------------
	cout << " ---- PART 5 (1 point)----" << endl;
	{
		int w;

		cout << "Input size of matrix: " << endl;
		cin >> w;

		matrix A(w), A1(w), I(w);

		int aa, bb;
		cout << "Onput random numbers range [a,b]:" << endl;
		do {
			cout << "Give a = ";
			cin >> aa;
			cout << "Give b = ";
			cin >> bb;
		} while (aa >= bb);

		A.random(aa, bb);
		cout << "A=" << A << endl;

		A1 = A.pseudoinverse();

		I = matrix::eye(w); // I.eye(w) DOES NOT WORK !!!

		cout << "Matrix A1:" << A1 << endl;

		matrix S = A*A1;

		cout << "Check: S=A*A1=" << S << endl;

		if (S == I)
			cout << "Checking OK" << endl;
		else
			cout << "Check failed" << endl;
	}

	cout << "Bye" << endl;
	system("pause");
}

