
// DrawAppView.h : интерфейс класса CDrawAppView
//

#pragma once
#include "DrawElement.h"

class CDrawAppView : public CView
{
private:
	CPoint m_StartPoint;
	CPoint m_EndPoint;
	DrawElement* m_pTempElement;
protected: // создать только из сериализации
	CDrawAppView();
	DECLARE_DYNCREATE(CDrawAppView)

// Атрибуты
public:
	CDrawAppDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Реализация
public:
	virtual ~CDrawAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	DrawElement * CreateElement(void);
	ElementType GetElementType(void);
	COLORREF GetElementColor(void);
};

#ifndef _DEBUG  // отладочная версия в DrawAppView.cpp
inline CDrawAppDoc* CDrawAppView::GetDocument() const
   { return reinterpret_cast<CDrawAppDoc*>(m_pDocument); }
#endif

