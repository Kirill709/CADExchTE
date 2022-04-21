#include <cmath>

#include "CurvesCM_Circle.h"

double Circle::myRadius() const 
{ 
	return rad; 
}

Point3D Circle::myPointOnCurve(double t) const
{
	return Point3D
	{
			rad * std::cos(t) + c.x,
			rad * std::sin(t) + c.y,
			c.z
	};
}

Vector3D Circle::myCurveVector(double t) const
{
	return Vector3D
	{
			-1 * rad * std::sin(t),
			rad * std::cos(t)
	};
}
