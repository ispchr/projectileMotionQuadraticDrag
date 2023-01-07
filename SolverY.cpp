/*
	Solver.cpp
	Purpose: Solves y-component of the ODE with the 
	RK4 numerical scheme
	@version 1 26/1/2022
*/

#include <cmath>
#include "constants.h"
#include "Solver.h"

// Expressing 2nd Order ODE as a System of 1st Order ODEs
double ODEy0(double v) {
	return v;
}

double ODEy1(double dragConst, double u, double v) {
	return -dragConst * v * std::sqrt(u * u + v * v) - constants::g;
}

RK4 SolverY(double y, double dragConst, double u, double v, double h) {

	RK4 Y{  };

	double lOne{ h * ODEy0(v) };
	double kOne{ h * ODEy1(dragConst, u, v) };

	double lTwo{ h * ODEy0(v + kOne / 2.0)};
	double kTwo{ h * ODEy1(dragConst, u, v + kOne / 2.0) };

	double lThree{ h * ODEy0(v + kTwo / 2.0) };
	double kThree{ h * ODEy1(dragConst, u, v + kTwo / 2.0) };

	double lFour{ h * ODEy0(v + kThree) };
	double kFour{ h * ODEy1(dragConst, u, v + kThree) };

	y += (lOne / 6.0 + lTwo / 3.0 + lThree / 3.0 + lFour / 6.0);
	v += (kOne / 6.0 + kTwo / 3.0 + kThree / 3.0 + kFour / 6.0);

	Y.coordinate = y;
	Y.velocity = v;
	return Y;
}
