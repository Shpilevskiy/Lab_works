#pragma once
#include "DrawElement.h"
class DrawLine :
	public DrawElement
{
protected:
	CPoint m_StartPoint;
	CPoint m_EndPoint;

public:
	~DrawLine(void);
	virtual void Draw(CDC* pDC);//функция рисования
								//конструктор преобразования
	DrawLine(const CPoint& start, const CPoint& end, COLORREF color);
protected:
	DrawLine();//запрет вызова
};

