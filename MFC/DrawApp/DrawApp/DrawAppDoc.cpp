
// DrawAppDoc.cpp : реализация класса CDrawAppDoc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "DrawApp.h"
#endif

#include "DrawAppDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDrawAppDoc

IMPLEMENT_DYNCREATE(CDrawAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawAppDoc, CDocument)
	ON_COMMAND(ID_EELEMENT_LINE, &CDrawAppDoc::OnEelementLine)
	ON_COMMAND(ID_EELEMENT_CIRCLE, &CDrawAppDoc::OnEelementCircle)
	ON_COMMAND(ID_EELEMENT_CURVE, &CDrawAppDoc::OnEelementCurve)
	ON_COMMAND(ID_EELEMENT_RECTANGLE32779, &CDrawAppDoc::OnEelementRectangle32779)
	ON_COMMAND(ID_COLOR_BLACK, &CDrawAppDoc::OnColorBlack)
	ON_COMMAND(ID_COLOR_RED, &CDrawAppDoc::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CDrawAppDoc::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CDrawAppDoc::OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_EELEMENT_LINE, &CDrawAppDoc::OnUpdateEelementLine)
	ON_UPDATE_COMMAND_UI(ID_EELEMENT_RECTANGLE32779, &CDrawAppDoc::OnUpdateEelementRectangle32779)
	ON_UPDATE_COMMAND_UI(ID_EELEMENT_CIRCLE, &CDrawAppDoc::OnUpdateEelementCircle)
	ON_UPDATE_COMMAND_UI(ID_EELEMENT_CURVE, &CDrawAppDoc::OnUpdateEelementCurve)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, &CDrawAppDoc::OnUpdateColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CDrawAppDoc::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CDrawAppDoc::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CDrawAppDoc::OnUpdateColorBlue)
	ON_COMMAND(ID_32789, &CDrawAppDoc::On32789)
	ON_COMMAND(ID_32790, &CDrawAppDoc::OnFillColorRed)
	ON_COMMAND(ID_32791, &CDrawAppDoc::OnFillColorGreen)
	ON_COMMAND(ID_32792, &CDrawAppDoc::OnFillColorBlack)
	ON_UPDATE_COMMAND_UI(ID_32789, &CDrawAppDoc::OnUpdateFillBlue)
	ON_UPDATE_COMMAND_UI(ID_32790, &CDrawAppDoc::OnUpdateFillRed)
	ON_UPDATE_COMMAND_UI(ID_32791, &CDrawAppDoc::OnUpdateFillGreen)
	ON_UPDATE_COMMAND_UI(ID_32792, &CDrawAppDoc::OnUpdateFillBlack)
	ON_COMMAND(ID_EDIT_UNDO, &CDrawAppDoc::OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, &CDrawAppDoc::OnUpdateEditUndo)
END_MESSAGE_MAP()


// создание/уничтожение CDrawAppDoc

CDrawAppDoc::CDrawAppDoc() :elementType(LINE), color(BLACK)
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CDrawAppDoc::~CDrawAppDoc()
{
}

BOOL CDrawAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// сериализация CDrawAppDoc

void CDrawAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		m_RectangleArray.Serialize(ar);
		// TODO: добавьте код сохранения
	}
	else
	{
		m_RectangleArray.Serialize(ar);
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CDrawAppDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CDrawAppDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CDrawAppDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// диагностика CDrawAppDoc

#ifdef _DEBUG
void CDrawAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// команды CDrawAppDoc
void CDrawAppDoc::AddRectangle(CPoint& m_StartPoint,CPoint& m_EndPoint)
{
	CRectangle *rectangle = new CRectangle(m_StartPoint, m_EndPoint, GetElementColor(), GetElementFillColor());
	m_RectangleArray.Add(rectangle);
	SetModifiedFlag();
}

int CDrawAppDoc::GetNumLines()
{
	return (int)m_RectangleArray.GetSize();
}

CRectangle* CDrawAppDoc::GetRectangle(int Index)
{
	if (Index<0 || Index>m_RectangleArray.GetUpperBound())
	{
		return 0;
	}
	return m_RectangleArray.GetAt(Index);
}

void CDrawAppDoc::OnEelementLine()
{
	elementType = LINE;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnEelementCircle()
{
	elementType = CIRCLE;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnEelementCurve()
{
	elementType = CURVE;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnEelementRectangle32779()
{
	elementType = RECTANGLE;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnColorBlack()
{
	color = BLACK;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnColorRed()
{
	color = RED;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnColorGreen()
{
	color = GREEN;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnColorBlue()
{
	color = BLUE;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnUpdateEelementLine(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == LINE);
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CDrawAppDoc::OnUpdateEelementRectangle32779(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == RECTANGLE);
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CDrawAppDoc::OnUpdateEelementCircle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == CIRCLE);
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CDrawAppDoc::OnUpdateEelementCurve(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == CURVE);
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CDrawAppDoc::OnUpdateColorBlack(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(color == BLACK);
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CDrawAppDoc::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(color == RED);
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CDrawAppDoc::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(color == GREEN);
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CDrawAppDoc::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(color == BLUE);
	// TODO: добавьте свой код обработчика ИП обновления команд
}

ElementType CDrawAppDoc::GetElementType(void)
{
	return elementType;
}


COLORREF CDrawAppDoc::GetElementColor(void)
{
	return color;
}

COLORREF CDrawAppDoc::GetElementFillColor(void)
{
	return fillColor;
}

void CDrawAppDoc::On32789()
{
	fillColor = BLUE;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnFillColorRed()
{
	fillColor = RED;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnFillColorGreen()
{
	fillColor = GREEN;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnFillColorBlack()
{
	fillColor = BLACK;
	// TODO: добавьте свой код обработчика команд
}


void CDrawAppDoc::OnUpdateFillBlue(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(fillColor == BLUE);
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CDrawAppDoc::OnUpdateFillRed(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(fillColor == RED);
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CDrawAppDoc::OnUpdateFillGreen(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(fillColor == GREEN);
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CDrawAppDoc::OnUpdateFillBlack(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(fillColor == BLACK);
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CDrawAppDoc::DeleteContents()
{
	// TODO: добавьте специализированный код или вызов базового класса

	CDocument::DeleteContents();
}


void CDrawAppDoc::OnEditUndo()
{
	// TODO: добавьте свой код обработчика команд
	int Index = (int)m_RectangleArray.GetUpperBound();
	if (Index>-1)
	{
		delete m_RectangleArray.GetAt(Index);
		m_RectangleArray.RemoveAt(Index);
	}
	UpdateAllViews(0);
	SetModifiedFlag();
}


void CDrawAppDoc::OnUpdateEditUndo(CCmdUI *pCmdUI)
{
	pCmdUI->Enable((int)m_RectangleArray.GetSize());
	// TODO: добавьте свой код обработчика ИП обновления команд
}
