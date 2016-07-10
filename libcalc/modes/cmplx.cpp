#pragma once

#include "cmplx.h"

ComplexScalar *conjg(ComplexScalar *input){
	ComplexScalar *result = new ComplexScalar(input->a, -input->b);
	return result;
}

BaseScalarType *arg(ComplexScalar *input){
	return new BaseScalarType(atan2(input->b, input->a));
}
