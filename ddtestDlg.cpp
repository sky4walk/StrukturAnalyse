// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

// Hauptdialogfenster
// ddtestDlg.cpp : implementation file
//
#include "stdafx.h"
#include "ddtest.h"
#include "ddtestDlg.h"
#include "viewer.h"
//DBV-Funktionen
#include "globals.h"
#include "Matrix.h"
#include "Gauss2.h"
#include "sobel.h"
#include "spreiz.h"
#include "Schwellwert.h"
#include "houghtrafo.h"
//Dialoge
#include "ThreshDlg.h"
#include "ScaleDlg.h"
#include "SobelDlg.h"
#include "laplace.h"
#include "SpreizDlg.h"
#include "GaussDlg.h"
#include "LinesDlg.h"
#include "KreisDlg.h"
#include "Kreis2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

class LineDesc
{
public:
	unsigned long Pos;
	unsigned long Ang;
	int Marker;
};


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDdtestDlg dialog

CDdtestDlg::CDdtestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDdtestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDdtestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	NoDlg = 0;
}

void CDdtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDdtestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDdtestDlg, CDialog)
	//{{AFX_MSG_MAP(CDdtestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RAW, OnRaw)
	ON_BN_CLICKED(IDC_BMP, OnScale)
	ON_BN_CLICKED(IDC_GAUSS, OnGauss)
	ON_BN_CLICKED(IDC_SOBEL, OnSobel)
	ON_BN_CLICKED(IDC_SPREIZ, OnSpreiz)
	ON_BN_CLICKED(IDC_LINES, OnLines)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_THRESH, OnThresh)
	ON_BN_CLICKED(IDC_CIRCLE, OnCircle)
	ON_BN_CLICKED(IDC_CIRCLE2, OnCircle2)
	ON_BN_CLICKED(IDC_LAPLACE, OnLaplace)
	ON_BN_CLICKED(IDC_AUTOMATIK, OnAutomatik)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDdtestDlg message handlers

BOOL CDdtestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDdtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDdtestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDdtestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Bild in den DirectX Puffer schreiben
void CDdtestDlg::ZeigMal(Bitmap& bmp) 
{
	int x,y;
	int dx,dy;
	int res;
	int OK = 0;
	CViewer* pV = new CViewer();

	dx = bmp.GetDimX();
	dy = bmp.GetDimY();

	pV->Create(dx,dy);
	BYTE* p = pV->Lock();

	if(pV->m_nBPP==24)
	{
		res = pV->m_Pitch - dx * pV->m_nBPP / 8;

		for(y=0;y<dy;y++)
		{
			for(x=0;x<dx;x++)
			{
				*p++ = bmp.GetGreyColor(x,y);
				*p++ = bmp.GetGreyColor(x,y);
				*p++ = bmp.GetGreyColor(x,y);
			}
			for(x=0;x<res;x++) p++;
		}
		OK = 1;
	}
	if(pV->m_nBPP==32)
	{
		res = pV->m_Pitch - dx * pV->m_nBPP / 8;

		for(y=0;y<dy;y++)
		{
			for(x=0;x<dx;x++)
			{
				*p++ = bmp.GetGreyColor(x,y);
				*p++ = bmp.GetGreyColor(x,y);
				*p++ = bmp.GetGreyColor(x,y);
				*p++ = bmp.GetGreyColor(x,y);
			}
			for(x=0;x<res;x++) p++;
		}
		OK = 1;
	}
	pV->Unlock();

	if(OK)
		pV->Draw();
	else
		MessageBox("Geht in nur in 24Bit Farbtiefe");
}

// PGM oder BMP laden
void CDdtestDlg::OnRaw()
{
	CFileDialog fdlg(true,NULL,NULL,OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST,"Bitmap (*.BMP)|*.bmp|Raw(*.PGM) |*.pgm||",NULL);
	if(fdlg.DoModal()==IDOK)
	{
		CString fln = fdlg.GetFileName();
		int len = fln.GetLength();
		const char* temp = (LPCTSTR)fln;
		if((temp[len-1] == 'M')||(temp[len-1] == 'm'))
			bmp1.ReadPGM(temp);
		else
			bmp1.ReadBMP(temp);
		ZeigMal(bmp1);
	}
}

// Skalieren
void CDdtestDlg::OnScale() 
{
	CScaleDlg sdlg;
	sdlg.m_ScaleX = 200;
	sdlg.m_ScaleY = 200;
	sdlg.m_OrigX = bmp1.GetDimX();
	sdlg.m_OrigY = bmp1.GetDimY();

	int DlgRet;
	if(!NoDlg) DlgRet = sdlg.DoModal();
	if(DlgRet==IDOK||NoDlg)
	{
		if(bmp1.IsNull()) return;

		int Y = (int)((double)sdlg.m_ScaleX * (double)bmp1.GetDimY() / (double)bmp1.GetDimX());
		bmp1 = bmp1.Scale(sdlg.m_ScaleX,Y);
		ZeigMal(bmp1);
	}
}

