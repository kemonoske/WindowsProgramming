
// Laborator4.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CLaborator4App:
// О реализации данного класса см. Laborator4.cpp
//

class CLaborator4App : public CWinApp
{
public:
	CLaborator4App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CLaborator4App theApp;