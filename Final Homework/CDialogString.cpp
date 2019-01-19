// CDialogString.cpp: 实现文件
//

#include "stdafx.h"
#include "Final Homework.h"
#include "CDialogString.h"
#include "afxdialogex.h"


// CDialogString 对话框

IMPLEMENT_DYNAMIC(CDialogString, CDialogEx)

CDialogString::CDialogString(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_STRING, pParent)
{

}

CDialogString::~CDialogString()
{
}

void CDialogString::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_STRING, StringEdit);
}


BEGIN_MESSAGE_MAP(CDialogString, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialogString::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDialogString::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDialogString 消息处理程序


void CDialogString::OnBnClickedOk()//按住确定后把文字内容传递的函数，文字内容存储在变量theApp.mainstring中
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT_STRING)->GetWindowText(theApp.mainstring);
	CDialogEx::OnOK();
}


void CDialogString::OnBnClickedCancel()//点击取消则没有任何效果
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
