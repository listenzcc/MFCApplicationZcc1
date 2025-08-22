
// MFCApplicationZcc1View.h: CMFCApplicationZcc1View 类的接口
//

#pragma once


class CMFCApplicationZcc1View : public CListView
{
protected: // 仅从序列化创建
	CMFCApplicationZcc1View() noexcept;
	DECLARE_DYNCREATE(CMFCApplicationZcc1View)

// 特性
public:
	CMFCApplicationZcc1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCApplicationZcc1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplicationZcc1View.cpp 中的调试版本
inline CMFCApplicationZcc1Doc* CMFCApplicationZcc1View::GetDocument() const
   { return reinterpret_cast<CMFCApplicationZcc1Doc*>(m_pDocument); }
#endif

