#pragma once

#include <math.h>
#include <sstream>
#include "Scalar.h"
#include <objects/CalcErrors.h>
#include <internals.h>

using namespace std;

Scalar::Scalar(double a){
	if(log10(fabs(a)) > 100.0){ // fine, I accept 1E100.
		throw CalcErrors::MATH_BEYOND_RANGE;
	}
	this->a = a;
}

Scalar::Scalar(){
	a = 0;
}

void Scalar::parseInput(string input){
	istringstream(input) >> a;
}

ostream &operator<<(ostream &stream, Scalar &scalar){
	stream << scalar.toString();
	return stream;
}

Scalar::operator double(){
	return a;
}

Scalar Scalar::operator+(Scalar other){
	return Scalar(a + other.a);
}

Scalar Scalar::operator-(Scalar other){
	return Scalar(a - other.a);
}

Scalar Scalar::operator*(Scalar other){
	return Scalar(a * other.a);
}

Scalar Scalar::operator/(Scalar other){
	if(other.a == 0.0){
		throw CalcErrors::MATH_DIV_BY_ZERO;
	}
	return Scalar(a / other.a);
}

Scalar Scalar::operator<(Scalar other){
	return a < other.a;
}

Scalar Scalar::operator<=(Scalar other){
	return a <= other.a;
}

Scalar Scalar::operator>(Scalar other){
	return a > other.a;
}

Scalar Scalar::operator>=(Scalar other){
	return a >= other.a;
}

Scalar Scalar::operator==(Scalar other){
	return a == other.a;
}

Scalar Scalar::operator<(double other){
	return a < other;
}

Scalar Scalar::operator<=(double other){
	return a <= other;
}

Scalar Scalar::operator>(double other){
	return a > other;
}

Scalar Scalar::operator>=(double other){
	return a >= other;
}

Scalar Scalar::operator==(double other){
	return a == other;
}

Scalar &Scalar::operator=(Scalar other){
	a = other.a;
	return *this;
}

Scalar &Scalar::operator=(double other){
	a = other;
	return *this;
}

Scalar Scalar::operator!(){
	double intPart;
	if(!isIntegral(a, &intPart)){
		throw CalcErrors::MATH_NON_INT;
	}
	double output = 1;
	for(int i = 2; i <= intPart; i++){
		output *= i;
	}
	return Scalar(output);
}

Scalar Scalar::pow(Scalar index){
	return Scalar(::pow(a, index.a));
}
Scalar Scalar::pow(double index){
	return Scalar(::pow(a, index));
}
