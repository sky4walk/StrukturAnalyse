// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

#if !defined(AFX_KREIS2DLG_H__60FDA3C0_6597_11D5_B05E_99D18AB43836__INCLUDED_)
#define AFX_KREIS2DLG_H__60FDA3C0_6597_11D5_B05E_99D18AB43836__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Kreis2Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Kreis2Dlg dialog

class Kreis2Dlg : public CDialog
{
// Construction
public:
	Kreis2Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Kreis2Dlg)
	enum { IDD = IDD_KREIS2_DLG };
	int		m_Radius;
	int		m_TolRad;
	int		m_SizeX;
	int		m_SizeY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Kreis2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Kreis2Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KREIS2DLG_H__60FDA3C0_6597_11D5_B05E_99D18AB43836__INCLUDED_)
