#include "stdafx.h"
#include "MyCalc.h"
#include <vector>

using namespace std;

CMyCalc::CMyCalc()
{
}


CMyCalc::~CMyCalc()
{
}

// calculating points of the original function
void CMyCalc::CalcFunction()
{
	
	m_Point.resize(i);

	while(j < i)
	{
		x++;
		m_Point[j] = -100*sin(x/100+m_bCalc*3.1415)+m_aCalc;
		j++;
	}
	x = 0;
	j = 0;

}

// the method of rectangles
double CMyCalc::CalcIntegral(double a, double b, int n)
{
	double h = (b-a)/n;
	double result = 0;
	for (int i = 0; i < n;i++)
	{

		result += InFunction(a + h*(i + 0.5), a);

	}
	result *= h;
	return result;
}

// the original function
double CMyCalc::InFunction(double x, double a)
{
	return  100 * sin(x / 100 + m_bCalc*3.1415) + a;

}

// calculating the points of dependence of the integral on the parameter
void CMyCalc::CalcDependence()
{
	m_Point_Int.resize(i);
	for (int a = 0; a < i; a++)
	{
		m_Point_Int[a] = CalcIntegral(a, m_bCalc,100);
	}
}
