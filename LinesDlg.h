// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

#if !defined(AFX_LINESDLG_H__F37AA220_624A_11D5_B05E_CB6AC1DEED58__INCLUDED_)
#define AFX_LINESDLG_H__F37AA220_624A_11D5_B05E_CB6AC1DEED58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LinesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLinesDlg dialog

class CLinesDlg : public CDialog
{
// Construction
public:
	CLinesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLinesDlg)
	enum { IDD = IDD_LINES_DLG };
	int		m_Angels;
	int		m_Lot;
	int		m_Thresh;
	int		m_DelRad;
	int		m_Lines;
	BOOL	m_Flt90Grad;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLinesDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINESDLG_H__F37AA220_624A_11D5_B05E_CB6AC1DEED58__INCLUDED_)
