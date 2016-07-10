#pragma once

#include <setup/AngleSetup.h>
#include "real.h"

BaseScalarType pol(BaseScalarType x, BaseScalarType y){
	_X_ = Scalar(sqrt(x * x + y * y));
	_Y_ = AngleSetup::convertAngleFromRad(x == 0.0 ? M_PI : atan2(y, x));
	return _X_;
}
