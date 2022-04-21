#pragma once

#include <iostream>

struct Point3D
{
	double x{}, y{}, z{};
};

struct Vector3D
{
	double x{}, y{}, z{};
};

std::ostream& operator<<(std::ostream&, const Point3D&);
std::ostream& operator<<(std::ostream&, const Vector3D&);


class Shape3D
{
protected:
	Point3D c{}; 

	Shape3D() = default;
	Shape3D(const Point3D& center) : c{ center } {}

public:
	virtual ~Shape3D() {}

	virtual Point3D myPointOnCurve(double t) const = 0;   
	virtual Vector3D myCurveVector(double t) const = 0;
};