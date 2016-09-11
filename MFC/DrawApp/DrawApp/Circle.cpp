#include "stdafx.h"
#include "Circle.h"



Circle::Circle(const CPoint& start, const CPoint& end, COLORREF aColor)
{
	//находим радиус
	long Radius = static_cast<long>(sqrt(static_cast<double>(
		(start.x - end.x)*(start.x - end.x) +
		(start.y - end.y)*(start.y - end.y)
		)));
	//формируем точки
	m_StartPoint.x = start.x - Radius;
	m_StartPoint.y = start.y - Radius;
	m_EndPoint.x = start.x + Radius;
	m_EndPoint.y = start.y + Radius;

	m_PenWidth = 1;
	m_Color = aColor;

	//описывающий четырехугольник
	m_EnclosingRect = CRect(m_StartPoint, m_EndPoint);
	//нормализация
	m_EnclosingRect.NormalizeRect();
}

void Circle::Draw(CDC* pDC)
{
	CPen aPen;//объект перо
			  //если не удалось создать перо, то сообщение и выход
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
	{
		AfxMessageBox(_T("не удалось создать перо для круга"), MB_OK);
		AfxAbort();
	}

	//выбираем созданое перо и нулевую кисть
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	//рисуем элипс
	pDC->Ellipse(m_EnclosingRect);

	//восстанавливаем кисть и перо
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}