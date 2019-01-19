// CDialogMath1.cpp: 实现文件
//

#include "stdafx.h"
#include "Final Homework.h"
#include "CDialogMath1.h"
#include "afxdialogex.h"

static int flag=0;
double number1=0, number2=0,number3=0;


// CDialogMath1 对话框

IMPLEMENT_DYNAMIC(CDialogMath1, CDialogEx)

CDialogMath1::CDialogMath1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MATH1, pParent)
{
}

CDialogMath1::~CDialogMath1()
{
}

void CDialogMath1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NUMBER1, Math1Number1);
	DDX_Control(pDX, IDC_SCROLLBAR_NUMBER1, ScrollNumber1);
	DDX_Control(pDX, IDC_EDIT_NUMBER3, Math1Number3);
}


BEGIN_MESSAGE_MAP(CDialogMath1, CDialogEx)
//	ON_WM_ACTIVATE()
ON_WM_HSCROLL()
ON_WM_VSCROLL()
ON_BN_CLICKED(IDC_RADIO_PLUS, &CDialogMath1::OnBnClickedRadioPlus)
ON_BN_CLICKED(IDC_RADIO_MINUS, &CDialogMath1::OnBnClickedRadioMinus)
ON_BN_CLICKED(IDC_RADIO_TIME, &CDialogMath1::OnBnClickedRadioTime)
ON_BN_CLICKED(IDC_RADIO_DIVIDE, &CDialogMath1::OnBnClickedRadioDivide)
END_MESSAGE_MAP()


// CDialogMath1 消息处理程序


//void CDialogMath1::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
//{
//	CDialogEx::OnActivate(nState, pWndOther, bMinimized);
//
//	// TODO: 在此处添加消息处理程序代码
//}


int CDialogMath1::ChangeDisplayInfo(int pos)
{
	// TODO: 在此处添加实现代码.
	wchar_t sPos[10] = { 0 };
	swprintf_s(sPos,L"%g",(double)pos);
	Math1Number1.SetSel(0, -1);
	Math1Number1.ReplaceSel((LPCTSTR)sPos);
	UpdateData(FALSE);  //将与控件绑定的变量内容显示到屏幕上
	number1 = pos;
	return 0;
}


BOOL CDialogMath1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//数字1的滚动条
	ScrollNumber1.SetScrollRange(-25535, 25535);
	ScrollNumber1.SetScrollPos(0);
	ChangeDisplayInfo(ScrollNumber1.GetScrollPos());
	//数字2的spin控件
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_NUMBER2);
	pSpin->SetRange(-25535, 25535);
	pSpin->SetPos(0);
	pSpin->GetBuddy()->SetWindowText(L"0");
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogMath1::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)//拖动滚动条时响应的函数
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int iNowPos;
	switch (nSBCode)
	{
		if (pScrollBar == &ScrollNumber1)
		{
	case SB_THUMBTRACK://拖动滚动滑块时
		ScrollNumber1.SetScrollPos(nPos);
		ChangeDisplayInfo(ScrollNumber1.GetScrollPos());
		Math1Calculate();
		break;
	case SB_LINEDOWN://单击滚动条向下的箭头
		iNowPos = ScrollNumber1.GetScrollPos();
		iNowPos = iNowPos + 1;
		if (iNowPos > 20)
			iNowPos = 20;
		ScrollNumber1.SetScrollPos(iNowPos);
		ChangeDisplayInfo(ScrollNumber1.GetScrollPos());
		Math1Calculate();
		break;
	case SB_LINEUP:	//单击滚动条向上的箭头
		iNowPos = ScrollNumber1.GetScrollPos();
		iNowPos = iNowPos - 1;
		if (iNowPos < 0)
			iNowPos = 0;
		ScrollNumber1.SetScrollPos(iNowPos);
		ChangeDisplayInfo(ScrollNumber1.GetScrollPos());
		Math1Calculate();
		break;

	case SB_PAGEDOWN://单击滚动条下面的箭头与滚动块之间区域
		iNowPos = ScrollNumber1.GetScrollPos();
		iNowPos = iNowPos + 1;
		if (iNowPos > 20)
			iNowPos = 20;
		ScrollNumber1.SetScrollPos(iNowPos);
		ChangeDisplayInfo(ScrollNumber1.GetScrollPos());
		Math1Calculate();
		break;
	case SB_PAGEUP://单击滚动条上面的箭头与滚动块之间的区域
		iNowPos = ScrollNumber1.GetScrollPos();
		iNowPos = iNowPos - 1;
		if (iNowPos < 0)
			iNowPos = 0;
		ScrollNumber1.SetScrollPos(iNowPos);
		ChangeDisplayInfo(ScrollNumber1.GetScrollPos());
		Math1Calculate();
		break;
		}
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CDialogMath1::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)//点击spin控件时响应的函数
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (pScrollBar->GetDlgCtrlID() == IDC_SPIN_NUMBER2)
	{
		CString strValue; //定义一字符串对象存储编辑框中要显示的内容
		strValue.Format(L"%3d", (long)nPos);
		((CSpinButtonCtrl*)pScrollBar)->GetBuddy()->SetWindowText(strValue);
		number2 = (int)nPos;
		Math1Calculate();
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CDialogMath1::OnBnClickedRadioPlus()//单选按钮“加”
{
	// TODO: 在此添加控件通知处理程序代码
	flag = 1;
	Math1Calculate();
	UpdateData(FALSE);  //将与控件绑定的变量内容显示到屏幕上
}


void CDialogMath1::OnBnClickedRadioMinus()//单选按钮“减”
{
	// TODO: 在此添加控件通知处理程序代码
	flag = 2;
	Math1Calculate();
	UpdateData(FALSE);  //将与控件绑定的变量内容显示到屏幕上
}


void CDialogMath1::OnBnClickedRadioTime()//单选按钮“乘”
{
	// TODO: 在此添加控件通知处理程序代码
	flag = 3;
	Math1Calculate();
	UpdateData(FALSE);  //将与控件绑定的变量内容显示到屏幕上
}


void CDialogMath1::OnBnClickedRadioDivide()//单选按钮“除”
{
	// TODO: 在此添加控件通知处理程序代码
	flag = 4;
	Math1Calculate();
	UpdateData(FALSE);  //将与控件绑定的变量内容显示到屏幕上
}


int CDialogMath1::ChangeDisplayInfo2(double pos)//将加减乘除计算后的结果显示到编辑框里的函数
{
	// TODO: 在此处添加实现代码.
	wchar_t sPos[10] = { 0 };
	swprintf_s(sPos, L"%g", pos);
	Math1Number3.SetSel(0, -1);
	LPCTSTR p = (LPCTSTR)sPos;
	Math1Number3.ReplaceSel(p);
	UpdateData(FALSE);  //将与控件绑定的变量内容显示到屏幕上
	return 0;
}


 int CDialogMath1::Math1Calculate()//加减乘除计算函数
{
	// TODO: 在此处添加实现代码.
	 switch (flag)
	 {
	 case 1:
		 number3 = number1 + number2;
		 ChangeDisplayInfo2(number3);
		 break;
	 case 2:
		 number3 = number1 - number2;
		 ChangeDisplayInfo2(number3);
		 break;
	 case 3:
		 number3 = number1 * number2;
		 ChangeDisplayInfo2(number3);
		 break;
	 case 4:
		 if (number2 != 0)
		 {
			 number3 = number1 / number2;
			 ChangeDisplayInfo2(number3);
			 break;
		 }
		 else
		 {
			 AfxMessageBox(L"除数不能为0");//如果除数为0，则弹出提示框
			 break;
		 }
	 }
	return 0;
}
