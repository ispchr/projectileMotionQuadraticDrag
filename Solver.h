#ifndef SOLVER_H
#define SOLVER_H

class RK4{
public:
	double coordinate{  };
	double velocity{  };
};

RK4 SolverX(double x, double dragConst, double u, double v, double h);
RK4 SolverY(double y, double dragConst, double u, double v, double h);

#endif 
