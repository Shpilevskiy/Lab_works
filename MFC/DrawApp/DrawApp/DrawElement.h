#pragma once

// �������� ������ ������� DrawElement

class DrawElement : public CObject
{
	protected:
		int m_PenWidth;//������ ����
		COLORREF m_�olor;//���� ������
		CRect m_EnclosingRect;//����������� ���������������

	public:
		virtual ~DrawElement();
		virtual void Draw(CDC* pDC) {};//������ ������
		virtual CRect GetBoundRect();//���������� ����������� ���������������
	protected:
		DrawElement();//�������������� ������ � �������
};


