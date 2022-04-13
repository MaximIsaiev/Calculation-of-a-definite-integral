#pragma once
#include "MyCalc.h"

// CMyGraph

class CMyGraph : public CStatic
{
	DECLARE_DYNAMIC(CMyGraph)

public:
	CMyGraph();
	virtual ~CMyGraph();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();

	// function variables
	int x = 0, x1 = 0;
	int i = 0, i2 = 0;
	int m_tmp = 0;
	int m_aPaint = 0;
	int m_bPaint = 0;

	// function variables
	double m_Centre = 0;
	double y = 0, y1 = 0;

	// logical variable
	bool m_Start = false;
	bool m_Clear = false;
	bool m_Axis = false;

	// class variable
	CMyCalc m_Result;

	// pen and brush
	CPen MainPen, AxisPen, InvisPen, ThinPen,RedPen;
	CBrush WhiteBrush;
	
};


