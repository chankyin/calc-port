#pragma once

#include "PrecisionSetup.h"

using namespace Precision;

Precision::PrecisionSetup::PrecisionSetup(PrecisionType type, int value){
	this->type = type;
	this->value = value;
}

void Precision::PrecisionSetup::operator()(PrecisionSetup newSetup){
	if(this != &currentPrecision){
		throw "Attempt to change precision setup constants";
	}
	this->type = newSetup.type;
	this->value = newSetup.value;
}

PrecisionSetup Precision::currentPrecision(NORM, 1);

string Precision::presentDouble(double d){
	int type = currentPrecision.type; // an internal "goto" instructor
	int precision = currentPrecision.value; // this will be the eventual round precision if rounding is required

	// output values
	double output;
	double outputExp;

	double log = log10(fabs(d));
	if(type == Precision::NORM){
		if(d != 0 && log < (precision == 1 ? -2.0 : -9.0) || // too small
		   log >= 10.0){ // too big
			type = Precision::SCI;
			precision = 0;
			// goto SCI;
		}else{ // no scientific notation needed!
			output = d;
			outputExp = 0;
			// goto DONE;
		}
	}
	if(type == Precision::SCI){ // SCI:
		if(d == 0.0){
			output = 0.0;
			outputExp = 0;
		}else{
			outputExp = floor(log);
			d *= pow(10, -outputExp);
			precision -= 1;
			if(precision == -1){
				output = d; // goto DONE;
			}else{
				type = Precision::FIX;
				// goto FIX;
			}
		}
	}
	if(type == Precision::FIX){ // FIX:
		if(d == 0.0){
			output = 0.0;
			outputExp = 0;
		}else{
			double exponent = pow(10, precision);
			output = round(d * exponent) / exponent;
			if(currentPrecision.type == Precision::FIX){
				outputExp = 0;
			} // else outputExp already defined
		}
	}
	// DONE:
	ostringstream os;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
	os << output;
	if(outputExp != 0){
		os << " e " << outputExp;
	}
#pragma clang diagnostic pop
	return os.str();
}
