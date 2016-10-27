// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

// GaussDlg.cpp : implementation file
// Gausseingabedialog

#include "stdafx.h"
#include "ddtest.h"
#include "GaussDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGaussDlg dialog


CGaussDlg::CGaussDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGaussDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGaussDlg)
	m_GaussSize = 0;
	//}}AFX_DATA_INIT
}


void CGaussDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGaussDlg)
	DDX_Text(pDX, IDC_GAUSSSIZE, m_GaussSize);
	DDV_MinMaxInt(pDX, m_GaussSize, 2, 15);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGaussDlg, CDialog)
	//{{AFX_MSG_MAP(CGaussDlg)
	ON_EN_CHANGE(IDC_SIZE, OnChangeSize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGaussDlg message handlers

void CGaussDlg::OnChangeSize() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
