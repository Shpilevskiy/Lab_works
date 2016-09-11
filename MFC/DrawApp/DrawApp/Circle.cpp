#include "stdafx.h"
#include "Circle.h"



Circle::Circle(const CPoint& start, const CPoint& end, COLORREF aColor)
{
	//������� ������
	long Radius = static_cast<long>(sqrt(static_cast<double>(
		(start.x - end.x)*(start.x - end.x) +
		(start.y - end.y)*(start.y - end.y)
		)));
	//��������� �����
	m_StartPoint.x = start.x - Radius;
	m_StartPoint.y = start.y - Radius;
	m_EndPoint.x = start.x + Radius;
	m_EndPoint.y = start.y + Radius;

	m_PenWidth = 1;
	m_Color = aColor;

	//����������� ���������������
	m_EnclosingRect = CRect(m_StartPoint, m_EndPoint);
	//������������
	m_EnclosingRect.NormalizeRect();
}

void Circle::Draw(CDC* pDC)
{
	CPen aPen;//������ ����
			  //���� �� ������� ������� ����, �� ��������� � �����
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
	{
		AfxMessageBox(_T("�� ������� ������� ���� ��� �����"), MB_OK);
		AfxAbort();
	}

	//�������� �������� ���� � ������� �����
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	//������ �����
	pDC->Ellipse(m_EnclosingRect);

	//��������������� ����� � ����
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}