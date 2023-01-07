#ifndef PRECALCS_H
#define PRECALCS_H

class startParameters {
public:
	double endTime{  };
	double xVelocity{  };
	double yVelocity{  };
	double dragConst{  };
	double stepSize{  };
};

startParameters calcFunction(double initialVelocity, double diameter, double mass, double angle);

#endif 