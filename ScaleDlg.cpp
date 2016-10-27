// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

// ScaleDlg.cpp : implementation file
// Skalierungseingabe

#include "stdafx.h"
#include "ddtest.h"
#include "ScaleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScaleDlg dialog


CScaleDlg::CScaleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScaleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScaleDlg)
	m_ScaleX = 0;
	m_ScaleY = 0;
	//}}AFX_DATA_INIT
}


void CScaleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScaleDlg)
	DDX_Text(pDX, IDC_SCALE_X, m_ScaleX);
	DDV_MinMaxInt(pDX, m_ScaleX, 1, 512);
	DDX_Text(pDX, IDC_SCALE_Y, m_ScaleY);
	DDV_MinMaxInt(pDX, m_ScaleY, 1, 512);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScaleDlg, CDialog)
	//{{AFX_MSG_MAP(CScaleDlg)
	ON_EN_CHANGE(IDC_SCALE_X, OnChangeScaleX)
	ON_EN_CHANGE(IDC_SCALE_Y, OnChangeScaleY)
	ON_EN_UPDATE(IDC_SCALE_X, OnUpdateScaleX)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScaleDlg message handlers

void CScaleDlg::OnChangeScaleX() 
{
	m_ScaleY = m_OrigY * m_ScaleX / m_OrigX;
}

void CScaleDlg::OnChangeScaleY() 
{
	m_ScaleY = m_OrigY * m_ScaleX / m_OrigX;
}

void CScaleDlg::OnUpdateScaleX() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	
}
