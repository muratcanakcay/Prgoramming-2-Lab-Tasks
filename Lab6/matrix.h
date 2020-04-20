#pragma once
#include <iostream>

const int N = 10; // maximum matrix size

class matrix
{
	double t[N][N];
	int		n;					// actual size

	void init(int size);	
	void fill(double d = 0, double tab[][N] = {} );

	static const double eps;

public:
	explicit matrix( int n=0, double d=0 );
	matrix(matrix& M);
	
	void	random( int a, int b);				
	static matrix eye(int);						

	double  norm() const;
	matrix	transpose() const;
	matrix  pseudoinverse() const;
		
// ADD MISSING 

	double& operator()(int i, int j);
	double operator()(int i, int j) const;
	matrix& operator=(const matrix& other);
	matrix& operator+(const matrix& other) const;
	matrix& operator-(const matrix& other) const;
	bool operator==(const matrix& other) const;
	matrix& operator*(const matrix& other) const;
	friend matrix& operator*(double d, matrix M);

	friend std::ostream&	operator << ( std::ostream& os, const matrix& m );
  
};


