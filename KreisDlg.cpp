// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

// KreisDlg.cpp : implementation file
// Eingabedialog von Kreissuche 1

#include "stdafx.h"
#include "ddtest.h"
#include "KreisDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKreisDlg dialog


CKreisDlg::CKreisDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKreisDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKreisDlg)
	m_Radius = 0;
	m_TolAng = 0;
	m_TolRad = 0;
	m_Reso = 0;
	//}}AFX_DATA_INIT
}


void CKreisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKreisDlg)
	DDX_Text(pDX, IDC_RADIUS, m_Radius);
	DDX_Text(pDX, IDC_TOLANG, m_TolAng);
	DDV_MinMaxInt(pDX, m_TolAng, 0, 360);
	DDX_Text(pDX, IDC_TOLRAD, m_TolRad);
	DDX_Text(pDX, IDC_RESO, m_Reso);
	DDV_MinMaxInt(pDX, m_Reso, 0, 200);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKreisDlg, CDialog)
	//{{AFX_MSG_MAP(CKreisDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKreisDlg message handlers
