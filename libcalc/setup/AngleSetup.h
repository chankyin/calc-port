#pragma once

#include <math.h>

namespace AngleSetup{
	enum AngleSetup{
		ANGLE_DEG,
		ANGLE_RAD,
		ANGLE_GRAD
	};

	extern AngleSetup currentAngle;

	double convertAngleFromRad(double angle);

	double convertAngleToRad(double angle);
}
