#pragma once

#include <string>
#include <setup/PrecisionSetup.h>

using namespace Precision;
using namespace std;

class Scalar{
public:
	double a;

	Scalar();

	Scalar(double a);

	void parseInput(string input);

	string toString(){
		return presentDouble(a);
	}


	operator double();


	Scalar operator+(Scalar other);

	Scalar operator-(Scalar other);

	Scalar operator*(Scalar other);

	Scalar operator/(Scalar other);

	Scalar operator<(Scalar other);

	Scalar operator<=(Scalar other);

	Scalar operator>(Scalar other);

	Scalar operator>=(Scalar other);

	Scalar operator==(Scalar other);

	Scalar operator<(double other);

	Scalar operator<=(double other);

	Scalar operator>(double other);

	Scalar operator>=(double other);

	Scalar operator==(double other);

	Scalar &operator=(Scalar other);

	Scalar &operator=(double other);

	Scalar operator!();

	Scalar pow(Scalar index);
	Scalar pow(double index);
};

ostream &operator<<(ostream &stream, Scalar &scalar);
