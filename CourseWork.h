
// CourseWork.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CCourseWorkApp:
// � ���������� ������� ������ ��. CourseWork.cpp
//

class CCourseWorkApp : public CWinApp
{
public:
	CCourseWorkApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CCourseWorkApp theApp;