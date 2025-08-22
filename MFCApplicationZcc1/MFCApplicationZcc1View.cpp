
// MFCApplicationZcc1View.cpp: CMFCApplicationZcc1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplicationZcc1.h"
#endif

#include "MFCApplicationZcc1Doc.h"
#include "MFCApplicationZcc1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationZcc1View

IMPLEMENT_DYNCREATE(CMFCApplicationZcc1View, CListView)

BEGIN_MESSAGE_MAP(CMFCApplicationZcc1View, CListView)
	ON_WM_STYLECHANGED()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplicationZcc1View 构造/析构

CMFCApplicationZcc1View::CMFCApplicationZcc1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplicationZcc1View::~CMFCApplicationZcc1View()
{
}

BOOL CMFCApplicationZcc1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CListView::PreCreateWindow(cs);
}

void CMFCApplicationZcc1View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: 调用 GetListCtrl() 直接访问 ListView 的列表控件，
	//  从而可以用项填充 ListView。
}

void CMFCApplicationZcc1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplicationZcc1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplicationZcc1View 诊断

#ifdef _DEBUG
void CMFCApplicationZcc1View::AssertValid() const
{
	CListView::AssertValid();
}

void CMFCApplicationZcc1View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CMFCApplicationZcc1Doc* CMFCApplicationZcc1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationZcc1Doc)));
	return (CMFCApplicationZcc1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationZcc1View 消息处理程序
void CMFCApplicationZcc1View::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: 添加代码以响应用户对窗口视图样式的更改
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);
}
