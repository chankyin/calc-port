#pragma once

#include "ops.h"

BaseScalarType factorial(BaseScalarType scalar){
	return !scalar;
}

BaseScalarType nCr(BaseScalarType n, BaseScalarType r){
	return !n / !(n - r);
}

BaseScalarType nPr(BaseScalarType n, BaseScalarType r){
	return nCr(n, r) / !r;
}
