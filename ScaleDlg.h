// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

#if !defined(AFX_SCALEDLG_H__83069DA4_61C8_11D5_B05E_8EE077BE0E1E__INCLUDED_)
#define AFX_SCALEDLG_H__83069DA4_61C8_11D5_B05E_8EE077BE0E1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScaleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScaleDlg dialog

class CScaleDlg : public CDialog
{
// Construction
public:
	CScaleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScaleDlg)
	enum { IDD = IDD_SCALE_DLG };
	int		m_ScaleX;
	int		m_ScaleY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScaleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_OrigX;
	int m_OrigY;
protected:

	// Generated message map functions
	//{{AFX_MSG(CScaleDlg)
	afx_msg void OnChangeScaleX();
	afx_msg void OnChangeScaleY();
	afx_msg void OnUpdateScaleX();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCALEDLG_H__83069DA4_61C8_11D5_B05E_8EE077BE0E1E__INCLUDED_)
