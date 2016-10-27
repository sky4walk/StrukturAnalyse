// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

// SobelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ddtest.h"
#include "SobelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSobelDlg dialog


CSobelDlg::CSobelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSobelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSobelDlg)
	m_Thresh = 0;
	m_Optimal = FALSE;
	//}}AFX_DATA_INIT
}


void CSobelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSobelDlg)
	DDX_Text(pDX, IDC_SOBELTHRESH, m_Thresh);
	DDV_MinMaxInt(pDX, m_Thresh, 0, 255);
	DDX_Check(pDX, IDC_OPTIMAL, m_Optimal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSobelDlg, CDialog)
	//{{AFX_MSG_MAP(CSobelDlg)
	ON_EN_CHANGE(IDC_SOBELTHRESH, OnChangeSobelthresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSobelDlg message handlers

void CSobelDlg::OnChangeSobelthresh() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
