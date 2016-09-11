
// DrawApp.h : главный файл заголовка для приложения DrawApp
//
#pragma once
#include "ConstantsMenu.h"

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CDrawAppApp:
// О реализации данного класса см. DrawApp.cpp
//

class CDrawAppApp : public CWinAppEx
{
public:
	CDrawAppApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawAppApp theApp;
