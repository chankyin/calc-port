#pragma once

#include "ComplexScalar.h"
#include <internals.h>
#include <func/ops.h>
#include <objects/CalcErrors.h>

using namespace Precision;
using namespace std;
using namespace CalcFunc;

ComplexScalar::ComplexScalar(){
	a = b = 0;
}

ComplexScalar::ComplexScalar(double a){
	if(log10(a) > 100.0){ // fine, I accept 1E100.
		throw CalcErrors::MATH_BEYOND_RANGE;
	}
	this->a = a;
	b = 0;
}

ComplexScalar::ComplexScalar(double a, double b){
	if(log10(a) > 100.0){ // fine, I accept 1E100.
		throw CalcErrors::MATH_BEYOND_RANGE;
	}
	if(log10(b) > 100.0){ // fine, I accept 1E100.
		throw CalcErrors::MATH_BEYOND_RANGE;
	}
	this->a = a;
	this->b = b;
}

ComplexScalar::ComplexScalar(Scalar scalar){
	a = scalar.a;
}

void ComplexScalar::parseInput(string input){
	unsigned long offset = input.find(',');
	istringstream(input.substr(0, offset)) >> a;
	istringstream(input.substr(offset + 1)) >> b;
}

string ComplexScalar::toString(){
	return presentDouble(a) + " + " + presentDouble(b) + " i";
}

ostream &operator<<(ostream &stream, ComplexScalar &scalar){
	stream << scalar.toString();
	return stream;
}

ComplexScalar::operator double(){
	return a;
}

ComplexScalar ComplexScalar::operator+(ComplexScalar other){
	return ComplexScalar(a + other.a, b + other.b);
}

ComplexScalar ComplexScalar::operator-(ComplexScalar other){
	return ComplexScalar(a + other.a, b + other.b);
}

ComplexScalar ComplexScalar::operator*(ComplexScalar other){
	double a(this->a), b(this->b), c(other.a), d(other.b);
	return ComplexScalar(a * c - b * d, a * d + b * c);
}

ComplexScalar ComplexScalar::operator/(ComplexScalar other){
	double a(this->a), b(this->b), c(other.a), d(other.b);
	double cdSq = c * c + d * d;
	return ComplexScalar((a * c + b * d) / cdSq, (b * c - a * d) / cdSq);
}

ComplexScalar ComplexScalar::operator<(ComplexScalar other){
	if(b != 0 || other.b != 0){
		throw CalcErrors::MATH_NON_REAL;
	}
	return a < other.a;
}

ComplexScalar ComplexScalar::operator<=(ComplexScalar other){
	if(b != 0 || other.b != 0){
		throw CalcErrors::MATH_NON_REAL;
	}
	return a <= other.a;
}

ComplexScalar ComplexScalar::operator>(ComplexScalar other){
	if(b != 0 || other.b != 0){
		throw CalcErrors::MATH_NON_REAL;
	}
	return a > other.a;
}

ComplexScalar ComplexScalar::operator>=(ComplexScalar other){
	if(b != 0 || other.b != 0){
		throw CalcErrors::MATH_NON_REAL;
	}
	return a >= other.a;
}

ComplexScalar ComplexScalar::operator==(ComplexScalar other){
	return a == other.a && b == other.b;
}

ComplexScalar ComplexScalar::operator<(double other){
	if(b != 0){
		throw CalcErrors::MATH_NON_REAL;
	}
	return a < other;
}

ComplexScalar ComplexScalar::operator<=(double other){
	if(b != 0){
		throw CalcErrors::MATH_NON_REAL;
	}
	return a <= other;
}

ComplexScalar ComplexScalar::operator>(double other){
	if(b != 0){
		throw CalcErrors::MATH_NON_REAL;
	}
	return a > other;
}

ComplexScalar ComplexScalar::operator>=(double other){
	if(b != 0){
		throw CalcErrors::MATH_NON_REAL;
	}
	return a >= other;
}

ComplexScalar ComplexScalar::operator==(double other){
	return a == other && b == 0;
}

ComplexScalar &ComplexScalar::operator=(ComplexScalar other){
	a = other.a;
	b = other.b;
	return *this;
}

ComplexScalar &ComplexScalar::operator=(double other){
	a = other;
	b = 0;
	return *this;
}

ComplexScalar ComplexScalar::operator!(){
	double intPart;
	if(b != 0){
		throw CalcErrors::MATH_NON_REAL;
	}
	if(!isIntegral(a, &intPart)){
		throw CalcErrors::MATH_NON_INT;
	}
	double output = 1;
	for(int i = 2; i <= intPart; i++){
		output *= i;
	}
	return ComplexScalar(output);
}
ComplexScalar ComplexScalar::pow(ComplexScalar index){
	if(index.b != 0){
		throw CalcErrors::MATH_NON_REAL;
	}
	if(index == 2.0){
		return x2(*this);
	}
	if(index == 3.0){
		return x3(*this);
	}
}
ComplexScalar ComplexScalar::pow(double index){

}
