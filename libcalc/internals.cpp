#pragma once

#include "internals.h"

bool isIntegral(double d){
	return isIntegral(d, new double);
}

bool isIntegral(double d, double *intPart){
	return modf(d, intPart) == 0.0;
}
