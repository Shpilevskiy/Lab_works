
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
		// TODO: �������� ��� ����������
	}
	else
	{
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