#pragma once
#include "CWMPPlayer4.h"
#include "CWMPPlayer40.h"

// CDIALOGACTIVEX 对话框

class CDIALOGACTIVEX : public CDialogEx
{
	DECLARE_DYNAMIC(CDIALOGACTIVEX)

public:
	CDIALOGACTIVEX(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDIALOGACTIVEX();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ACTIVEX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CWMPPlayer4 MediaPlayer1;
	DECLARE_EVENTSINK_MAP()
	void DoubleClickOcx1(short nButton, short nShiftState, long fX, long fY);
};
