
// DrawApp.h : ������� ���� ��������� ��� ���������� DrawApp
//
#pragma once
#include "ConstantsMenu.h"

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CDrawAppApp:
// � ���������� ������� ������ ��. DrawApp.cpp
//

class CDrawAppApp : public CWinAppEx
{
public:
	CDrawAppApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawAppApp theApp;
