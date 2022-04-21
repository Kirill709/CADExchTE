#include <cmath>

#include "CurvesCM_Helix.h"


Point3D Helix3D::myPointOnCurve(double t) const
{
	return Point3D
	{
			Rad * t * std::cos(t) + c.x,
			Rad * t * std::sin(t) + c.y,
			Step * t + c.z
	};
}
Vector3D Helix3D::myCurveVector(double t) const
{
	return Vector3D
	{
			Rad * (std::cos(t) - t * std::sin(t)),
			Rad * (std::sin(t) + t * std::cos(t)),
			Step
	};
}