#pragma once

#include <math.h>
#include <objects/Scalar.h>

using namespace std;

class ComplexScalar{

public:
	double a;
	double b;

	ComplexScalar();

	ComplexScalar(double a);

	ComplexScalar(double a, double b);

	ComplexScalar(Scalar scalar);

	void parseInput(string input);

	string toString();


	operator double();


	ComplexScalar operator+(ComplexScalar other);

	ComplexScalar operator-(ComplexScalar other);

	ComplexScalar operator*(ComplexScalar other);

	ComplexScalar operator/(ComplexScalar other);

	ComplexScalar operator<(ComplexScalar other);

	ComplexScalar operator<=(ComplexScalar other);

	ComplexScalar operator>(ComplexScalar other);

	ComplexScalar operator>=(ComplexScalar other);

	ComplexScalar operator==(ComplexScalar other);

	ComplexScalar operator<(double other);

	ComplexScalar operator<=(double other);

	ComplexScalar operator>(double other);

	ComplexScalar operator>=(double other);

	ComplexScalar operator==(double other);

	ComplexScalar &operator=(ComplexScalar other);

	ComplexScalar &operator=(double other);

	ComplexScalar operator!();

	ComplexScalar pow(ComplexScalar index);
	ComplexScalar pow(double index);
};

ostream &operator<<(ostream &stream, ComplexScalar &scalar);
