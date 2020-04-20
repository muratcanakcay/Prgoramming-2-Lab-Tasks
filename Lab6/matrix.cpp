//#include "stdafx.h"
#include <iostream>
using namespace std;
#include <ctime>
#include <iomanip>
#include<cmath>
#include "matrix.h"

//-------------------------------------------------------------------
void matrix::init(int n)	
{
	this->n = (n < 0 || n > 10) ? 0 : n; 
}
//-------------------------------------------------------------------
void matrix::fill(double d, double tab[][N])
{
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->n; j++)
			t[i][j] = (tab) ? tab[i][j] : d;	
}
//-------------------------------------------------------------------
matrix::matrix( int n, double d )
{ 
	init(n);
	fill(d);
}
//-------------------------------------------------------------------
void matrix::random(int a, int b)
{
	srand(unsigned(time(nullptr)));
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->n; j++)
			t[i][j] = (double)(rand() % (b - a + 1)) + (double)a;
}
//-------------------------------------------------------------------
matrix matrix::eye(int _n)
{
	matrix I(_n);
	for (int i = 0; i < _n; i++)
		I.t[i][i] = 1;
	return I;
}
//-------------------------------------------------------------------
double matrix::norm() const
{
	int n = this->n; 
	double sum = 0.0;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum += pow(this->t[i][j], 2);
	
	double norm = sqrt(sum);
	return norm;
}
//-------------------------------------------------------------------
matrix matrix::transpose() const
{
	int n = this->n; 
	matrix T(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			T.t[i][j] = this->t[j][i];
	return T;
}
//-------------------------------------------------------------------
//ADD MISSING
matrix::matrix(matrix& M)
{
	init(M.n);
	fill(0, M.t);
}
double& matrix::operator()(int i, int j)
{
	return this->t[i][j];
}
double matrix::operator()(int i, int j) const
{
	return this->t[i][j];
}

matrix& matrix::operator=(const matrix& other)
{
	int n = this->n = other.n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			this->t[i][j] = other.t[i][j];
	return *this;
}
matrix& matrix::operator+(const matrix& other) const
{
	int n = this->n;
	matrix* S = new matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			S->t[i][j] = this->t[i][j] + other.t[i][j];
	return *S;
}
matrix& matrix::operator-(const matrix& other) const
{
	int n = this->n;
	matrix* S = new matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			S->t[i][j] = this->t[i][j] - other.t[i][j];
	return *S;
}
bool matrix::operator==(const matrix& other) const
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (abs(this->t[i][j] - other.t[i][j]) > eps) 
				return false;
	return true;
}
matrix& matrix::operator*(const matrix& other) const
{
	int n = this->n;
	matrix* M = new matrix(n);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				M->t[i][j] += this->t[i][k] * other.t[k][j];
			
	return *M;
}
matrix& operator*(double d, matrix M)
{
	int n = M.n;
	matrix* R = new matrix(M);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			R->t[i][j] = d * M.t[i][j];

	return *R;
}

//-------------------------------------------------------------------
matrix matrix::pseudoinverse() const 
{
	double norm = this->norm();
	double alpha = 1 / pow(norm, 2);
	
	matrix At, Ak, Ak1, I, diff;
	I = eye(this->n);
	At = this->transpose();
	Ak = alpha * At;

	for (int i = 0; i < 100000; i++)
	{
		Ak1 = Ak + (Ak * (I - (*this*Ak)));
		
		diff = Ak1 - Ak;
		if (diff.norm() < eps) break;
		
		Ak = Ak1;
	}

	return Ak1;
}
//-------------------------------------------------------------------
ostream& operator << ( ostream& os, const matrix& m )
{
	if (!m.n) return os << "empty matrix!" << endl;

	os << endl;
	for( int i=0; i<m.n; i++ ) 
	{
		os << "| ";
		for( int j=0; j<m.n; j++ ) os << fixed<<setprecision(3)<<setw(8)<<m.t[i][j]<<" ";
		os << " |" << endl;
	}
	return os;
}
//-------------------------------------------------------------------

