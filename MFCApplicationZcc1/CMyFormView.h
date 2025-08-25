#pragma once
#include "afxwin.h"
#include "afxext.h"
#include "CLISTBOX1.h"

class CMyFormView : public CFormView
{
    DECLARE_DYNCREATE(CMyFormView)

public:
    CMyFormView();
    virtual ~CMyFormView();

    enum { IDD = IDD_FORMVIEW }; // ȷ������ԴIDƥ��

    // ��ѡ����ʼ������
    void SetInitialData();
    void AddItemToListBox(LPCTSTR lpszItem);

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual void OnInitialUpdate();

	CStatic m_staticLabel; // ʾ���ؼ�
    CListBox m_listBox;
    CLISTBOX1 m_listBoxActiveX;

    DECLARE_MESSAGE_MAP()

private:
    void AddActiveXItem(CLISTBOX1& listBox, LPCTSTR lpszText);
};

