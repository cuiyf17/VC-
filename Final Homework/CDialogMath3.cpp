// CDialogMath3.cpp: 实现文件
//

#include "stdafx.h"
#include "Final Homework.h"
#include "CDialogMath3.h"
#include "afxdialogex.h"

static int dad=0;

// CDialogMath3 对话框

IMPLEMENT_DYNAMIC(CDialogMath3, CDialogEx)

CDialogMath3::CDialogMath3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MATH3, pParent)
{
}

CDialogMath3::~CDialogMath3()
{
}

void CDialogMath3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MATH3_COMBO, Math3Combo);
	DDX_Control(pDX, IDC_EDIT1, Math3Number2);
	DDX_Control(pDX, IDC_COMBO2, Math3Combo2);
	DDX_Control(pDX, IDC_MATH3_SCROLLBAR1, Math3ScrollBar1);
	DDX_Control(pDX, IDC_MATH3_SCROLLBAR2, Math3ScrollBar2);
	DDX_Control(pDX, IDC_MATH3_SCROLLBAR3, Math3ScrollBar3);
}


BEGIN_MESSAGE_MAP(CDialogMath3, CDialogEx)
	ON_CBN_SELCHANGE(IDC_MATH3_COMBO, &CDialogMath3::OnCbnSelchangeMath3Combo)
	ON_BN_CLICKED(IDC_MATH3_BUTTON, &CDialogMath3::OnBnClickedMath3Button)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CDialogMath3::OnCbnSelchangeCombo2)
	ON_WM_VSCROLL()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDOK, &CDialogMath3::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDialogMath3::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDialogMath3 消息处理程序


BOOL CDialogMath3::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	//初始化角度值的组合框
	Math3Combo.AddString(L"0");
	Math3Combo.AddString(L"30");
	Math3Combo.AddString(L"60");
	Math3Combo.AddString(L"90");
	Math3Combo.AddString(L"120");
	Math3Combo.AddString(L"150");
	Math3Combo.AddString(L"180");
	Math3Combo.AddString(L"210");
	Math3Combo.AddString(L"240");
	Math3Combo.AddString(L"270");
	Math3Combo.AddString(L"300");
	Math3Combo.AddString(L"330");
	Math3Combo.AddString(L"360");
	//初始化选择线条模式的组合框
	Math3Combo2.AddString(L"直线");
	Math3Combo2.AddString(L"虚线");
	Math3Combo2.AddString(L"点画线");
	Math3Combo2.SetCurSel(0);//线条模式默认选择直线
	//初始化颜色控制滚动条
	Math3ScrollBar1.SetScrollRange(0, 255);
	Math3ScrollBar1.SetScrollPos(0);
	Math3ScrollBar2.SetScrollRange(0, 255);
	Math3ScrollBar2.SetScrollPos(0);
	Math3ScrollBar3.SetScrollRange(0, 255);
	Math3ScrollBar3.SetScrollPos(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogMath3::OnCbnSelchangeMath3Combo()//当角度值的组合框被选动时响应的函数，用来在另一个编辑框显示计算结果
{
	// TODO: 在此添加控件通知处理程序代码
	CString msg;//msg变量存储角度值
	Math3Combo.GetLBText(Math3Combo.GetCurSel(), msg);
	int i = _ttoi(msg);
	double n;
	n = cos(i*3.14159265358/180);
	msg.Format(L"%lf", n);
	Math3Number2.SetSel(0, -1);
	Math3Number2.ReplaceSel(msg);
}

void CDialogMath3::OnBnClickedMath3Button()//绘图功能的开关按钮
{
	// TODO: 在此添加控件通知处理程序代码
	if (dad == 0)
	{
		dad = 1;
		GetDlgItem(IDC_MATH3_BUTTON)->SetWindowText(L"取消绘图");
	}
	else
	{
		dad = 0;
		GetDlgItem(IDC_MATH3_BUTTON)->SetWindowText(L"绘图");
	}
	DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
	
}


int CDialogMath3::DrawCos(int a,int b, int c)//这是一个封装好的Cos画图函数，三个参量是RGB函数的三个参量
{
	// TODO: 在此处添加实现代码.
	HDC hdc;
	hdc = ::GetDC(m_hWnd); //HDC方式创建
	int i = 0, flag = 1;
	CString msg;
	HPEN hpen;
	HBRUSH hbrush;
	CPoint point[361];
	for (i = 0;i <= 360; i++)
	{
		point[i].x = 50 + i;
		point[i].y = 250 - 100 * cos(i*3.14159265358 / 180);
	}
	Math3Combo2.GetLBText(Math3Combo2.GetCurSel(), msg);
	if (!msg.CompareNoCase(L"0"))
	{
		flag = PS_SOLID;
	}
	else if (!msg.CompareNoCase(L"直线"))
	{
		flag = PS_SOLID;
	}
	else if (!msg.CompareNoCase(L"虚线"))
	{
		flag = PS_DASH;
	}
	else if (!msg.CompareNoCase(L"点画线"))
	{
		flag = PS_DOT;
	}
	if (dad == 1)
	{
		hbrush = CreateSolidBrush(RGB(255, 255, 255));
		hpen = CreatePen(flag, 1, RGB(a, b, c));
		SelectObject(hdc, hbrush);
		Rectangle(hdc, 45, 140, 415, 360);
		SelectObject(hdc, hpen);
		Polyline(hdc, point, 361);
		::ReleaseDC(m_hWnd, hdc);    //释放dc
	}
	else
	{
		hbrush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, hbrush);
		Rectangle(hdc, 45, 140, 415, 360);
		::ReleaseDC(m_hWnd, hdc);    //释放dc
	}
	return 0;
}


