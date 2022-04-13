
// CourseWorkDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "CourseWork.h"
#include "CourseWorkDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define IDC_TIMER 9181

#include <initguid.h>
DEFINE_GUID(ImageFormatBMP, 0xb96b3cab, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatEMF, 0xb96b3cac, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatWMF, 0xb96b3cad, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatJPEG, 0xb96b3cae, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatPNG, 0xb96b3caf, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatGIF, 0xb96b3cb0, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatTIFF, 0xb96b3cb1, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CCourseWorkDlg



CCourseWorkDlg::CCourseWorkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COURSEWORK_DIALOG, pParent)
	
	, m_Count(0)
	, m_a(0)
	, m_b(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CCourseWorkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, m_Count);
	DDX_Text(pDX, IDC_EDIT2, m_a);
	DDX_Text(pDX, IDC_EDIT3, m_b);
}

BEGIN_MESSAGE_MAP(CCourseWorkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CCourseWorkDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCourseWorkDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCourseWorkDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, &CCourseWorkDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON4, &CCourseWorkDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCourseWorkDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// ����������� ��������� CCourseWorkDlg

BOOL CCourseWorkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������
	m_Paint.SubclassDlgItem(IDC_STATIC_GRAPH,this);
	// Pen and brush consciousness
	m_Paint.MainPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	m_Paint.AxisPen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	m_Paint.InvisPen.CreatePen(PS_NULL, 1, RGB(255, 255, 255));
	m_Paint.ThinPen.CreatePen(PS_SOLID, 1, RGB(180, 180, 180));
	m_Paint.RedPen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	m_Paint.WhiteBrush.CreateSolidBrush(NULL_BRUSH);
	// Axis drawing
	m_Paint.m_Axis = true;
	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CCourseWorkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CCourseWorkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CCourseWorkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCourseWorkDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	// Redrawing the function graph window
	m_Paint.Invalidate();
	
	CDialogEx::OnTimer(nIDEvent);
}


void CCourseWorkDlg::OnBnClickedButton1()
{
	// Reading variables
	UpdateData(TRUE);
	m_Paint.m_Start = true;
	m_Paint.m_tmp = m_Count;
	m_Paint.m_aPaint = m_a;
	m_Paint.m_bPaint = m_b;
	// Start timer
	SetTimer(9181, 1, NULL);
	// TODO: �������� ���� ��� ����������� �����������
}


void CCourseWorkDlg::OnBnClickedButton2()
{
	// Clear the graph window
	m_Paint.m_Clear = true;

	// TODO: �������� ���� ��� ����������� �����������
}


void CCourseWorkDlg::OnBnClickedButton3()
{
	CWnd *pWn = GetDlgItem(IDC_STATIC_GRAPH);
	if (!pWn)
		return;
	CWindowDC winDC(pWn);
	CRect rc;
	pWn->GetClientRect(&rc);
	CDC memDC;
	memDC.CreateCompatibleDC(&winDC);
	CBitmap bitMap;
	bitMap.CreateCompatibleBitmap(&winDC, rc.Width(), rc.Height());
	HGDIOBJ pOld = memDC.SelectObject(&bitMap);
	memDC.FillSolidRect(&rc, RGB(0, 255, 0));
	memDC.BitBlt(0, 0, rc.Width(), rc.Height(), &winDC, 0, 0, NOTSRCCOPY);
	memDC.SelectObject(pOld);

	static TCHAR szFilter[] = _T("BMP Files (*.bmp)|*.bmp|")
		_T("PNG Files (*.png)|*.png|GIF Files (*.gif)|*.gif|")
		_T("JPG Files (*.jpg)|*.jpg|All Files (*.*)|*.*||");
	CFileDialog dlg(FALSE, _T(".bmp"), NULL, 6UL, szFilter);
	if (IDOK == dlg.DoModal())
	{
		CImage image;
		image.Attach(HBITMAP(bitMap));
		CString strFull = dlg.GetOFN().lpstrFile;
		HRESULT hr;
		if (-1 != strFull.Find(_T(".png")))
			hr = image.Save(strFull, ImageFormatPNG);
		else if (-1 != strFull.Find(_T(".jpg")))
			hr = image.Save(strFull, ImageFormatJPEG);
		else if (-1 != strFull.Find(_T(".gif")))
			hr = image.Save(strFull, ImageFormatGIF);
		else if (-1 != strFull.Find(_T(".bmp")))
			hr = image.Save(strFull, ImageFormatBMP);
		else
		{
			strFull += _T(".bmp");
			hr = image.Save(strFull, ImageFormatBMP);
		}

		if (FAILED(hr))
		{
			CString strErr;
			strErr.Format(L" Couldn't Save File: %s, %x ", (LPCTSTR)strFull, hr);
			AfxMessageBox(strErr, MB_OK | MB_ICONERROR);
		}
	}
	// TODO: �������� ���� ��� ����������� �����������
}


void CCourseWorkDlg::OnBnClickedOk()
{
	// TODO: �������� ���� ��� ����������� �����������
	CDialogEx::OnOK();
}


void CCourseWorkDlg::OnBnClickedButton4()
{
	MessageBox(L"���������� ��������� ���������� ������� ������� y(x) = 100*sin (0.01*x+b) +a � ������� ����������� ��������� ���� ������� �� ���������� a � b.\n���������� �������� � �� Windows(7, 8, 8.1, 10)\n\n1.������� ��������� ������� � ���� ����� �� = � � �b = �.����� ������� ����������� �� ��� � � ��������������� ���� �����\n2.������� ������ ����������� � ��������� ��������� ��������� �������\n3.���� ����� ���������� ��� ���� ������, �������� ��������� ������� � ������� ������ �����������\n4.���� ��� ����� ��������� �����������, ������� ��������������� ������\n5.��� ������� ���� ������� ������ ����������\n\n��������� �����������!", L"����������");
	// TODO: �������� ���� ��� ����������� �����������
}


void CCourseWorkDlg::OnBnClickedButton5()
{
	
	// TODO: �������� ���� ��� ����������� �����������
}
