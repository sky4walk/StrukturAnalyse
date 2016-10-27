// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

// LinesDlg.cpp : implementation file
// LinensucheDialog

#include "stdafx.h"
#include "ddtest.h"
#include "LinesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinesDlg dialog


CLinesDlg::CLinesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLinesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLinesDlg)
	m_Angels = 0;
	m_Lot = 0;
	m_Thresh = 0;
	m_DelRad = 0;
	m_Lines = 0;
	m_Flt90Grad = FALSE;
	//}}AFX_DATA_INIT
}


void CLinesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinesDlg)
	DDX_Text(pDX, IDC_ANGELS, m_Angels);
	DDX_Text(pDX, IDC_LOT, m_Lot);
	DDX_Text(pDX, IDC_THRESH, m_Thresh);
	DDV_MinMaxInt(pDX, m_Thresh, 0, 10000);
	DDX_Text(pDX, IDC_DELRAD, m_DelRad);
	DDV_MinMaxInt(pDX, m_DelRad, 0, 10000);
	DDX_Text(pDX, IDC_LINES, m_Lines);
	DDX_Check(pDX, IDC_FLT90GRAD, m_Flt90Grad);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLinesDlg, CDialog)
	//{{AFX_MSG_MAP(CLinesDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinesDlg message handlers
