
// CourseWorkDlg.h : файл заголовка
//

#pragma once
#include "MyGraph.h"
#include "MyCalc.h"


// диалоговое окно CCourseWorkDlg
class CCourseWorkDlg : public CDialogEx
{
	// Создание
public:
	CCourseWorkDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COURSEWORK_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//functions
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();

	// class variable
	CMyGraph m_Paint;
	CMyCalc m_Calc;

	// function parameters
	int m_Count;
	int m_a;
	int m_b;
	
	
};
