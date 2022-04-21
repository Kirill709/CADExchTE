#pragma once

#include "CurvesCM_Shape.h"

class Circle : public Shape3D 
{
	double rad{};
public:
	Circle() = default;
	Circle(const Point3D& center, double radius) : Shape3D(center), rad{ radius } {}

	virtual ~Circle() {}

	double myRadius() const;

	virtual Point3D myPointOnCurve(double t) const override;
	virtual Vector3D myCurveVector(double t) const override;
};
