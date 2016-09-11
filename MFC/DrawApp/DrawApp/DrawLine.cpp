#include "stdafx.h"
#include "DrawLine.h"


DrawLine::DrawLine()
{
}


DrawLine::~DrawLine()
{
}

DrawLine::DrawLine(const CPoint& start, const CPoint& end, COLORREF aColor)
	:m_StartPoint(start)//первая точка
	, m_EndPoint(end)//вторая точка
{
	m_Color = aColor;//цвет
	m_PenWidth = 1;//ширина
	m_EnclosingRect = CRect(start, end);//описывающий четырехугольник
	m_EnclosingRect.NormalizeRect();//нормализация
}

void DrawLine::Draw(CDC* pDC)
{
	CPen aPen;//общект нового пера
			  //создаем перо, если не удача то закрываем программу
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
	{
		//выводим сообщение о неудаче и завершаем программу
		AfxMessageBox(_T("Не удалось создать перо для линии"), MB_OK);
		AfxAbort();//завершение программы
	}
	//выбираем новое перо и сохраняем старое
	CPen* pOldPen = pDC->SelectObject(&aPen);
	//рисуем линию
	pDC->MoveTo(m_StartPoint);
	pDC->LineTo(m_EndPoint);
	//возвращаем старое перо
	pDC->SelectObject(pOldPen);
}