#include "pch.h"
#include "MFCApplicationZcc1.h" // �����Ŀͷ�ļ�
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
    // ��������ӿؼ�������
    // DDX_Control(pDX, IDC_EDIT1, m_editControl);
    // DDX_Text(pDX, IDC_EDIT1, m_strText);
    //DDX_Control(pDX, IDC_STATIC, m_staticLabel); // ������һ����̬�ı��ؼ�
    DDX_Control(pDX, IDC_LABEL1, m_staticLabel);
    DDX_Control(pDX, IDC_LIST2, m_listBox);
    DDX_Control(pDX, IDC_LISTBOX1, m_listBoxActiveX);
}

BEGIN_MESSAGE_MAP(CMyFormView, CFormView)
    // �����Ϣ����
    // ON_BN_CLICKED(IDC_BUTTON1, &CMyFormView::OnBnClickedButton1)
END_MESSAGE_MAP()

// ��ѡ����ʼ������
void CMyFormView::SetInitialData()
{
    // ��ʼ��������
    // m_strText = _T("Initial Text");
    // UpdateData(FALSE); // ���¿ؼ���ʾ
}

void CMyFormView::OnInitialUpdate()
{
    CFormView::OnInitialUpdate();

    // �ڳ�ʼ�����κ���Ҫ�ĵط�
    CWnd* pStatic = GetDlgItem(IDC_STATIC);
    if (pStatic)
    {
        pStatic->SetWindowText(_T("��ã��������ı���"));
    }

    // ��ʼ�� ListBox
    if (m_listBox.GetSafeHwnd()) {
        m_listBox.AddString(_T("Item 1"));
        m_listBox.AddString(_T("Item 2"));
        m_listBox.AddString(_T("Item 3"));

        // ȷ����ʾ
        m_listBox.SetCurSel(0);
        m_listBox.Invalidate();
        m_listBox.UpdateWindow();

        // ��ѡ�������б�߶�����Ӧ����
        //int itemHeight = m_listBox.GetItemHeight(0);
        //m_listBox.SetWindowPos(NULL, 0, 0, 200, itemHeight * 5, SWP_NOMOVE | SWP_NOZORDER);
    } else {
		AfxMessageBox(_T("ListBox �ؼ�δ�ҵ���δ��ȷ��ʼ����"));
    }

    // �����װ����Ϊ CMyActiveXListBox
    VARIANT varItem;
    VariantInit(&varItem);
    varItem.vt = VT_BSTR;
    varItem.bstrVal = SysAllocString(L"ActiveX Item 1");
    m_listBoxActiveX.AddItem(&varItem, 0);
    VariantClear(&varItem);

    AddActiveXItem(m_listBoxActiveX, _T("ActiveX Item 2"));
    AddActiveXItem(m_listBoxActiveX, _T("ActiveX Item 3"));

    m_staticLabel.SetWindowText(_T("Hello, MFC Form View!")); // ���þ�̬�ı��ؼ�������
    UpdateData(FALSE); // ���¿ؼ���ʾ
}

// ��ͷ�ļ�����Ӹ�������
void CMyFormView::AddActiveXItem(CLISTBOX1& listBox, LPCTSTR lpszText)
{
    COleVariant varItem(lpszText);
    size_t index = -1;
    if (index == -1)
    {
        // �Զ���ӵ�ĩβ
        index = listBox.get_ListCount();
    }
	COleVariant varIndex(index);
    listBox.AddItem(varItem, varIndex);
}