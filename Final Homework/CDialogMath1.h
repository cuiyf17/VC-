#pragma once


// CDialogMath1 对话框

class CDialogMath1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogMath1)

public:
	CDialogMath1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogMath1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MATH1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit Math1Number1;
	CScrollBar ScrollNumber1;
//	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	int ChangeDisplayInfo(int pos);
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedRadioPlus();
	afx_msg void OnBnClickedRadioMinus();
	afx_msg void OnBnClickedRadioTime();
	afx_msg void OnBnClickedRadioDivide();
	CEdit Math1Number3;
	int ChangeDisplayInfo2(double pos);
	int Math1Calculate();
};
