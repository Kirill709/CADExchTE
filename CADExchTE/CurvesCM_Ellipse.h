#pragma once

#include "CurvesCM_Shape.h"
class Ellipse : public Shape3D
{
	double RadX{};
	double RadY{};

public:
	Ellipse() = default;
	Ellipse(const Point3D& center, double rad_x, double rad_y) : Shape3D(center), RadX{ rad_x }, RadY{ rad_y } {}

	virtual ~Ellipse() {}

	virtual Point3D myPointOnCurve(double t) const override;
	virtual Vector3D myCurveVector(double t) const override;
};