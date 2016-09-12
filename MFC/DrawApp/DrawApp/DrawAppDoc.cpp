
// DrawAppDoc.cpp : ���������� ������ CDrawAppDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
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


// ��������/����������� CDrawAppDoc

CDrawAppDoc::CDrawAppDoc() :elementType(LINE), color(BLACK)
{
	// TODO: �������� ��� ��� ������������ ������ ������������

}

CDrawAppDoc::~CDrawAppDoc()
{
}

BOOL CDrawAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)

	return TRUE;
}




// ������������ CDrawAppDoc

void CDrawAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		m_RectangleArray.Serialize(ar);
		// TODO: �������� ��� ����������
	}
	else
	{
		m_RectangleArray.Serialize(ar);
		// TODO: �������� ��� ��������
	}
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void CDrawAppDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
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

// ��������� ������������ ������
void CDrawAppDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
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

// ����������� CDrawAppDoc

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


// ������� CDrawAppDoc
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
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnEelementCircle()
{
	elementType = CIRCLE;
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnEelementCurve()
{
	elementType = CURVE;
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnEelementRectangle32779()
{
	elementType = RECTANGLE;
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnColorBlack()
{
	color = BLACK;
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnColorRed()
{
	color = RED;
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnColorGreen()
{
	color = GREEN;
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnColorBlue()
{
	color = BLUE;
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnUpdateEelementLine(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == LINE);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CDrawAppDoc::OnUpdateEelementRectangle32779(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == RECTANGLE);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CDrawAppDoc::OnUpdateEelementCircle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == CIRCLE);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CDrawAppDoc::OnUpdateEelementCurve(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == CURVE);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CDrawAppDoc::OnUpdateColorBlack(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(color == BLACK);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CDrawAppDoc::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(color == RED);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CDrawAppDoc::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(color == GREEN);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CDrawAppDoc::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(color == BLUE);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
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
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnFillColorRed()
{
	fillColor = RED;
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnFillColorGreen()
{
	fillColor = GREEN;
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnFillColorBlack()
{
	fillColor = BLACK;
	// TODO: �������� ���� ��� ����������� ������
}


void CDrawAppDoc::OnUpdateFillBlue(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(fillColor == BLUE);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CDrawAppDoc::OnUpdateFillRed(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(fillColor == RED);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CDrawAppDoc::OnUpdateFillGreen(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(fillColor == GREEN);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CDrawAppDoc::OnUpdateFillBlack(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(fillColor == BLACK);
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}


void CDrawAppDoc::DeleteContents()
{
	// TODO: �������� ������������������ ��� ��� ����� �������� ������

	CDocument::DeleteContents();
}


void CDrawAppDoc::OnEditUndo()
{
	// TODO: �������� ���� ��� ����������� ������
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
	// TODO: �������� ���� ��� ����������� �� ���������� ������
}
