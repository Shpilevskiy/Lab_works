
// DrawAppDoc.h : интерфейс класса CDrawAppDoc
//


#pragma once
#include "ConstantsMenu.h"


class CDrawAppDoc : public CDocument
{
protected: // создать только из сериализации
	CDrawAppDoc();
	DECLARE_DYNCREATE(CDrawAppDoc)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CDrawAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnEelementLine();
	afx_msg void OnEelementCircle();
	afx_msg void OnEelementCurve();
	afx_msg void OnEelementRectangle32779();
private:
	// для обозначения выбранного элемента
	ElementType elementType;
	// цвет курсора
	COLORREF color;
public:
	afx_msg void OnColorBlack();
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
	afx_msg void OnUpdateEelementLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEelementRectangle32779(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEelementCircle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEelementCurve(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
	ElementType GetElementType(void);
	COLORREF GetElementColor(void);
	COLORREF GetElementFillColor(void);
	afx_msg void On32789();
	afx_msg void OnFillColorRed();
	afx_msg void OnFillColorGreen();
	afx_msg void OnFillColorBlack();
	// цвет заливки
	COLORREF fillColor;
	afx_msg void OnUpdateFillBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFillRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFillGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFillBlack(CCmdUI *pCmdUI);
};
