#include "stdafx.h"
#include "Curve.h"


Curve::Curve(const CPoint& p1, const CPoint& p2, COLORREF aColor)
{
	m_PenWidth = 1;
	m_Color = aColor;
	//добавляем в массив две точки
	m_Points.push_back(p1);
	m_Points.push_back(p2);

	//описывающий четырехугольник
	m_EnclosingRect = CRect(min(p1.x, p2.x),
		min(p1.y, p2.y),
		max(p1.x, p2.x),
		max(p1.y, p2.y));
	m_EnclosingRect.NormalizeRect();//нормализация
}

void Curve::AddSegment(const CPoint& point)
{
	m_Points.push_back(point);

	m_EnclosingRect = CRect(min(m_EnclosingRect.left, point.x),
		min(m_EnclosingRect.top, point.y),
		max(m_EnclosingRect.right, point.x),
		max(m_EnclosingRect.bottom, point.y));
}

void Curve::Draw(CDC* pDC)
{
	CPen aPen;
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
	{
		AfxMessageBox(_T(""), MB_OK);
		AfxAbort();
	}

	//выбираем новое перо и сохраняем старое
	CPen* pOldPen = pDC->SelectObject(&aPen);

	//рисуем кривую
	pDC->MoveTo(m_Points[0]);
	for (int i = 1; i<m_Points.size(); ++i)
		pDC->LineTo(m_Points[i]);

	//восстанавливаем старое перо
	pDC->SelectObject(pOldPen);
}