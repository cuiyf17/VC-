#pragma once


// CDialogString 对话框

class CDialogString : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogString)

public:
	CDialogString(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogString();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_STRING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit StringEdit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
