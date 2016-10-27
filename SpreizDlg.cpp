// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

// SpreizDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ddtest.h"
#include "SpreizDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpreizDlg dialog


CSpreizDlg::CSpreizDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpreizDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpreizDlg)
	m_Spreiz = 0;
	//}}AFX_DATA_INIT
}


void CSpreizDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpreizDlg)
	DDX_Text(pDX, IDC_SPREIZWERT, m_Spreiz);
	DDV_MinMaxInt(pDX, m_Spreiz, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpreizDlg, CDialog)
	//{{AFX_MSG_MAP(CSpreizDlg)
	ON_EN_CHANGE(IDC_SPREIZWERT, OnChangeSpreizwert)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpreizDlg message handlers

void CSpreizDlg::OnChangeSpreizwert() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
