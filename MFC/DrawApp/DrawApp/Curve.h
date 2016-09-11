#pragma once
#include "DrawElement.h"
class Curve :
	public DrawElement
{
protected:
	vector<CPoint> m_Points;//вектор с точками
public:
	//~Curve(void);
	virtual void Draw(CDC* pDC);
	void AddSegment(const CPoint& point);//добавляет точку к вектору
	Curve(const CPoint& p1, const CPoint& p2, COLORREF aColor);
protected:
	//Curve(void);
};

