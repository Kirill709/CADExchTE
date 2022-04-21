#pragma once

#include <iostream>
#include <vector>
#include "CurvesCM_Shape.h"
#include "CurvesCM_ShapeGenerator.h"

//===========================================================
class aCurveMaker
{
private:
	const double pi = acos(-1);
	double aRadSum;
public:
	aCurveMaker() = default;
	// Функция, фактически выполняющая задачу по созданию и сортировке
	void Perform();
	// Генерация случайных типов фигур со случайными параметрами
	std::vector<PShape> ProcessShapeGeneration();
	//Вывод созданных фигур
	void ShapesOutput(std::vector<PShape> aVShapes);
};