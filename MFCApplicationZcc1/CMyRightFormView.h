#pragma once
#include <afxext.h>


class CMyRightFormView :
    public CFormView
{
	DECLARE_DYNCREATE(CMyRightFormView)

public:
	CMyRightFormView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyRightFormView();
	enum { IDD = IDD_FORMVIEW_Right}; // ȷ������ԴIDƥ��

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

	CButton m_button1;

	DECLARE_MESSAGE_MAP()

private:
	afx_msg void OnButton1Clicked();
};


