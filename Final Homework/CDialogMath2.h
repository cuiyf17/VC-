#pragma once


// CDialogMath2 对话框

class CDialogMath2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogMath2)

public:
	CDialogMath2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogMath2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MATH2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int Math2Calculate(int a);
};
