// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

// Kreis2Dlg.cpp : implementation file
// Eingabedialog von Kreissuche 2

#include "stdafx.h"
#include "ddtest.h"
#include "Kreis2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Kreis2Dlg dialog


Kreis2Dlg::Kreis2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Kreis2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(Kreis2Dlg)
	m_Radius = 0;
	m_TolRad = 0;
	m_SizeX = 0;
	m_SizeY = 0;
	//}}AFX_DATA_INIT
}


void Kreis2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Kreis2Dlg)
	DDX_Text(pDX, IDC_RADIUS, m_Radius);
	DDX_Text(pDX, IDC_TOLRAD, m_TolRad);
	DDX_Text(pDX, IDC_SIZE_X, m_SizeX);
	DDX_Text(pDX, IDC_SIZE_Y, m_SizeY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Kreis2Dlg, CDialog)
	//{{AFX_MSG_MAP(Kreis2Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Kreis2Dlg message handlers
