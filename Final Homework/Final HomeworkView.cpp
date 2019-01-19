
// Final HomeworkView.cpp: CFinalHomeworkView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Final Homework.h"
#endif

#include "Final HomeworkDoc.h"
#include "Final HomeworkView.h"
#include "CDialogString.h"
#include "CDIALOGACTIVEX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static int xieti=0, jiacu=1,red=0,green=0,blue=0;
CString FONT=L"黑体";
// CFinalHomeworkView

IMPLEMENT_DYNCREATE(CFinalHomeworkView, CView)

BEGIN_MESSAGE_MAP(CFinalHomeworkView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFinalHomeworkView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_MENU_STRING, &CFinalHomeworkView::OnMenuString)
	ON_COMMAND(ID_MENU_FONT1, &CFinalHomeworkView::OnMenuFont1)
	ON_COMMAND(ID_MENU_FONT2, &CFinalHomeworkView::OnMenuFont2)
	ON_COMMAND(ID_MENU_FONT3, &CFinalHomeworkView::OnMenuFont3)
	ON_COMMAND(ID_BUTTON_jiacu, &CFinalHomeworkView::OnButtonJiacu)
	ON_COMMAND(ID_BUTTON_xieti, &CFinalHomeworkView::OnButtonXieti)
	ON_COMMAND(ID_FONT_RED, &CFinalHomeworkView::OnFontRed)
	ON_COMMAND(ID_FONT_GREEN, &CFinalHomeworkView::OnFontGreen)
	ON_COMMAND(ID__FONT_BLUE, &CFinalHomeworkView::OnFontBlue)
	ON_COMMAND(ID_HELP, &CFinalHomeworkView::OnHelp)
END_MESSAGE_MAP()

// CFinalHomeworkView 构造/析构

CFinalHomeworkView::CFinalHomeworkView() noexcept
{
	// TODO: 在此处添加构造代码

}

CFinalHomeworkView::~CFinalHomeworkView()
{
}

BOOL CFinalHomeworkView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFinalHomeworkView 绘图

void CFinalHomeworkView::OnDraw(CDC* pDC)//刷新函数，用来及时刷新字符串
{
	CFinalHomeworkDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDoc->m_str = theApp.mainstring;
	CRect rectClient;
	GetClientRect(rectClient);	// 获取当前客户区的指针
	CSize sizeClient = rectClient.Size();	// 获取当前客户区的大小
	CSize sizeTextExtent = pDC->GetTextExtent(pDoc->m_str);
	// 用新选定的字体绘制字符串
	CFont font;
	font.CreateFont(
		25,						//字体的高度
		0,						//由系统根据高宽比选取字体最佳宽度值
		0,						//文本的倾斜度为0，表示水平 
		0,						//字体与基线的倾斜度为0， 表示与基线平行
		jiacu,						//字体的粗度，FW_HEAVY为最粗
		xieti,						//非斜体字
		0,						//无下划线
		0,						//无删除线
		GB2312_CHARSET,			//表示所用的字符集为GB2312_CHARSET
		OUT_DEFAULT_PRECIS,		//输出精度为默认精度
		CLIP_DEFAULT_PRECIS,	//剪裁精度为默认精度
		DEFAULT_QUALITY,		//输出质量为默认值
		DEFAULT_PITCH | FF_DONTCARE,	//字间距和字体系列使用默认值
		FONT					//字体名称
	);
	pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(red,green,blue));
	pDC->TextOut((sizeClient.cx - sizeTextExtent.cx) / 2,
		(sizeClient.cy - sizeTextExtent.cy) / 2, pDoc->m_str);
	font.DeleteObject();
}


// CFinalHomeworkView 打印


void CFinalHomeworkView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFinalHomeworkView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFinalHomeworkView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFinalHomeworkView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CFinalHomeworkView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFinalHomeworkView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFinalHomeworkView 诊断

#ifdef _DEBUG
void CFinalHomeworkView::AssertValid() const
{
	CView::AssertValid();
}

void CFinalHomeworkView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFinalHomeworkDoc* CFinalHomeworkView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFinalHomeworkDoc)));
	return (CFinalHomeworkDoc*)m_pDocument;
}
#endif //_DEBUG


// CFinalHomeworkView 消息处理程序


void CFinalHomeworkView::OnMenuString()//点击输入字符串菜单弹出相应对话框
{
	// TODO: 在此添加命令处理程序代码
	CDialogString DialogString;
	DialogString.DoModal();
	Invalidate();
}


void CFinalHomeworkView::OnMenuFont1()//切换楷体
{
	// TODO: 在此添加命令处理程序代码	
	FONT = L"楷体";
	Invalidate();
}


void CFinalHomeworkView::OnMenuFont2()//切换宋体
{
	// TODO: 在此添加命令处理程序代码
	FONT = L"宋体";
	Invalidate();
}


void CFinalHomeworkView::OnMenuFont3()//切换仿宋体
{
	// TODO: 在此添加命令处理程序代码
	FONT = L"仿宋";
	Invalidate();
}


void CFinalHomeworkView::OnButtonJiacu()//加粗按钮的响应
{
	// TODO: 在此添加命令处理程序代码
	if (jiacu == 1)
		jiacu = 1000;
	else if (jiacu == 1000)
		jiacu = 1;
	Invalidate();
}


void CFinalHomeworkView::OnButtonXieti()//斜体按钮的响应
{
	// TODO: 在此添加命令处理程序代码
	if (xieti == 1)
		xieti = 0;
	else if (xieti == 0)
		xieti = 1;
	Invalidate();
}


void CFinalHomeworkView::OnFontRed()//红色字体颜色的响应
{
	// TODO: 在此添加命令处理程序代码
	red = 255;
	green = 0;
	blue = 0;
	Invalidate();
}


void CFinalHomeworkView::OnFontGreen()//绿色字体颜色的响应
{
	// TODO: 在此添加命令处理程序代码
	red = 0;
	green = 255;
	blue = 0;
	Invalidate();
}


void CFinalHomeworkView::OnFontBlue()//蓝色字体颜色的响应
{
	// TODO: 在此添加命令处理程序代码
	red = 0;
	green = 0;
	blue = 255;
	Invalidate();
}


void CFinalHomeworkView::OnHelp()//操作演示按钮的响应
{
	// TODO: 在此添加命令处理程序代码
	CDIALOGACTIVEX DialogString;
	DialogString.DoModal();
	Invalidate();
}