// Gauss-Filter
void CDdtestDlg::OnGauss() 
{
	CGaussDlg gsdlg;
	gsdlg.m_GaussSize = 5;

	int DlgRet;
	if(!NoDlg) DlgRet = gsdlg.DoModal();
	if(DlgRet==IDOK||NoDlg)
	{
		if(bmp1.IsNull()) return;

		Gauss gs(gsdlg.m_GaussSize);
		bmp1 = gs.GetBlur(bmp1);
		ZeigMal(bmp1);
	}
}

// Sobelfilter
void CDdtestDlg::OnSobel() 
{
	CSobelDlg sobdlg;
	sobdlg.m_Thresh = 7;
	sobdlg.m_Optimal = false;

	int DlgRet;
	if(!NoDlg) DlgRet = sobdlg.DoModal();
	if(DlgRet==IDOK||NoDlg)
	{
		if(bmp1.IsNull()) return;
		
		SobelFilter sb(sobdlg.m_Optimal);
		sb.SetTreshHold(sobdlg.m_Thresh);
		sb.GetEdges(bmp1,EdgeForce,EdgeAngle);
		ZeigMal(EdgeForce);
		ZeigMal(EdgeAngle);
		bmp1 = EdgeForce;
	}
}

// Farben spreizen
void CDdtestDlg::OnSpreiz() 
{
	CSpreizDlg spdlg;
	spdlg.m_Spreiz = 10;

	int DlgRet;
	if(!NoDlg) DlgRet = spdlg.DoModal();
	if(DlgRet==IDOK||NoDlg)
	{
		if(bmp1.IsNull()) return;

		SpreizFilter sf;
		bmp1 = sf.filter(bmp1,spdlg.m_Spreiz);
		ZeigMal(bmp1);
	}
}

// Linien suchen
void CDdtestDlg::OnLines() 
{
	CLinesDlg lindlg;
	lindlg.m_Angels = 200;
	lindlg.m_Lot	= 200;
	lindlg.m_Thresh = 0;
	lindlg.m_DelRad = 18;
	lindlg.m_Lines  = 8;
	lindlg.m_Flt90Grad = true;

	int DlgRet;
	if(!NoDlg) DlgRet = lindlg.DoModal();
	if(DlgRet==IDOK||NoDlg)
	{
		if(bmp1.IsNull()) return;
	
		HoughTrafo ht;	
		Matrix<unsigned long> mathg;
		Vector<LineDesc> LinesVec;
		LineDesc DescTemp;
		int iMaxA = 0;
		int iMaxP = 0;
		int iLines = 0;
		int iCount;
		unsigned long ulMax;
		unsigned long drawMax = 0;
		Bitmap lines = bmp1;
		Bitmap hough;

		LinesVec.SetSize(lindlg.m_Lines);

		mathg = ht.TransLine(bmp1,lindlg.m_Angels,lindlg.m_Lot);
		hough = ht.DrawHough(mathg,255);
		ZeigMal(hough);

// bereits gefundene Linien aus dem Houghraum löschen und nächste suchen
		while(iLines<lindlg.m_Lines)
		{
			ulMax = ht.GetMax(mathg,iMaxA,iMaxP);
			if(ulMax>(unsigned long)lindlg.m_Thresh)
			{
				if(drawMax==0) drawMax=ulMax;
				ht.DelMax(mathg,iMaxA,iMaxP,lindlg.m_DelRad);
				DescTemp.Pos = iMaxP;
				DescTemp.Ang = iMaxA;
				DescTemp.Marker = 0;
				LinesVec.SetField(iLines,DescTemp);
				
// 90 Grad Filter
				if(lindlg.m_Flt90Grad)
				{
					int AngTol = 3;
					for(iCount=0;iCount<=iLines;iCount++)
					{	
						LineDesc equ;
						equ = LinesVec.GetField(iCount);
						int Alpha1 = (int)((double)(180 * DescTemp.Ang) / (double)mathg.GetDimX()) + 2*AngTol;
						int Alpha2 = (int)((double)(180 * equ.Ang) / (double)mathg.GetDimX()) + 2*AngTol;
						
						if( ((Alpha1+90)%180 <= (Alpha2 + AngTol/2)) &&
							((Alpha1+90)%180 >= (Alpha2 - AngTol/2)) )
						{
							DescTemp.Marker = 1;
							equ.Marker = 1;
							LinesVec.SetField(iCount,equ);
						}
					}
					LinesVec.SetField(iLines,DescTemp);
				}
			}
			else
			{
				DescTemp.Pos = 0;
				DescTemp.Ang = 0;
				DescTemp.Marker = 0;
				LinesVec.SetField(iLines,DescTemp);
			}
			iLines++;
		}

// Linien herausfiltern, die keine korrespondierende 90 Grad gedrehten Linie haben
		for(iLines=0;iLines<lindlg.m_Lines;iLines++)
		{
			DescTemp = LinesVec.GetField(iLines);
			if((DescTemp.Marker != 0)||(!lindlg.m_Flt90Grad))
				ht.DrawLine(lines,DescTemp.Ang,DescTemp.Pos,mathg);
		}

//Linien zeigen
		ZeigMal(lines);
	}
}

