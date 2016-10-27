// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

#if !defined(AFX_THRESHDLG_H__3E617120_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_)
#define AFX_THRESHDLG_H__3E617120_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThreshDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CThreshDlg dialog

class CThreshDlg : public CDialog
{
// Construction
public:
	CThreshDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CThreshDlg)
	enum { IDD = IDD_THRESH_DLG };
	int		m_Thresh;
	BOOL	m_Average;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreshDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CThreshDlg)
	afx_msg void OnChangeThresh();
	afx_msg void OnAverage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THRESHDLG_H__3E617120_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_)
