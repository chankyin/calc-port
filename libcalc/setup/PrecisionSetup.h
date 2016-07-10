#pragma once

#include <string>
#include <sstream>
#include <setup/PrecisionType.h>
#include <math.h>

using namespace std;

namespace Precision{
	class PrecisionSetup{
	public:
		PrecisionType type;
		int value;

		PrecisionSetup(PrecisionType type, int value);

		void operator()(PrecisionSetup newSetup);
	};

	const PrecisionSetup
			PRECISION_FIX_0(Precision::FIX, 0),
			PRECISION_FIX_1(Precision::FIX, 1),
			PRECISION_FIX_2(Precision::FIX, 2),
			PRECISION_FIX_3(Precision::FIX, 3),
			PRECISION_FIX_4(Precision::FIX, 4),
			PRECISION_FIX_5(Precision::FIX, 5),
			PRECISION_FIX_6(Precision::FIX, 6),
			PRECISION_FIX_7(Precision::FIX, 7),
			PRECISION_FIX_8(Precision::FIX, 8),
			PRECISION_FIX_9(Precision::FIX, 9),
			PRECISION_SCI_0(Precision::SCI, 0),
			PRECISION_SCI_1(Precision::SCI, 1),
			PRECISION_SCI_2(Precision::SCI, 2),
			PRECISION_SCI_3(Precision::SCI, 3),
			PRECISION_SCI_4(Precision::SCI, 4),
			PRECISION_SCI_5(Precision::SCI, 5),
			PRECISION_SCI_6(Precision::SCI, 6),
			PRECISION_SCI_7(Precision::SCI, 7),
			PRECISION_SCI_8(Precision::SCI, 8),
			PRECISION_SCI_9(Precision::SCI, 9),
			PRECISION_NORM_1(Precision::NORM, 1),
			PRECISION_NORM_2(Precision::NORM, 2);

	extern PrecisionSetup currentPrecision;

	string presentDouble(double d);
}
