// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

#include "stdafx.h"
#include "ddtest.h"
#include "ThreshDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThreshDlg dialog


CThreshDlg::CThreshDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreshDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreshDlg)
	m_Thresh = 0;
	m_Average = FALSE;
	//}}AFX_DATA_INIT
}


void CThreshDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreshDlg)
	DDX_Text(pDX, IDC_THRESH, m_Thresh);
	DDV_MinMaxInt(pDX, m_Thresh, 0, 255);
	DDX_Check(pDX, IDC_AVERAGE, m_Average);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CThreshDlg, CDialog)
	//{{AFX_MSG_MAP(CThreshDlg)
	ON_EN_CHANGE(IDC_THRESH, OnChangeThresh)
	ON_BN_CLICKED(IDC_AVERAGE, OnAverage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreshDlg message handlers

void CThreshDlg::OnChangeThresh() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CThreshDlg::OnAverage() 
{
	// TODO: Add your control notification handler code here
	
}
