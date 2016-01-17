
// SmallPolygonsVis.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSmallPolygonsVisApp:
// See SmallPolygonsVis.cpp for the implementation of this class
//

class CSmallPolygonsVisApp : public CWinApp
{
public:
	CSmallPolygonsVisApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSmallPolygonsVisApp theApp;