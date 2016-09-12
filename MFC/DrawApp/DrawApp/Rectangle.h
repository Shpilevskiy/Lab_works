#pragma once
#include "DrawElement.h"
class CRectangle :
	public DrawElement
{
protected:
	CPoint m_StartPoint;
	CPoint m_EndPoint;
	CRectangle() {}
	
public:
	//serializer
	DECLARE_SERIAL(CRectangle)
	virtual void Serialize(CArchive& ar);
	CRectangle(const CPoint & start, const CPoint & end, COLORREF aColor, COLORREF fColor);
	//~CRectangle(void);
	virtual void Draw(CDC* pDC);
	virtual void DrawAndFill(CDC * pDC);
	//функция рисования
protected:
	//CRectangle(void);
};

