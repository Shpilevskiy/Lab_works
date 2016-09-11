#pragma once

// конечный объект команды DrawElement

class DrawElement : public CObject
{
	protected:
		int m_PenWidth;//ширина пера
		COLORREF m_Сolor;//цвет фигуры
		CRect m_EnclosingRect;//описывающий четырехугольник

	public:
		virtual ~DrawElement();
		virtual void Draw(CDC* pDC) {};//рисует фигуру
		virtual CRect GetBoundRect();//возвращает описывающий четырехугольник
	protected:
		DrawElement();//предотвращение вызова в предках
};


