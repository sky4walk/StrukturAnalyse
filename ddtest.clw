; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDdtestDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ddtest.h"
LastPage=0

ClassCount=12
Class1=CDdtestApp
Class2=CAboutDlg
Class3=CDdtestDlg
Class4=CViewer

ResourceCount=10
Resource1=IDD_GAUSS_DLG
Resource2=IDD_THRESH_DLG
Class5=CScaleDlg
Resource3=IDD_DEMO_DIALOG
Class6=CThreshDlg
Resource4=IDD_KREIS_DLG
Class7=CGaussDlg
Resource5=IDD_SCALE_DLG
Class8=CSpreizDlg
Resource6=IDD_LINES_DLG
Class9=CSobelDlg
Resource7=IDD_SOBEL_DLG
Class10=CLinesDlg
Resource8=IDD_SPREIZ_DLG
Class11=CKreisDlg
Resource9=IDD_ABOUTBOX
Class12=Kreis2Dlg
Resource10=IDD_KREIS2_DLG

[CLS:CDdtestApp]
Type=0
BaseClass=CWinApp
HeaderFile=ddtest.h
ImplementationFile=ddtest.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=ddtestDlg.cpp
ImplementationFile=ddtestDlg.cpp
LastObject=CAboutDlg

[CLS:CDdtestDlg]
Type=0
BaseClass=CDialog
HeaderFile=ddtestDlg.h
ImplementationFile=ddtestDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CDdtestDlg

[CLS:CViewer]
Type=0
BaseClass=CFrameWnd
HeaderFile=Viewer.h
ImplementationFile=Viewer.cpp
Filter=T
VirtualFilter=fWC
LastObject=CViewer

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_SCALE_DLG]
Type=1
Class=CScaleDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SCALE_X,edit,1350631552
Control4=IDC_SCALE_Y,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:CScaleDlg]
Type=0
HeaderFile=ScaleDlg.h
ImplementationFile=ScaleDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SCALE_X
VirtualFilter=dWC

[DLG:IDD_THRESH_DLG]
Type=1
Class=CThreshDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_THRESH,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_AVERAGE,button,1342242851

[CLS:CThreshDlg]
Type=0
HeaderFile=ThreshDlg.h
ImplementationFile=ThreshDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_THRESH
VirtualFilter=dWC

[DLG:IDD_GAUSS_DLG]
Type=1
Class=CGaussDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_GAUSSSIZE,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CGaussDlg]
Type=0
HeaderFile=GaussDlg.h
ImplementationFile=GaussDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CGaussDlg
VirtualFilter=dWC

[DLG:IDD_SPREIZ_DLG]
Type=1
Class=CSpreizDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SPREIZWERT,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CSpreizDlg]
Type=0
HeaderFile=SpreizDlg.h
ImplementationFile=SpreizDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSpreizDlg
VirtualFilter=dWC

[DLG:IDD_SOBEL_DLG]
Type=1
Class=CSobelDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SOBELTHRESH,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_OPTIMAL,button,1342242851

[CLS:CSobelDlg]
Type=0
HeaderFile=SobelDlg.h
ImplementationFile=SobelDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSobelDlg
VirtualFilter=dWC

[DLG:IDD_LINES_DLG]
Type=1
Class=CLinesDlg
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_ANGELS,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LOT,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_THRESH,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_DELRAD,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_LINES,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_FLT90GRAD,button,1342242851

[CLS:CLinesDlg]
Type=0
HeaderFile=LinesDlg.h
ImplementationFile=LinesDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_ANGTOL

[DLG:IDD_KREIS_DLG]
Type=1
Class=CKreisDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIUS,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_TOLRAD,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_TOLANG,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_RESO,edit,1350631552
Control10=IDC_STATIC,static,1342308352

[CLS:CKreisDlg]
Type=0
HeaderFile=KreisDlg.h
ImplementationFile=KreisDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DEMO_DIALOG]
Type=1
Class=CDdtestDlg
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDC_RAW,button,1342242816
Control3=IDC_BMP,button,1342242816
Control4=IDC_GAUSS,button,1342242816
Control5=IDC_SOBEL,button,1342242816
Control6=IDC_SPREIZ,button,1342242816
Control7=IDC_LAPLACE,button,1342242816
Control8=IDC_CIRCLE,button,1342242816
Control9=IDC_SAVE,button,1342242816
Control10=IDC_THRESH,button,1342242816
Control11=IDC_LINES,button,1342242816
Control12=IDC_CIRCLE2,button,1342242816
Control13=IDC_AUTOMATIK,button,1342242816

[DLG:IDD_KREIS2_DLG]
Type=1
Class=Kreis2Dlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIUS,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_TOLRAD,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_SIZE_X,edit,1350631552
Control8=IDC_SIZE_Y,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352

[CLS:Kreis2Dlg]
Type=0
HeaderFile=Kreis2Dlg.h
ImplementationFile=Kreis2Dlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIUS
VirtualFilter=dWC

