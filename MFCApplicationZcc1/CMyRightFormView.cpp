#include "pch.h"
#include "MFCApplicationZcc1.h" // �����Ŀͷ�ļ�
#include "MFCApplicationZcc1Doc.h"
#include "CMyRightFormView.h"
#include "resource.h"


IMPLEMENT_DYNCREATE(CMyRightFormView, CFormView)

CMyRightFormView::CMyRightFormView()
	: CFormView(CMyRightFormView::IDD)
{
}

CMyRightFormView::~CMyRightFormView()
{
}

void CMyRightFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
}

BEGIN_MESSAGE_MAP(CMyRightFormView, CFormView)
	//ON_BN_CLICKED(IDC_BUTTON1, [](void) {
	//	AfxMessageBox(_T("�Ҳఴť�������"));
	//	})
	ON_BN_CLICKED(IDC_BUTTON1, &CMyRightFormView::OnButton1Clicked)
END_MESSAGE_MAP()

void CMyRightFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	UpdateData(FALSE); // ���¿ؼ���ʾ
}

void CMyRightFormView::OnButton1Clicked()
{
	//AfxMessageBox(_T("Button1 is clicked."));

	CMFCApplicationZcc1Doc* pDoc = (CMFCApplicationZcc1Doc*)GetDocument();
	if (pDoc)
	{
		pDoc->AddItemToListBox(_T("������һ����ͼ����"));
	}

	//CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST2);
	//if (pListBox)
	//{
	//	int nCount = pListBox->GetCount();
	//	CString strMessage;
	//	strMessage.Format(_T("ListBox ��ǰ�� %d �"), nCount);
	//	AfxMessageBox(strMessage);
	//	pListBox->AddString(_T("New item."));
	//}
}