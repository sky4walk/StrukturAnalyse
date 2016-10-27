// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

#if !defined(AFX_SPREIZDLG_H__3E617122_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_)
#define AFX_SPREIZDLG_H__3E617122_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpreizDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpreizDlg dialog

class CSpreizDlg : public CDialog
{
// Construction
public:
	CSpreizDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSpreizDlg)
	enum { IDD = IDD_SPREIZ_DLG };
	int		m_Spreiz;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpreizDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSpreizDlg)
	afx_msg void OnChangeSpreizwert();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPREIZDLG_H__3E617122_6240_11D5_B05E_CB6AC1DEED58__INCLUDED_)
