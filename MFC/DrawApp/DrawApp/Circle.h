#pragma once
#include "DrawElement.h"
class Circle :
	public DrawElement
{
protected:
	CPoint m_StartPoint;
	CPoint m_EndPoint;
public:
	//~Circle(void);
	virtual void Draw(CDC* pDC);
	Circle(const CPoint& start, const CPoint& end, COLORREF aColor);
protected:
	//Circle(void);//запрет вызова
};

