
// DrawAppView.cpp : реализация класса CDrawAppView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "DrawApp.h"
#include "DrawLine.h"
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

// создание/уничтожение CDrawAppView

CDrawAppView::CDrawAppView() : m_StartPoint(0), m_EndPoint(0), m_pTempElement(nullptr)
{

	// TODO: добавьте код создания
}

CDrawAppView::~CDrawAppView()
{
}

BOOL CDrawAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CDrawAppView

void CDrawAppView::OnDraw(CDC* /*pDC*/)
{
	CDrawAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
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


// диагностика CDrawAppView

#ifdef _DEBUG
void CDrawAppView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawAppDoc* CDrawAppView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawAppDoc)));
	return (CDrawAppDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CDrawAppView


void CDrawAppView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	SetCapture();//перехватыватьв се последующие сообщения
	m_StartPoint = point;//точка нажатия мышки
	//CView::OnLButtonDown(nFlags, point);
}


void CDrawAppView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CClientDC aDC(this);
	//проверяем нажата ли кнопка мышки и курсор пренадлежит нашему виду
	if ((nFlags&MK_LBUTTON) && (this == GetCapture()))
	{
		m_EndPoint = point;
		//если нарисован элемент, то его нужно удалить
		if (m_pTempElement)
		{
			aDC.SetROP2(R2_NOTXORPEN);//устанавливаем режим
			m_pTempElement->Draw(&aDC);//удаляем элемент
			delete m_pTempElement;//удаляем память
			m_pTempElement = nullptr;//обнуляем указатель
		}
		//рисуем элемент
		m_pTempElement = CreateElement();
		m_pTempElement->Draw(&aDC);
	}

	//CView::OnMouseMove(nFlags, point);
}


void CDrawAppView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (m_pTempElement)
	{
		ReleaseCapture();//освободить мышь
		delete m_pTempElement;//освобождаем память
		m_pTempElement = nullptr;//обнуляем указатель
	}
	//CView::OnLButtonUp(nFlags, point);
}


DrawElement* CDrawAppView::CreateElement(void)
{
	CDrawAppDoc* pDoc = GetDocument();//получаем указатель на класс документа
	switch (pDoc->GetElementType())
	{
	case LINE:
		return new DrawLine(m_StartPoint, m_EndPoint, pDoc->GetElementColor());
	default:
		AfxMessageBox(_T("не известный обьект, не удалось создать [CreateElement]"), MB_OK);
		AfxAbort();//завершение программы
	}
}