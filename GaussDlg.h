// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

#if !defined(AFX_GAUSSDLG_H__3E617121_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_)
#define AFX_GAUSSDLG_H__3E617121_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GaussDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGaussDlg dialog

class CGaussDlg : public CDialog
{
// Construction
public:
	CGaussDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGaussDlg)
	enum { IDD = IDD_GAUSS_DLG };
	int		m_GaussSize;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaussDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGaussDlg)
	afx_msg void OnChangeSize();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAUSSDLG_H__3E617121_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_)
