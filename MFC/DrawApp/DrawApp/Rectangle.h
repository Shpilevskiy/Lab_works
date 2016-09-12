#pragma once
#include "DrawElement.h"
class CRectangle :
	public DrawElement
{
protected:
	CPoint m_StartPoint;
	CPoint m_EndPoint;
public:
	CRectangle(const CPoint & start, const CPoint & end, COLORREF aColor, COLORREF fColor);
	//~CRectangle(void);
	virtual void Draw(CDC* pDC);
	virtual void DrawAndFill(CDC * pDC);
	//функция рисования
	CRectangle(const CPoint& start, const CPoint& end, COLORREF aColor);
protected:
	//CRectangle(void);
};

