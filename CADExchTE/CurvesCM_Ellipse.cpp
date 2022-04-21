#include <cmath>

#include "CurvesCM_Ellipse.h"


Point3D Ellipse::myPointOnCurve(double t) const
{
	return Point3D
	{
			RadX * std::cos(t) + c.x,
			RadY * std::sin(t) + c.y,
			c.z
	};
}

Vector3D Ellipse::myCurveVector(double t) const
{
	return Vector3D
	{
			-1 * RadX * std::sin(t),
			RadY * std::cos(t)
	};
}
