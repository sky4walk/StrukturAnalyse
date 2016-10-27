// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

#if !defined(AFX_KREISDLG_H__5B90BD60_626C_11D5_B05E_895C51AEE539__INCLUDED_)
#define AFX_KREISDLG_H__5B90BD60_626C_11D5_B05E_895C51AEE539__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KreisDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKreisDlg dialog

class CKreisDlg : public CDialog
{
// Construction
public:
	CKreisDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CKreisDlg)
	enum { IDD = IDD_KREIS_DLG };
	int		m_Radius;
	int		m_TolAng;
	int		m_TolRad;
	int		m_Reso;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKreisDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CKreisDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KREISDLG_H__5B90BD60_626C_11D5_B05E_895C51AEE539__INCLUDED_)
