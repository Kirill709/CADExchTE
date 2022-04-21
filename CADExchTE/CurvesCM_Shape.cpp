#include "CurvesCM_Shape.h"


std::ostream& operator<<(std::ostream& os, const Point3D& p)
{
	return os << "P(" << p.x << ", " << p.y << ", " << p.z << ")";
}

std::ostream& operator<<(std::ostream& os, const Vector3D& v)
{
	return os << "V(" << v.x << ", " << v.y << ", " << v.z << ")";
}