// Bild im PGM Format speichern
void CDdtestDlg::OnSave() 
{
	CFileDialog fdlg(false,NULL,"*.pgm",OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST,"Raw(*.PGM) |*.pgm||",NULL);
	if(fdlg.DoModal()==IDOK)
	{
		if(bmp1.IsNull()) return;

		CString fln = fdlg.GetFileName();
		bmp1.WritePGM((LPCTSTR)fln);
	}
}

// Schwellwert
void CDdtestDlg::OnThresh() 
{
	CThreshDlg ThDlg;
	ThDlg.m_Thresh = 128;
	ThDlg.m_Average = true;

	int DlgRet;
	if(!NoDlg) DlgRet = ThDlg.DoModal();
	if(DlgRet==IDOK||NoDlg)
	{
		if(bmp1.IsNull()) return;
	
		SchwellwertFilter swf;
		if(ThDlg.m_Average)
			bmp1 = swf.filter_average(bmp1);
		else
			bmp1 = swf.filter(bmp1,ThDlg.m_Thresh);
		ZeigMal(bmp1);
	}
}

// nach Kreise suchen Methode 1
void CDdtestDlg::OnCircle() 
{
	Bitmap tmpbmp = bmp1;
	CKreisDlg krdlg;
	krdlg.m_Radius	= 20;
	krdlg.m_Reso	= 10;
	krdlg.m_TolAng	= 3;
	krdlg.m_TolRad	= 30;

	int DlgRet;
	if(!NoDlg) DlgRet = krdlg.DoModal();
	if(DlgRet==IDOK||NoDlg)
	{
		if(bmp1.IsNull()) return;
		if(EdgeAngle.IsNull()) return;

		HoughTrafo ht;	
		Matrix<unsigned long> mathg;
		Bitmap hough;
		int iPosX = 0;
		int iPosY = 0;
		int iRadius = 0;
		unsigned long ulMax = 0;

// Mittelpunkt suchen
		mathg = ht.CircleMiddle(bmp1,EdgeAngle,krdlg.m_Radius,krdlg.m_TolRad,krdlg.m_TolAng,krdlg.m_Reso);
		ulMax = ht.GetMax(mathg,iPosX,iPosY);
		hough = ht.DrawHough(mathg,ulMax);
		ZeigMal(hough);

// Radius suchen
		Vector<unsigned long> Vec;
		Vec = ht.CircleRadius(bmp1,iPosX,iPosY);
		ulMax = ht.GetMax(Vec,iRadius);

		ht.DrawCircle(tmpbmp,iPosY,iPosX,iRadius);
		tmpbmp.SetGreyColor(iPosX,iPosY,255);
		ZeigMal(tmpbmp);
	}
}

// Kreise suchen Methode 2
void CDdtestDlg::OnCircle2() 
{
	Bitmap tmpbmp = bmp1;
	Kreis2Dlg krdlg;
	krdlg.m_Radius	= 50;
	krdlg.m_TolRad	= 5;
	krdlg.m_SizeX	= bmp1.GetDimX();
	krdlg.m_SizeY	= bmp1.GetDimY();

	int DlgRet;
	if(!NoDlg) DlgRet = krdlg.DoModal();
	if(DlgRet==IDOK||NoDlg)
	{
		if(bmp1.IsNull()) return;

		HoughTrafo ht;
		Bitmap hough;
		Matrix<unsigned long> mathg;
		unsigned long ulMax = 0;
		unsigned long ulTmp = 0;
		int iPosX = 0;
		int iPosY = 0;
		int iMaxPosX = 0;
		int iMaxPosY = 0;
		int iMaxRad = 0;
		int iCount;

		for(iCount = 0;iCount<krdlg.m_TolRad;iCount++)
		{
			mathg = ht.TransCircle(bmp1,krdlg.m_Radius+iCount-krdlg.m_TolRad/2,krdlg.m_SizeX,krdlg.m_SizeY);
			ulTmp = ht.GetMax(mathg,iPosX,iPosY);
			if(ulTmp>ulMax)
			{
				iMaxRad  = krdlg.m_Radius+iCount-krdlg.m_TolRad/2;
				iMaxPosX = iPosX * krdlg.m_SizeX / bmp1.GetDimX();
				iMaxPosY = iPosY * krdlg.m_SizeY / bmp1.GetDimY();
			}

			hough = ht.DrawHough(mathg,ulTmp);
			ZeigMal(hough);
		}
		ht.DrawCircle(tmpbmp,iMaxPosX,iMaxPosY,iMaxRad);
		tmpbmp.SetGreyColor(iMaxPosY,iMaxPosX,255);
		ZeigMal(tmpbmp);
	}
}

// Laplacefilter
void CDdtestDlg::OnLaplace() 
{
	if(!bmp1.IsNull())
	{
		LaplaceFilter lft;
		bmp1 = lft.Filter(bmp1);
		ZeigMal(bmp1);
	}
}

// Versuch einer automatischen Strukturanalyse
void CDdtestDlg::OnAutomatik()
{
	OnRaw();
	NoDlg = 1;
	OnScale();
	OnGauss();
	OnThresh();
	OnLaplace();
	OnCircle2();
	OnLines();
	NoDlg = 0;
}
