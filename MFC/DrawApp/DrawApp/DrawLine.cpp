#include "stdafx.h"
#include "DrawLine.h"


DrawLine::DrawLine()
{
}


DrawLine::~DrawLine()
{
}

DrawLine::DrawLine(const CPoint& start, const CPoint& end, COLORREF aColor)
	:m_StartPoint(start)//������ �����
	, m_EndPoint(end)//������ �����
{
	m_�olor = aColor;//����
	m_PenWidth = 1;//������
	m_EnclosingRect = CRect(start, end);//����������� ���������������
	m_EnclosingRect.NormalizeRect();//������������
}

void DrawLine::Draw(CDC* pDC)
{
	CPen aPen;//������ ������ ����
			  //������� ����, ���� �� ����� �� ��������� ���������
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_�olor))
	{
		//������� ��������� � ������� � ��������� ���������
		AfxMessageBox(_T("�� ������� ������� ���� ��� �����"), MB_OK);
		AfxAbort();//���������� ���������
	}
	//�������� ����� ���� � ��������� ������
	CPen* pOldPen = pDC->SelectObject(&aPen);
	//������ �����
	pDC->MoveTo(m_StartPoint);
	pDC->LineTo(m_EndPoint);
	//���������� ������ ����
	pDC->SelectObject(pOldPen);
}