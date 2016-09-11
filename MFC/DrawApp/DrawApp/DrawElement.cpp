// DrawElement.cpp: файл реализации
//

#include "stdafx.h"
#include "DrawApp.h"
#include "DrawElement.h"


// DrawElement

DrawElement::DrawElement()
{
}

DrawElement::~DrawElement()
{
}


// функции-члены DrawElement

CRect DrawElement::GetBoundRect()
{
	CRect r(m_EnclosingRect);//конструирование
	r.InflateRect(m_PenWidth, m_PenWidth);//увеличиваем четырехугольник на ширину пера
	return r;//возврат описывающего четырехугольника
}