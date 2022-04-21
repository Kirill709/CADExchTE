#pragma once

#include <random>

#include "CurvesCM_Shape.h"

using PShape = std::shared_ptr<Shape3D>;

class Shape_generator
{
	enum shape_t { circle_t, ellipse_t, helix_t };

	static std::random_device aRandDev;
	//รัยื
	std::uniform_real_distribution<double> udd{ -1, 1 };
	std::uniform_int_distribution<> usd{ circle_t, helix_t };

public:

	void SetRange(double min, double max);
	PShape RandCircle2D();
	PShape RandEllipse2D();
	PShape RandHelix3D();
	PShape MakeRandomShape();
};