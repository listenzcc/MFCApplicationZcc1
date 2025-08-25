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

    enum { IDD = IDD_FORMVIEW }; // 确保与资源ID匹配

    // 可选：初始化方法
    void SetInitialData();
    void AddItemToListBox(LPCTSTR lpszItem);

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual void OnInitialUpdate();

	CStatic m_staticLabel; // 示例控件
    CListBox m_listBox;
    CLISTBOX1 m_listBoxActiveX;

    DECLARE_MESSAGE_MAP()

private:
    void AddActiveXItem(CLISTBOX1& listBox, LPCTSTR lpszText);
};

