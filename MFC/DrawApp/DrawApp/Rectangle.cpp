#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(const CPoint& start, const CPoint& end, COLORREF aColor, COLORREF fColor)
	:m_StartPoint(start)
	, m_EndPoint(end)
{
	m_Color = aColor;//цвет элемента
	fill_Color = fColor; //цвет заливки
	m_PenWidth = 1;//ширина пера
	m_EnclosingRect = CRect(m_StartPoint, m_EndPoint);//описывающий четырехугольник
	m_EnclosingRect.NormalizeRect();//нормализаци€
}

//IMPLEMENT_SERIAL(CRectangle, DrawElement, 1)
void CRectangle::Draw(CDC* pDC)
{
	CPen aPen;//перо
			  //если неудалось создать перо, то выводим сообщение и закрываем программу
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
	{
		AfxMessageBox(_T("Ќе удалось создать перо дл€ пр€моугольника"), MB_OK);//вывод сообщени€
		AfxAbort();//завершение программы
	}


	//сохран€ем старое перо и кисть
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	//рисуем
	pDC->Rectangle(m_EnclosingRect);//рисуем черырехугольник
									//восстанавливаем

	pDC->SelectObject(pOldPen);//восстановить старое перо
	pDC->SelectObject(pOldBrush);//восстановить старую кисть
}

IMPLEMENT_SERIAL(CRectangle, DrawElement, 1)
void CRectangle::DrawAndFill(CDC* pDC)
{
	CPen aPen;//перо
			  //если неудалось создать перо, то выводим сообщение и закрываем программу
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
	{
		AfxMessageBox(_T("Ќе удалось создать перо дл€ пр€моугольника"), MB_OK);//вывод сообщени€
		AfxAbort();//завершение программы
	}


	//сохран€ем старое перо и кисть
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	//рисуем
	pDC->Rectangle(m_EnclosingRect);//рисуем черырехугольник
									//восстанавливаем
	pDC->FillSolidRect(m_EnclosingRect, fill_Color);
	//pDC->FillSolidRect(m_EnclosingRect, RGB(0,0,0));

	pDC->SelectObject(pOldPen);//восстановить старое перо
	pDC->SelectObject(pOldBrush);//восстановить старую кисть
}


void CRectangle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
		ar << m_StartPoint << m_EndPoint << m_Color << fill_Color << m_EnclosingRect;
	else
		ar >> m_StartPoint >> m_EndPoint >> m_Color >> fill_Color >> m_EnclosingRect;
}