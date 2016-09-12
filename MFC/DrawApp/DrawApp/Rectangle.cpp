#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(const CPoint& start, const CPoint& end, COLORREF aColor, COLORREF fColor)
	:m_StartPoint(start)
	, m_EndPoint(end)
{
	m_Color = aColor;//���� ��������
	fill_Color = fColor; //���� �������
	m_PenWidth = 1;//������ ����
	m_EnclosingRect = CRect(m_StartPoint, m_EndPoint);//����������� ���������������
	m_EnclosingRect.NormalizeRect();//������������
}

//IMPLEMENT_SERIAL(CRectangle, DrawElement, 1)
void CRectangle::Draw(CDC* pDC)
{
	CPen aPen;//����
			  //���� ��������� ������� ����, �� ������� ��������� � ��������� ���������
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
	{
		AfxMessageBox(_T("�� ������� ������� ���� ��� ��������������"), MB_OK);//����� ���������
		AfxAbort();//���������� ���������
	}


	//��������� ������ ���� � �����
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	//������
	pDC->Rectangle(m_EnclosingRect);//������ ���������������
									//���������������

	pDC->SelectObject(pOldPen);//������������ ������ ����
	pDC->SelectObject(pOldBrush);//������������ ������ �����
}

IMPLEMENT_SERIAL(CRectangle, DrawElement, 1)
void CRectangle::DrawAndFill(CDC* pDC)
{
	CPen aPen;//����
			  //���� ��������� ������� ����, �� ������� ��������� � ��������� ���������
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
	{
		AfxMessageBox(_T("�� ������� ������� ���� ��� ��������������"), MB_OK);//����� ���������
		AfxAbort();//���������� ���������
	}


	//��������� ������ ���� � �����
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	//������
	pDC->Rectangle(m_EnclosingRect);//������ ���������������
									//���������������
	pDC->FillSolidRect(m_EnclosingRect, fill_Color);
	//pDC->FillSolidRect(m_EnclosingRect, RGB(0,0,0));

	pDC->SelectObject(pOldPen);//������������ ������ ����
	pDC->SelectObject(pOldBrush);//������������ ������ �����
}


void CRectangle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
		ar << m_StartPoint << m_EndPoint << m_Color << fill_Color << m_EnclosingRect;
	else
		ar >> m_StartPoint >> m_EndPoint >> m_Color >> fill_Color >> m_EnclosingRect;
}