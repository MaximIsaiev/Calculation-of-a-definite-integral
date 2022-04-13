#pragma once
#include <vector>
class CMyCalc
{
public:
	CMyCalc();
	~CMyCalc();
// functions:
	void CalcFunction();
	void CalcDependence();
	double CalcIntegral(double a, double b, int n);
	double InFunction(double x, double a);
// variables:
	int i = 0;
	int j = 0, j2 = 0;
	int m_aCalc = 0;
	int m_bCalc = 0;
	double x = 0, x2 = 0;
// arrays of points
	std::vector<double> m_Point;
	std::vector<double> m_Point_Int;
	
	
};

