#include "CurvesCM_ShapeGenerator.h"
#include "CurvesCM.h"
#include "CurvesCM_Circle.h"
#include "CurvesCM_Ellipse.h"
#include "CurvesCM_Helix.h"

constexpr double eps = 1e-6;

using PShape = std::shared_ptr<Shape3D>;
static std::random_device rd;

void Shape_generator::SetRange(double theMin, double theMax)
{
	if ((std::abs(theMax) + std::abs(theMin)) < 2 * eps)
		return;
	udd = decltype(udd){ theMin, theMax };
}

PShape Shape_generator::RandCircle2D()
{
	double radius=0.;
	while (radius < eps)
		radius = std::abs(udd(aRandDev));
	return std::make_shared<Circle>(Point3D{ udd(aRandDev), udd(aRandDev) }, radius);
}

PShape Shape_generator::RandEllipse2D()
{
	double radius_x=0.;
	while (radius_x < eps)
		radius_x = std::abs(udd(aRandDev));   // è > 0

	double radius_y=0.;
	while (radius_y < eps)
		radius_y = std::abs(udd(aRandDev));

	return std::make_shared<Ellipse>(Point3D{ udd(aRandDev), udd(aRandDev) }, radius_x, radius_y);
}

PShape Shape_generator::RandHelix3D()
{
	double aRadius=0.;
	while (aRadius < eps)
		aRadius = std::abs(udd(aRandDev));

	double aStep{};
	while (std::abs(aStep) < eps)
		aStep = udd(aRandDev);

	return std::make_shared<Helix3D>(Point3D{ udd(aRandDev), udd(aRandDev), udd(aRandDev) }, aRadius, aStep);
}

PShape Shape_generator::MakeRandomShape()
{
	switch (usd(rd))
	{
	case circle_t:
		return RandCircle2D();
	case ellipse_t:
		return RandEllipse2D();
	case helix_t:
		return RandHelix3D();
	default:
		return RandCircle2D();
	}
}

