// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

#if !defined(AFX_SOBELDLG_H__3E617123_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_)
#define AFX_SOBELDLG_H__3E617123_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SobelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSobelDlg dialog

class CSobelDlg : public CDialog
{
// Construction
public:
	CSobelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSobelDlg)
	enum { IDD = IDD_SOBEL_DLG };
	int		m_Thresh;
	BOOL	m_Optimal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSobelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSobelDlg)
	afx_msg void OnChangeSobelthresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOBELDLG_H__3E617123_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_)
