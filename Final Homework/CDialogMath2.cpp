// CDialogMath2.cpp: 实现文件
//

#include "stdafx.h"
#include "Final Homework.h"
#include "CDialogMath2.h"
#include "afxdialogex.h"
#include "math.h"


// CDialogMath2 对话框

IMPLEMENT_DYNAMIC(CDialogMath2, CDialogEx)

CDialogMath2::CDialogMath2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MATH2, pParent)
{

}

CDialogMath2::~CDialogMath2()
{
}

void CDialogMath2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogMath2, CDialogEx)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CDialogMath2 消息处理程序


BOOL CDialogMath2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString strText1;//存储角度值的变量
	CSliderCtrl* pSlide1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER);//指向滑杆控件的指针
	//设定滑杆控件的范围和初始值
	pSlide1->SetRange(0, 360);
	pSlide1->SetPos(0);
	//角度值和滑杆位置绑定
	strText1.Format(L"%d", pSlide1->GetPos());
	//角度值编辑框内容的初始化
	SetDlgItemText(IDC_EDIT_MATH2_NUMBER1, strText1);
	Math2Calculate(pSlide1->GetPos());
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogMath2::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)//当滑杆滑动时响应的函数
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (pScrollBar->GetDlgCtrlID() == IDC_SLIDER)
	{
		CSliderCtrl* pSlide = (CSliderCtrl*)pScrollBar;
		CString strText;
		strText.Format(L"%d", pSlide->GetPos());
		SetDlgItemText(IDC_EDIT_MATH2_NUMBER1, strText);
		Math2Calculate(pSlide->GetPos());
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


int CDialogMath2::Math2Calculate(int a)//这是一个封装好的计算Sin函数值的函数
{
	// TODO: 在此处添加实现代码.
	double b;
	if (a == 360 || a == 180)//因为在360°和180°的时候，由于double类型的变量会出小bug，结果不显示为0，而是10的负12次方量级的小数字，故对这两个值特殊对待
	{
		b = 0;
	}
	else
	{
		b = sin(a*3.14159265358 / 180);
	}
	CString strText;
	strText.Format(L"%g", b);
	SetDlgItemText(IDC_EDIT_MATH2_NUMBER2, strText);
	return 0;
}
