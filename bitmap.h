// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de

// Bitmap-Klasse

#include <stdio.h>
#include "Matrix.h"

#ifndef BITMAP
#define BITMAP

class Bitmap : Matrix<unsigned char>
{
public:
  Bitmap();
  Bitmap(const Bitmap& bmp);
  Bitmap(const char* Filename);
  Bitmap(int iWidth, int iHeight);
  ~Bitmap();
  void NeuesBild(int iWidth,int iHeight);
  int ReadBMP(const char* pcFileName);
  int ReadPGM(const char* pcFileName);
  int WritePGM(const char* pcFileName);
  int GetDimX() const;
  int GetDimY() const;
  unsigned char GetGreyColor(int iXPos,int iYPos);
  void SetGreyColor(int iXPos,int iYPos,unsigned char ucCol);
  Bitmap& operator=(const Bitmap& bmp);
  Bitmap GetGreyAoi(int iOffsetX,int iOffsetY,int iSizeX,int iSizeY);
  Bitmap Scale(int iXSize,int iYSize);
  int IsNull();
protected:
  void copy(const Bitmap &bmp);
  void set_pixel(unsigned char* buffer,int byte,int* colortable);
  int ReadShort(FILE* fp,int* ret);
  int ReadLong(FILE* fp,int* ret);
  unsigned char* m_Data;          
  unsigned char* m_pucData;
  int            m_iWidth;
  int            m_iHeight;
  int			 m_iBpp;
};

#endif