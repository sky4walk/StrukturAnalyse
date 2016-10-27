// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

#include "bitmap.h"
#include "Matrix.h"

#ifndef HOUGH
#define HOUGH

class HoughTrafo
{
public:
	Matrix<unsigned long> TransLine(Bitmap& Bmp,int iXSize,int iYSize);
	Matrix<unsigned long> TransCircle(Bitmap& Bmp,int iRadius,int iXSize,int iYSize);
	Matrix<unsigned long> CircleMiddle(Bitmap& xEdgeFrc,Bitmap& xEdgeAng,int iRadius,int iTolRad,int TolAng,int iAngRes = 1);
	Vector<unsigned long> CircleRadius(Bitmap& xEdgeFrc,int iPosX,int iPosY);
	unsigned long GetMax(Matrix<unsigned long>& xHough,int& iMaxP,int& iMaxAlpha);
	unsigned long GetMax(Vector<unsigned long>& xHough,int& iMaxP);
	void DelMax(Matrix<unsigned long>& xHough,int iMaxAlpha,int iMaxP,int iDelSize = 5);
	Bitmap DrawHough(Matrix<unsigned long>& xHough,unsigned long ulMax);
	void DrawLine(Bitmap& bmp,int iMaxAlpha,int iMaxP,Matrix<unsigned long>& xHough);
	void DrawLine(Matrix<unsigned long>& xOrig,int iXStart,int iYStart,int iGrad,int iBegin,int iLength,int AngRes = 1);
	void DrawCircle(Bitmap& xOrig,int iXPos,int iYPos,int iRad);
protected:
	int Round(double dZ);
};

#endif