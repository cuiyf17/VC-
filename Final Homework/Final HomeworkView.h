
// Final HomeworkView.h: CFinalHomeworkView 类的接口
//

#pragma once


class CFinalHomeworkView : public CView
{
protected: // 仅从序列化创建
	CFinalHomeworkView() noexcept;
	DECLARE_DYNCREATE(CFinalHomeworkView)

// 特性
public:
	CFinalHomeworkDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CFinalHomeworkView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenuString();
	afx_msg void OnMenuFont1();
	afx_msg void OnMenuFont2();
	afx_msg void OnMenuFont3();
	afx_msg void OnButtonJiacu();
	afx_msg void OnButtonXieti();
	afx_msg void OnFontRed();
	afx_msg void OnFontGreen();
	afx_msg void OnFontBlue();
	afx_msg void OnHelp();
};

#ifndef _DEBUG  // Final HomeworkView.cpp 中的调试版本
inline CFinalHomeworkDoc* CFinalHomeworkView::GetDocument() const
   { return reinterpret_cast<CFinalHomeworkDoc*>(m_pDocument); }
#endif

