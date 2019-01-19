// CDIALOGACTIVEX.cpp: 实现文件
//

#include "stdafx.h"
#include "Final Homework.h"
#include "CDIALOGACTIVEX.h"
#include "afxdialogex.h"
#include "CWMPPlayer4.h"


// CDIALOGACTIVEX 对话框

IMPLEMENT_DYNAMIC(CDIALOGACTIVEX, CDialogEx)

CDIALOGACTIVEX::CDIALOGACTIVEX(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ACTIVEX, pParent)
{

}

CDIALOGACTIVEX::~CDIALOGACTIVEX()
{
}

void CDIALOGACTIVEX::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OCX1, MediaPlayer1);
}


BEGIN_MESSAGE_MAP(CDIALOGACTIVEX, CDialogEx)
END_MESSAGE_MAP()


// CDIALOGACTIVEX 消息处理程序
BEGIN_EVENTSINK_MAP(CDIALOGACTIVEX, CDialogEx)
	ON_EVENT(CDIALOGACTIVEX, IDC_OCX1, 6506, CDIALOGACTIVEX::DoubleClickOcx1, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
END_EVENTSINK_MAP()


void CDIALOGACTIVEX::DoubleClickOcx1(short nButton, short nShiftState, long fX, long fY)//双击MediaPlayer控件选择播放路径里的文件
{
	// TODO: 在此处添加消息处理程序代码
	CFileDialog dlg(TRUE, NULL, L"*.*",
		OFN_FILEMUSTEXIST,
		L"ActiveStreamingFormat(*.asf)|*.asf|"
		L"AudioVideoInterleaveFormat(*.avi)|*.avi|"
		L"RealAudio/RealVideo(*.rm)|*.rm|"
		L"WaveAudio(*.wav)|*.wav|"
		L"MIDIFile(*.mid)|*.mid|"
		L"所有文件(*.*)|*.*||");
	if (dlg.DoModal() == IDOK)
	{
		MediaPlayer1.put_URL(dlg.GetPathName());
		// 传递媒体文件到播放器，并开始播放
	}

}
