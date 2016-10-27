// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

// ddtestDlg.h : header file
//


#if !defined(AFX_DDTESTDLG_H__905F7A02_4097_4BE9_9735_062A57678725__INCLUDED_)
#define AFX_DDTESTDLG_H__905F7A02_4097_4BE9_9735_062A57678725__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDdtestDlg dialog

#include "bitmap.h"

class CDdtestDlg : public CDialog
{
// Construction
public:
	CDdtestDlg(CWnd* pParent = NULL);	// standard constructor
	void ZeigMal(Bitmap& bmp);

// Dialog Data
	//{{AFX_DATA(CDdtestDlg)
	enum { IDD = IDD_DDTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDdtestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	int NoDlg;

	Bitmap bmp1;
	Bitmap EdgeForce;
	Bitmap EdgeAngle;
	// Generated message map functions
	//{{AFX_MSG(CDdtestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRaw();
	afx_msg void OnScale();
	afx_msg void OnGauss();
	afx_msg void OnSobel();
	afx_msg void OnSpreiz();
	afx_msg void OnLines();
	afx_msg void OnSave();
	afx_msg void OnThresh();
	afx_msg void OnCircle();
	afx_msg void OnCircle2();
	afx_msg void OnLaplace();
	afx_msg void OnAutomatik();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDTESTDLG_H__905F7A02_4097_4BE9_9735_062A57678725__INCLUDED_)
