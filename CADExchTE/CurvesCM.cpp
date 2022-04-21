#include <omp.h>

#include <iostream>
#include <vector>

#include "CurvesCM.h"
#include "CurvesCM_Shape.h"
#include "CurvesCM_Circle.h"
#include "CurvesCM_Ellipse.h"
#include "CurvesCM_Helix.h"
#include "CurvesCM_ShapeGenerator.h"

using std::cout;
using std::endl;

using std::vector;

using std::type_info;

using std::shared_ptr;
using std::dynamic_pointer_cast;

std::random_device Shape_generator::aRandDev;

vector<PShape> aCurveMaker::ProcessShapeGeneration()
{
	int mySize = 0;
	std::cout << "Enter quantity of shapes: ";
	std::cin >> mySize;

	if(mySize<=0)
	{
		std::cout << "Error: incorrect quantity (your number <= 0)";
	}

	vector<PShape> aVShapes;
	Shape_generator aSG;
	aSG.SetRange(-1*mySize, mySize);

//-----------------------------------------------------
#pragma omp parallel for
	for (int i = 0; i < mySize; ++i)
		aVShapes.emplace_back(aSG.MakeRandomShape());
//-----------------------------------------------------

	return aVShapes;
}

void aCurveMaker::Perform()
{
	//Создание и вывод данных о фигурах
	vector<PShape> aVShapes = ProcessShapeGeneration();
	ShapesOutput(aVShapes);

	//Подготовка к сортировке
	using PCircle = shared_ptr<Circle>;
	vector<PCircle> aVCircles;
	aRadSum = 0.;

	//-----------------------------------------------------
#pragma omp parallel for
	for (auto& aPS : aVShapes)
	{
		const type_info& aTypeInfo{typeid(*aPS)};												
		if (aTypeInfo.hash_code() == typeid(Circle).hash_code())
		{
			aVCircles.emplace_back(dynamic_pointer_cast<Circle>(aPS));
			aRadSum += aVCircles.back()->myRadius();
		}
	}
	//-----------------------------------------------------

	// Сортировка
	std::sort(aVCircles.begin(), aVCircles.end(), [](const auto& lh, const auto& rh)
	{
		return lh->myRadius() < rh->myRadius();
	});

	// Вывод
#pragma omp parallel for
	for (auto& aPCircles : aVCircles)
		cout << aPCircles->myRadius() << endl;
	cout << "sum = " << aRadSum << endl;
}

void aCurveMaker::ShapesOutput(vector<PShape> aVShapes)
{
#pragma omp parallel for
	for (auto& aPS : aVShapes)
	{
		const type_info& aTypeInfo{ typeid(*aPS) };
		cout << aTypeInfo.name() << '	' << aPS->myPointOnCurve(pi / 4) << '	' << aPS->myCurveVector(pi / 4) << endl;
	}
}