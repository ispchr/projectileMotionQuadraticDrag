/*
	SolverX.cpp
	Purpose: Solves x-component of the ODE with the
	RK4 numerical scheme
	@version 1 26/1/2022
*/


#include <cmath>
#include "constants.h"
#include "solver.h"

// Expressing 2nd Order ODE as a System of 1st Order ODEs
double ODEx0(double u) {
	return u;
}

double ODEx1(double dragConst, double u, double v) {
	return -dragConst * u * std::sqrt(u * u + v * v);
}

RK4 SolverX(double x, double dragConst, double u, double v, double h) {

	RK4 X{  };

	double lOne{ h * ODEx0(u) };
	double kOne{ h * ODEx1(dragConst, u, v) };

	double lTwo{ h * ODEx0(u + kOne / 2.0) };
	double kTwo{ h * ODEx1(dragConst, u + kOne / 2.0, v) };

	double lThree{ h * ODEx0(u + kTwo / 2.0) };
	double kThree{ h * ODEx1(dragConst, u + kTwo / 2.0, v) };

	double lFour{ h * ODEx0(u + kThree) };
	double kFour{ h * ODEx1(dragConst, u + kThree, v) };

	x += (lOne / 6.0 + lTwo / 3.0 + lThree / 3.0 + lFour / 6.0);
	u += (kOne / 6.0 + kTwo / 3.0 + kThree / 3.0 + kFour / 6.0);

	X.coordinate = x;
	X.velocity = u;
	return X;
}