#include "pch.h"
#include "MFCApplicationZcc1.h" // 你的项目头文件
#include "CMyFormView.h"
#include "resource.h"

IMPLEMENT_DYNCREATE(CMyFormView, CFormView)

CMyFormView::CMyFormView()
    : CFormView(CMyFormView::IDD)
{
}

CMyFormView::~CMyFormView()
{
}

void CMyFormView::DoDataExchange(CDataExchange* pDX)
{
    CFormView::DoDataExchange(pDX);
    // 在这里添加控件变量绑定
    // DDX_Control(pDX, IDC_EDIT1, m_editControl);
    // DDX_Text(pDX, IDC_EDIT1, m_strText);
    //DDX_Control(pDX, IDC_STATIC, m_staticLabel); // 假设有一个静态文本控件
    DDX_Control(pDX, IDC_LABEL1, m_staticLabel);
    DDX_Control(pDX, IDC_LIST2, m_listBox);
    DDX_Control(pDX, IDC_LISTBOX1, m_listBoxActiveX);
}

BEGIN_MESSAGE_MAP(CMyFormView, CFormView)
    // 添加消息处理
    // ON_BN_CLICKED(IDC_BUTTON1, &CMyFormView::OnBnClickedButton1)
END_MESSAGE_MAP()

// 可选：初始化方法
void CMyFormView::SetInitialData()
{
    // 初始化表单数据
    // m_strText = _T("Initial Text");
    // UpdateData(FALSE); // 更新控件显示
}

void CMyFormView::OnInitialUpdate()
{
    CFormView::OnInitialUpdate();

    // 在初始化或任何需要的地方
    CWnd* pStatic = GetDlgItem(IDC_STATIC);
    if (pStatic)
    {
        pStatic->SetWindowText(_T("你好，这是新文本！"));
    }

    // 初始化 ListBox
    if (m_listBox.GetSafeHwnd()) {
        m_listBox.AddString(_T("Item 1"));
        m_listBox.AddString(_T("Item 2"));
        m_listBox.AddString(_T("Item 3"));

        // 确保显示
        m_listBox.SetCurSel(0);
        m_listBox.Invalidate();
        m_listBox.UpdateWindow();

        // 可选：设置列表高度以适应内容
        //int itemHeight = m_listBox.GetItemHeight(0);
        //m_listBox.SetWindowPos(NULL, 0, 0, 200, itemHeight * 5, SWP_NOMOVE | SWP_NOZORDER);
    } else {
		AfxMessageBox(_T("ListBox 控件未找到或未正确初始化！"));
    }

    // 假设包装类名为 CMyActiveXListBox
    VARIANT varItem;
    VariantInit(&varItem);
    varItem.vt = VT_BSTR;
    varItem.bstrVal = SysAllocString(L"ActiveX Item 1");
    m_listBoxActiveX.AddItem(&varItem, 0);
    VariantClear(&varItem);

    AddActiveXItem(m_listBoxActiveX, _T("ActiveX Item 2"));
    AddActiveXItem(m_listBoxActiveX, _T("ActiveX Item 3"));

    m_staticLabel.SetWindowText(_T("Hello, MFC Form View!")); // 设置静态文本控件的内容
    UpdateData(FALSE); // 更新控件显示
}

// 在头文件中添加辅助函数
void CMyFormView::AddActiveXItem(CLISTBOX1& listBox, LPCTSTR lpszText)
{
    COleVariant varItem(lpszText);
    size_t index = -1;
    if (index == -1)
    {
        // 自动添加到末尾
        index = listBox.get_ListCount();
    }
	COleVariant varIndex(index);
    listBox.AddItem(varItem, varIndex);
}