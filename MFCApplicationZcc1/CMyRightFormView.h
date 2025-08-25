#pragma once
#include <afxext.h>


class CMyRightFormView :
    public CFormView
{
	DECLARE_DYNCREATE(CMyRightFormView)

public:
	CMyRightFormView();           // 动态创建所使用的受保护的构造函数
	virtual ~CMyRightFormView();
	enum { IDD = IDD_FORMVIEW_Right}; // 确保与资源ID匹配

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

	CButton m_button1;

	DECLARE_MESSAGE_MAP()

private:
	afx_msg void OnButton1Clicked();
};


