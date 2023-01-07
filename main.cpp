/*
	main.cpp
	Purpose: Calculates and writes the coordinates of a projectile
	with quadratic drag
	@version 1 26/1/2022
*/

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "preCalcs.h"
#include "Solver.h"
#include "constants.h"
#include "preCalcs.h"

// Returns user input 
double askInput(std::string inputName) {
	std::cout << inputName << " = ";
	double input{  };
	std::cin >> input;
	return input;
};

// Controls program
int main()
{
	std::cout << "----------------------------------------------\n";
	std::cout << "    Projectile Motion with Quadratic Drag    \n";
	std::cout << "		version 1.0    \n";
	std::cout << "----------------------------------------------\n";
	std::cout << "Enter you Initial Conditions Below    \n";

	// Taking user inputs
	double mass{ askInput("Object Mass") };
	double angle{ askInput("Initial Angle") };
	double initialVelocity{ askInput("Initial Velocity") };
	double diameter{ askInput("Object Diameter") };
	double x{ askInput("Initial X-Position") };
	double y{ askInput("Initial Y-Position") };

	// Initializing Calculation Function for Start Parameters
	startParameters calcd{  };
	calcd = calcFunction(initialVelocity, diameter, mass, angle);
	double u = calcd.xVelocity;
	double v = calcd.yVelocity;
	double dragConst = calcd.dragConst;
	double h = calcd.stepSize;

	std::cout << "----------------------------------------------\n";
	std::cout << "Initializing Simulation ..." << '\n';
	std::cout << "End time = " << calcd.endTime << " s" << '\n';
	std::cout << "Initial x - velocity = " << u << " m/s" << '\n';
	std::cout << "Initial y - velocity = " << v << " m/s" << '\n';
	std::cout << "Step size = " << h << ' s' << '\n';

	// Defines start time
	double t{ 0 };

	std::cout << "----------------------------------------------\n";
	std::cout << "t" << '\t' << "x" << '\t' << "y" << '\n';

	// Creating file to write data
	std::ofstream dataOut;
	dataOut.open("projectileCoordinates.txt");

	// Initializing Members X and Y of RK4 class to output results from solvers
	RK4 X{ }, Y{ };

	// Initializing Row and Column Dummy Parameters (To Help Print the Results)
	int row{  };
	int column{  };

	for (row = 0; row < constants::N + 1; ++row)
	{		
		// Breaking Out of The Calculation Loop Once the Ground ( y < 0 ) is Reached 
		if (y < 0)
			break;
		for (column = 0; column < 3; ++column)
			if (column < 1)
			{
				dataOut << t << '\t';
				std::cout << t << '\t';
				t += h;
			}
			else if (column < 2)
			{
				std::cout << x << '\t';			
				dataOut << x << '\t';
				X = SolverX(x, dragConst, u, v, h);
				x = X.coordinate;
				u = X.velocity;
			}
			else
			{
				std::cout << y << '\n';
				dataOut << y << '\n';
				Y = SolverY(y, dragConst, u, v, h);
				y = Y.coordinate;
				v = Y.velocity;
			}
	}
	return 0;
}
