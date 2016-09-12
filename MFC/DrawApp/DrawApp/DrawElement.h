#pragma once
#include <cmath>
#include <vector>
using std::vector;
// �������� ������ ������� DrawElement

class DrawElement : public CObject
{
	protected:
		int m_PenWidth;//������ ����
		COLORREF m_Color;//���� ������
		COLORREF fill_Color;//���� �������
		CRect m_EnclosingRect;//����������� ���������������

	public:
		virtual ~DrawElement();
		virtual void Draw(CDC* pDC) {};//������ ������
		virtual void DrawAndFill(CDC* pDC) {};//������ ������
		virtual CRect GetBoundRect();//���������� ����������� ���������������
	protected:
		DrawElement();//�������������� ������ � �������
};


