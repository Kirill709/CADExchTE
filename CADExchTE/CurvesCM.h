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
	// �������, ���������� ����������� ������ �� �������� � ����������
	void Perform();
	// ��������� ��������� ����� ����� �� ���������� �����������
	std::vector<PShape> ProcessShapeGeneration();
	//����� ��������� �����
	void ShapesOutput(std::vector<PShape> aVShapes);
};