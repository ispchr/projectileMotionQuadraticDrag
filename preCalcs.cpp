/*
	preCalcs.cpp
	Purpose: Calculates required parameters to run the RK4 calculation loop
s	@version 1 26/1/2022
*/

#include <cmath>
#include "constants.h"
#include "preCalcs.h"

startParameters calcFunction(double initialVelocity, double diameter, double mass, double angle) {

	startParameters calcAns{  };

	double end{ 2 * initialVelocity * sin(angle * constants::pi / 180) / constants::g };

	double u{ initialVelocity * cos(angle * constants::pi / 180) };
	double v{ initialVelocity * sin(angle * constants::pi / 180) };

	double area{ constants::pi * diameter * diameter / 4.0 };
	double dragConst{ constants::cd * area * constants::rho / (2.0 * mass) };

	double h{ end / constants::N };

	calcAns.endTime = end;
	calcAns.xVelocity = u;
	calcAns.yVelocity = v;
	calcAns.dragConst = dragConst;
	calcAns.stepSize = h;

	return calcAns;
}
