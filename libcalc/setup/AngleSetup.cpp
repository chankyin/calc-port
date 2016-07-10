#pragma once

#include "AngleSetup.h"

namespace AngleSetup{
	AngleSetup currentAngle = ANGLE_RAD;

	double convertAngleToRad(double angle){
		if(currentAngle == ANGLE_DEG){
			return angle * M_PI / 180;
		}
		if(currentAngle == ANGLE_GRAD){
			return angle * M_PI / 200;
		}
		return angle;
	}

	double convertAngleFromRad(double angle){
		if(currentAngle == ANGLE_DEG){
			return angle / M_PI * 180;
		}
		if(currentAngle == ANGLE_GRAD){
			return angle / M_PI * 200;
		}
		return angle;
	}
}
