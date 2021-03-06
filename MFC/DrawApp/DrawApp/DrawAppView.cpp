
// DrawAppView.cpp : ���������� ������ CDrawAppView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "DrawApp.h"
#include "DrawLine.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Curve.h"
#endif

#include "DrawAppDoc.h"
#include "DrawAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawAppView

IMPLEMENT_DYNCREATE(CDrawAppView, CView)

BEGIN_MESSAGE_MAP(CDrawAppView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// ��������/����������� CDrawAppView

CDrawAppView::CDrawAppView() : m_StartPoint(0), m_EndPoint(0), m_pTempElement(nullptr)
{

	// TODO: �������� ��� ��������
}

CDrawAppView::~CDrawAppView()
{
}

BOOL CDrawAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CDrawAppView

void CDrawAppView::OnDraw(CDC* pDC)
{
	CDrawAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int Index = pDoc->GetNumLines();
	while (Index--)
		pDoc->GetRectangle(Index)->DrawAndFill(pDC);
	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}

void CDrawAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� CDrawAppView

#ifdef _DEBUG
void CDrawAppView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawAppDoc* CDrawAppView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawAppDoc)));
	return (CDrawAppDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CDrawAppView


void CDrawAppView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	SetCapture();//�������������� �� ����������� ���������
	m_StartPoint = point;//����� ������� �����
	CView::OnLButtonDown(nFlags, point);
}


void CDrawAppView::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC aDC(this);
	//��������� ������ �� ������ ����� � ������ ����������� ������ ����
	if ((nFlags&MK_LBUTTON) && (this == GetCapture()))
	{
		m_EndPoint = point;
		//���� ��������� �������, �� ��� ����� �������
		if (m_pTempElement)
		{
			if (CURVE == GetDocument()->GetElementType())
			{
				//��������� ����� � ���������� ��������
				static_cast<Curve*>(m_pTempElement)->AddSegment(m_EndPoint);
				m_pTempElement->Draw(&aDC);//�������������� �������
				return;
			}
			
			aDC.SetROP2(R2_NOTXORPEN);//������������� �����
			m_pTempElement->Draw(&aDC);//������� �������
			delete m_pTempElement;//������� ������
			m_pTempElement = nullptr;//�������� ���������
		}
		//������ �������
		m_pTempElement = CreateElement();
		m_pTempElement->Draw(&aDC);
	}
}


void CDrawAppView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC aDC(this);
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	if (m_pTempElement)
	{
		if (RECTANGLE == GetDocument()->GetElementType())
		{
			CDrawAppDoc* pDoc = GetDocument();
			//��������� ����� � ���������� ��������
			m_pTempElement->DrawAndFill(&aDC);//�������������� �������
			pDoc->AddRectangle(m_StartPoint, m_EndPoint, pDoc->GetElementColor(), pDoc->GetElementFillColor());
		}

		ReleaseCapture();//���������� ����
		delete m_pTempElement;//����������� ������
		m_pTempElement = nullptr;//�������� ���������
	}
	//CView::OnLButtonUp(nFlags, point);
}


DrawElement* CDrawAppView::CreateElement(void)
{
	CDrawAppDoc* pDoc = GetDocument();//�������� ��������� �� ����� ���������
	switch (pDoc->GetElementType())
	{
	case LINE:
		return new DrawLine(m_StartPoint, m_EndPoint, pDoc->GetElementColor());
	case RECTANGLE:
		return new CRectangle(m_StartPoint, m_EndPoint, pDoc->GetElementColor(), pDoc->GetElementFillColor());
	case CIRCLE:
		return new Circle(m_StartPoint, m_EndPoint, pDoc->GetElementColor());
	case CURVE:
		return new Curve(m_StartPoint, m_EndPoint, pDoc->GetElementColor());
	default:
		AfxMessageBox(_T("�� ��������� ������, �� ������� ������� [CreateElement]"), MB_OK);
		AfxAbort();//���������� ���������
	}
	return NULL;
}