#pragma once

#include <setup/AngleSetup.h>
#include <global.h>

namespace CalcFunc{
	BaseScalarType factorial(BaseScalarType scalar);

	BaseScalarType nCr(BaseScalarType n, BaseScalarType r);

	BaseScalarType nPr(BaseScalarType n, BaseScalarType r);

	BaseScalarType x2(BaseScalarType x){
		return x * x;
	}

	BaseScalarType x3(BaseScalarType x){
		return x * x * x;
	}
}