void CDialogMath3::OnCbnSelchangeCombo2()//当选择划线模式的时候响应的函数
{
	// TODO: 在此添加控件通知处理程序代码
	DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
}


void CDialogMath3::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)//当三个滑块滑动的时候响应的函数
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int iNowPos;
	switch (nSBCode)
	{
	case SB_THUMBTRACK://拖动滚动滑块时
		if (pScrollBar == &Math3ScrollBar1)
		{
			Math3ScrollBar1.SetScrollPos(nPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		else if (pScrollBar == &Math3ScrollBar2)
		{
			Math3ScrollBar2.SetScrollPos(nPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		else if (pScrollBar == &Math3ScrollBar3)
		{
			Math3ScrollBar3.SetScrollPos(nPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		break;
	case SB_LINEDOWN://单击滚动条向下的箭头
		if (pScrollBar == &Math3ScrollBar1)
		{
			iNowPos = Math3ScrollBar1.GetScrollPos();
			iNowPos = iNowPos + 1;
			if (iNowPos > 255)
				iNowPos = 255;
			Math3ScrollBar1.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		else if (pScrollBar == &Math3ScrollBar2)
		{
			iNowPos = Math3ScrollBar2.GetScrollPos();
			iNowPos = iNowPos + 1;
			if (iNowPos > 255)
				iNowPos = 255;
			Math3ScrollBar2.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		else 	if (pScrollBar == &Math3ScrollBar3)
		{
			iNowPos = Math3ScrollBar3.GetScrollPos();
			iNowPos = iNowPos + 1;
			if (iNowPos > 255)
				iNowPos = 255;
			Math3ScrollBar3.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		break;
	case SB_LINEUP:	//单击滚动条向上的箭头
		if (pScrollBar == &Math3ScrollBar1)
		{
			iNowPos = Math3ScrollBar1.GetScrollPos();
			iNowPos = iNowPos - 1;
			if (iNowPos < 0)
				iNowPos = 0;
			Math3ScrollBar1.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		else if (pScrollBar == &Math3ScrollBar2)
		{
			iNowPos = Math3ScrollBar2.GetScrollPos();
			iNowPos = iNowPos - 1;
			if (iNowPos < 0)
				iNowPos = 0;
			Math3ScrollBar2.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		else if (pScrollBar == &Math3ScrollBar3)
		{
			iNowPos = Math3ScrollBar3.GetScrollPos();
			iNowPos = iNowPos - 1;
			if (iNowPos < 0)
				iNowPos = 0;
			Math3ScrollBar3.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		break;
	case SB_PAGEDOWN://单击滚动条下面的箭头与滚动块之间区域
		if (pScrollBar == &Math3ScrollBar1)
		{
			iNowPos = Math3ScrollBar1.GetScrollPos();
			iNowPos = iNowPos + 1;
			if (iNowPos > 255)
				iNowPos = 255;
			Math3ScrollBar1.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		else if (pScrollBar == &Math3ScrollBar2)
		{
			iNowPos = Math3ScrollBar2.GetScrollPos();
			iNowPos = iNowPos + 1;
			if (iNowPos > 255)
				iNowPos = 255;
			Math3ScrollBar2.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		else 	if (pScrollBar == &Math3ScrollBar3)
		{
			iNowPos = Math3ScrollBar3.GetScrollPos();
			iNowPos = iNowPos + 1;
			if (iNowPos > 255)
				iNowPos = 255;
			Math3ScrollBar3.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		break;
	case SB_PAGEUP://单击滚动条上面的箭头与滚动块之间的区域
		if (pScrollBar == &Math3ScrollBar1)
		{
			iNowPos = Math3ScrollBar1.GetScrollPos();
			iNowPos = iNowPos - 1;
			if (iNowPos < 0)
				iNowPos = 0;
			Math3ScrollBar1.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		else if (pScrollBar == &Math3ScrollBar2)
		{
			iNowPos = Math3ScrollBar2.GetScrollPos();
			iNowPos = iNowPos - 1;
			if (iNowPos < 0)
				iNowPos = 0;
			Math3ScrollBar2.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		else if (pScrollBar == &Math3ScrollBar3)
		{
			iNowPos = Math3ScrollBar3.GetScrollPos();
			iNowPos = iNowPos - 1;
			if (iNowPos < 0)
				iNowPos = 0;
			Math3ScrollBar3.SetScrollPos(iNowPos);
			DrawCos(Math3ScrollBar1.GetScrollPos(), Math3ScrollBar2.GetScrollPos(), Math3ScrollBar3.GetScrollPos());
		}
		break;
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


int CDialogMath3::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	return 0;
}


void CDialogMath3::OnBnClickedOk()//按住确定之后初始化绘图模式
{
	// TODO: 在此添加控件通知处理程序代码
	dad = 0;
	GetDlgItem(IDC_MATH3_BUTTON)->SetWindowText(L"绘图");
	CDialogEx::OnOK();
}


void CDialogMath3::OnBnClickedCancel()//按住取消之后初始化绘图模式
{
	// TODO: 在此添加控件通知处理程序代码
	dad = 0;
	GetDlgItem(IDC_MATH3_BUTTON)->SetWindowText(L"绘图");
	CDialogEx::OnCancel();
}
