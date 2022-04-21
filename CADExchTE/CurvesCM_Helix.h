#pragma once

#include "CurvesCM_Shape.h"

class Helix3D : public Shape3D
{
	double Rad{};
	double Step{};

public:
	Helix3D() = default;
	Helix3D(const Point3D& center, double radius, double step_z) : Shape3D(center), Rad{ radius }, Step{ step_z } {}

	virtual ~Helix3D() {}

	virtual Point3D myPointOnCurve(double t) const override;
	virtual Vector3D myCurveVector(double t) const override;
};
