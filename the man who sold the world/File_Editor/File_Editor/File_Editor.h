
// File_Editor.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFileEditorApp:
// See File_Editor.cpp for the implementation of this class
//

class CFileEditorApp : public CWinApp
{
public:
	CFileEditorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFileEditorApp theApp;
