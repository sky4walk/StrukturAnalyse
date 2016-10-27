// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

// ddtest.h : main header file for the DDTEST application
//

#if !defined(AFX_DDTEST_H__857AC09A_FCF2_4704_9C24_3AAC553F981D__INCLUDED_)
#define AFX_DDTEST_H__857AC09A_FCF2_4704_9C24_3AAC553F981D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDdtestApp:
// See ddtest.cpp for the implementation of this class
//

class CDdtestApp : public CWinApp
{
public:
	CDdtestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDdtestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDdtestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDTEST_H__857AC09A_FCF2_4704_9C24_3AAC553F981D__INCLUDED_)
