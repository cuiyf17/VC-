
// Final Homework.h: Final Homework 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CFinalHomeworkApp:
// 有关此类的实现，请参阅 Final Homework.cpp
//

class CFinalHomeworkApp : public CWinAppEx
{
public:
	CFinalHomeworkApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	CString mainstring =L"欢迎来到崔晏菲的大作业";
// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMenuMath1();
	afx_msg void OnMenuMath2();
	afx_msg void OnMenuMath3();
	afx_msg void OnMenuString();
};
extern CFinalHomeworkApp theApp;
