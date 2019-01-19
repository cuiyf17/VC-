#pragma once


// CDialogMath3 对话框

class CDialogMath3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogMath3)

public:
	CDialogMath3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogMath3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MATH3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox Math3Combo;
	afx_msg void OnCbnSelchangeMath3Combo();
	CEdit Math3Number2;
	CComboBox Math3Combo2;
	afx_msg void OnBnClickedMath3Button();
	int DrawCos(int a,int b,int c);
	afx_msg void OnCbnSelchangeCombo2();
	CScrollBar Math3ScrollBar1;
	CScrollBar Math3ScrollBar2;
	CScrollBar Math3ScrollBar3;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
