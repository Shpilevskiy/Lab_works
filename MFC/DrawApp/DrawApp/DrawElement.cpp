// DrawElement.cpp: ���� ����������
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


// �������-����� DrawElement

CRect DrawElement::GetBoundRect()
{
	CRect r(m_EnclosingRect);//���������������
	r.InflateRect(m_PenWidth, m_PenWidth);//����������� ��������������� �� ������ ����
	return r;//������� ������������ ����������������
}