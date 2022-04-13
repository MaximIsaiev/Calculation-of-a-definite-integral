// MyGraph.cpp: файл реализации
//

#include "stdafx.h"
#include "CourseWork.h"
#include "MyGraph.h"


// CMyGraph

IMPLEMENT_DYNAMIC(CMyGraph, CStatic)

CMyGraph::CMyGraph()
{

}

CMyGraph::~CMyGraph()
{
}


BEGIN_MESSAGE_MAP(CMyGraph, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// обработчики сообщений CMyGraph




void CMyGraph::OnPaint()
{
	// device context for painting
	CPaintDC dc(this);
	CRect rc;
	GetClientRect(&rc);
	CRgn rgn;
	rgn.CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);
	dc.SelectClipRgn(&rgn);

	if (m_Start)
	{
		// reset variables
		x = 0;
		x1 = 0;
		y = 0;
		y1 = 0;
		i = 0;
		i2 = 0;
		m_Result.x = 0;
		m_Result.x2 = 0;
		m_Result.j = 0;
		m_Result.j2 = 0;
		m_Result.i = 0;
		m_Start = false;
		/// 
	}
	if (m_Clear)
	{
		// clearing the window and the construction of the axes
		dc.Rectangle(rc.left, rc.top, rc.right, rc.bottom);
		dc.SelectObject(AxisPen);
		dc.MoveTo(rc.left, m_Centre);
		dc.LineTo(rc.right, m_Centre);
		dc.SelectObject(ThinPen);
		dc.MoveTo(100, rc.top);
		dc.LineTo(100, rc.bottom);
		dc.MoveTo(200, rc.top);
		dc.LineTo(200, rc.bottom);
		dc.MoveTo(300, rc.top);
		dc.LineTo(300, rc.bottom);
		dc.MoveTo(400, rc.top);
		dc.LineTo(400, rc.bottom);
		dc.MoveTo(500, rc.top);
		dc.LineTo(500, rc.bottom);
		dc.MoveTo(600, rc.top);
		dc.LineTo(600, rc.bottom);
		dc.SelectObject(InvisPen);
		m_Clear = false;
		/// 
	}
	// sending data to the calculation class
	m_Result.i = m_tmp;
	m_Result.m_aCalc = m_aPaint;
	m_Result.m_bCalc = m_bPaint;
	m_Result.CalcFunction();
	m_Result.CalcDependence();
	///
	m_Centre = (rc.bottom - rc.top) / 2;
	if (m_Axis)
	{
		// clearing the window and the construction of the axes
		dc.Rectangle(rc.left, rc.top, rc.right, rc.bottom);
		dc.SelectObject(AxisPen);
		dc.MoveTo(rc.left, m_Centre);
		dc.LineTo(rc.right, m_Centre);
		dc.SelectObject(ThinPen);
		dc.MoveTo(100, rc.top);
		dc.LineTo(100, rc.bottom);
		dc.MoveTo(200, rc.top);
		dc.LineTo(200, rc.bottom);
		dc.MoveTo(300, rc.top);
		dc.LineTo(300, rc.bottom);
		dc.MoveTo(400, rc.top);
		dc.LineTo(400, rc.bottom);
		dc.MoveTo(500, rc.top);
		dc.LineTo(500, rc.bottom);
		dc.MoveTo(600, rc.top);
		dc.LineTo(600, rc.bottom);
		dc.SelectObject(InvisPen);
		m_Axis = false;
		///
	}
	if (i < m_Result.i)
	{ 
		// plotting a function
		dc.SelectObject(MainPen);
		if (i == 0)
		{
			dc.SelectObject(InvisPen);
		}
		dc.MoveTo(x, y + m_Centre);
		y = m_Result.m_Point[i];
		x += 1;
		dc.LineTo(x, y + m_Centre);
		i++;
		///
	}	
	if (i2 < m_Result.i)
	{
		// building the dependence of the integral on the parameter
		dc.SelectObject(RedPen);
		if (i2 == 0)
		{
			dc.SelectObject(InvisPen);
		}
		dc.MoveTo(x1, y1 + m_Centre);
		y1 = m_Result.m_Point_Int[i2] ;
		x1 += 3;
		dc.LineTo(x1, y1 + m_Centre);
		i2++;
		///
	}

	// TODO: добавьте свой код обработчика сообщений
	// Не вызывать CStatic::OnPaint() для сообщений рисования
}
