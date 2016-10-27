// (C) 2001 by 
// Manfred Lippert mani@mani.de
// Andre Betz andre.betz@gmx.de
#include <stdlib.h>
#include "bitmap.h"

// Bitmap-Klasse
#define BMP_HEADER ('B' + ('M' << 8))
#define BMP_RGB                  0 
#define BMP_RLE8                 1
#define BMP_RLE4                 2
#define BMP_BITFIELDS            3

typedef struct 
{
  unsigned int magic;
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  unsigned long value;
} IColorP;

Bitmap::Bitmap()
{
  m_iHeight = 0;
  m_iWidth  = 0;
  m_pucData = NULL;
}

Bitmap::Bitmap(const Bitmap& bmp)
{
  m_iHeight = 0;
  m_iWidth  = 0;
  m_pucData = NULL;
  copy(bmp);
}

Bitmap::Bitmap(const char* pcFileName)
{
  m_pucData = NULL;
  ReadBMP(pcFileName);
}

Bitmap::Bitmap(int iWidth,int iHeight)
{
  m_pucData = NULL;
  NeuesBild(iWidth,iHeight);
}

Bitmap::~Bitmap()
{
  delete m_pucData;
}

Bitmap& Bitmap::operator=(const Bitmap& bmp)
{
  if(&bmp==this) return *this;
  copy(bmp);
  return *this;
}

void Bitmap::copy(const Bitmap &bmp)
{
  int iDimX = bmp.GetDimX();
  int iDimY = bmp.GetDimY();

  NeuesBild(iDimX,iDimY);
  for(int iCount=0;iCount<iDimY*iDimX*3;iCount++)
  {
    m_pucData[iCount] = bmp.m_pucData[iCount];
  }
}

// erzeugt ein neues Bild
void Bitmap::NeuesBild(int iWidth,int iHeight)
{
  if(m_pucData!=NULL) delete m_pucData;

//  Matrix<unsigned char>::
  m_iWidth  = iWidth;
  m_iHeight = iHeight;
  SetSize(m_iWidth,m_iHeight);
  m_pucData = new unsigned char[m_iWidth * m_iHeight * 3];
  for(int iCount=0;iCount<m_iWidth*m_iHeight*3;iCount++)
  {
    m_pucData[iCount] = 0;
  }
}

void Bitmap::set_pixel(unsigned char* buffer,int byte,int* colortable)
{
  do 
  {
    *(buffer+0) = (unsigned char)(colortable[byte&0xff]&(0xff<<16))>>16;
    *(buffer+1) = (unsigned char)(colortable[byte&0xff]&(0xff<<8))>>8;  
    *(buffer+2) = (unsigned char)(colortable[byte&0xff]&(0xff<<0))>>0;
  }while(0);
}                                                      

int Bitmap::ReadShort(FILE* fp,int* ret)
{
  int c = fgetc(fp);
  if (c == EOF) return 0;
  *ret = (c&0xff);
  c = fgetc(fp);
  if (c == EOF) return 0;
  *ret |= (c&0xff) << 8;
  return 1;
}

int Bitmap::ReadLong(FILE* fp,int* ret)
{
  int c = fgetc(fp);
  if (c == EOF) return 0;
  *ret = (c&0xff);
  c = fgetc(fp);
  if (c == EOF) return 0;
  *ret |= (c&0xff) << 8;
  c = fgetc(fp);
  if (c == EOF) return 0;
  *ret |= (c&0xff) << 16;
  c = fgetc(fp);
  if (c == EOF) return 0;
  *ret |= (c&0xff) << 24;
  return 1;
}

// liest Bilder im Bitmap-Format ein
int Bitmap::ReadBMP(const char* pcFileName)
{
  FILE* fp;
  fp = fopen(pcFileName,"rb");

  int scratch, fileSize, offset,depth, compression,
      imagesize, xpelspermeter, ypelspermeter, colorsused, colorsimportant;
  int redmask, greenmask, bluemask,
      redshift, greenshift, blueshift,
      redbits, greenbits, bluebits;
  int *colortable = NULL;

  if (!ReadShort(fp, &scratch) || scratch != BMP_HEADER) return 2;
  if (!ReadLong(fp, &fileSize))                          return 2;
  if (!ReadShort(fp, &scratch) || scratch != 0)          return 2;
  if (!ReadShort(fp, &scratch) || scratch != 0)          return 2;
  if (!ReadLong(fp, &offset))                            return 2;
  if (!ReadLong(fp, &scratch) || scratch != 40)          return 2;
  if (!ReadLong(fp, &m_iWidth))                          return 2;
  if (!ReadLong(fp, &m_iHeight))                         return 2;
  if (!ReadShort(fp, &scratch) || scratch != 1)          return 2;
  if (!ReadShort(fp, &depth))                            return 2;
  if (!ReadLong(fp, &compression))                       return 2;
  if (!ReadLong(fp, &imagesize))                         return 2;
  if (!ReadLong(fp, &xpelspermeter))                     return 2;
  if (!ReadLong(fp, &ypelspermeter))                     return 2;
  if (!ReadLong(fp, &colorsused))                        return 2;
  if (!ReadLong(fp, &colorsimportant))                   return 2;

  if(compression==BMP_BITFIELDS) 
  {
    if (!ReadLong(fp,&redmask)) return 1;
    for (redshift = 0; !(redmask&(1<<redshift)) && redshift<32; redshift++);
    for (redbits = 0; (redmask&(1<<(redshift+redbits))) && redshift<32; redbits++);
    if (!ReadLong(fp,&greenmask)) return 1;
    for (greenshift = 0; !(greenmask&(1<<greenshift)) && greenshift<32; greenshift++);
    for (greenbits = 0; (greenmask&(1<<(greenshift+greenbits))) && greenshift<32; greenbits++);
    if (!ReadLong(fp,&bluemask)) return 1;
    for (blueshift = 0; !(bluemask&(1<<blueshift)) && blueshift<32; blueshift++);
    for (bluebits = 0; (bluemask&(1<<(blueshift+bluebits))) && blueshift<32; bluebits++);
  }

  NeuesBild(m_iWidth,m_iHeight);
  m_iBpp = depth;

  if (depth <= 8) 
  {
    if (!colorsused) colorsused = 2<<depth;
    colortable = new int[colorsused];
    for (scratch = 0; scratch < colorsused; scratch++) 
    {
      if (!ReadLong(fp,(colortable+scratch))) return 2;
    }
  }

  if (fseek(fp, offset, SEEK_SET) < 0) return 2;

  if (depth == 24 && compression == BMP_RGB) 
  {
    int x, y, z, tmp;
	int npad = (imagesize / m_iHeight) - m_iWidth * 3;

    for (y = m_iHeight - 1; y >= 0; y--) 
    {
		for (x = 0; x < m_iWidth; x++) 
		{
			int r,g,b;
			r = fgetc(fp); 
			g = fgetc(fp); 
			b = fgetc(fp);

			if (r == EOF || g == EOF || b == EOF) return 2;
			*(m_pucData + (y*3*m_iWidth) + (x*3))     = b;
			*(m_pucData + (y*3*m_iWidth) + (x*3) + 1) = g;
			*(m_pucData + (y*3*m_iWidth) + (x*3) + 2) = r;
		}
		for(z=0;z<npad;z++)
		{
			tmp = fgetc(fp);
		}
    }
  }
  else if (depth == 16 && compression == BMP_BITFIELDS) 
  {
    int x, y;
    for (y = m_iHeight - 1; y >= 0; y--) 
    {
      for (x = 0; x < m_iWidth; x++) 
      {
        unsigned char *pixel = m_pucData + (y*3*m_iWidth) + (x*3);
        int color;
        if (!ReadShort(fp, &color)) return 2;
        *(pixel + 0) = (((color&redmask)>>redshift)<<8)>>redbits;
        *(pixel + 1) = (((color&greenmask)>>greenshift)<<8)>>greenbits;
        *(pixel + 2) = (((color&bluemask)>>blueshift)<<8)>>bluebits;
      }
    }
  }
  else if (depth == 8 && compression == BMP_RGB) 
  {
    int x, y;
    for (y = m_iHeight - 1; y >= 0; y--) 
    {
      for (x = 0; x < m_iWidth; x++) 
      {
        unsigned char *pixel = m_pucData + (y*m_iWidth*3)+(x*3);
        int byte = fgetc(fp); 
        if (byte == EOF) return 2;
        set_pixel(pixel,byte,colortable);
      }
    }

  } 
  else if (depth <= 8 && compression) 
  {
    int byte, count, x, y;
    unsigned char *buffer = m_pucData+m_iWidth*(m_iHeight-1)*3;
    for (y = 0; y < m_iHeight; ) 
    {
      count = fgetc(fp);
      if (count == EOF) return 2;
      if (count != 0) 
      {
        byte = fgetc(fp); if (byte == EOF) return 2;
        for (scratch = 0; scratch < count; scratch++) 
        {
          if (compression == 1) 
          {
            set_pixel(buffer,byte,colortable);
          }
          else 
          {
            int thisbyte = (scratch & 0x01) ? (byte & 0x0f) : ((byte >> 4) & 0x0f);
            set_pixel(buffer,byte,colortable);
          }
          buffer += 3;
        }
      }
      else 
      {
        count = fgetc(fp);
        if (count == EOF) return 2;
        if (count == 0x01) break;
        switch (count) 
        {
        case 0x00:
          y++;
          buffer = m_pucData+m_iWidth*(m_iHeight-y-1)*3;
          break;
        case 0x02: 
          x = fgetc(fp);
          y = fgetc(fp);
          if (x == EOF || y == EOF) return 2;
          buffer = m_pucData+m_iWidth*(m_iHeight-y-1)*3+(x*3);
          break;
        default: 
          for (scratch = 0; scratch < count; scratch++) 
          {
            byte = fgetc(fp); if (byte == EOF) return 2;
            if (compression == 1) 
            {
              set_pixel(buffer,byte,colortable);
            }
            else 
            {
              int thisbyte = (scratch & 0x01) ? (byte & 0x0f) : ((byte >> 4) & 0x0f);
              set_pixel(buffer,byte,colortable);
            }
            buffer += 3;
          }
          if (compression == 1) 
          {
            if (count & 0x01) 
            {
              (void)fgetc(fp);
            }
          }
          else if ((count & 0x03) == 1 || ((count & 0x03) == 2)) 
          {
            (void)fgetc(fp);
          }
          break;
        }
      }
    }
  }
  else 
  {
    delete m_pucData;
    return 2;
  }

  fclose(fp);
  if(colortable) delete colortable;
  return 0;
}

// schreibt Bilder im PGM-Format
int Bitmap::WritePGM(const char* pcFileName)
{
	if(!IsNull())
	{
		FILE* wr;
		unsigned char ucAvrgRGB;

		if(GetDimX()==0 || GetDimY()==0) return 1;

		wr = fopen(pcFileName,"wb");
		fprintf(wr,"P5\n");
		fprintf(wr,"%d\n",m_iWidth); 
		fprintf(wr,"%d\n",m_iHeight);
		fprintf(wr,"%d\n",255);

		for(int iYCount=0;iYCount<GetDimY();iYCount++)
		{
			for(int iXCount=0;iXCount<GetDimX();iXCount++)
			{
				ucAvrgRGB = GetGreyColor(iXCount,iYCount);
				fwrite(&ucAvrgRGB,1,1,wr);
			}
		}
		fclose (wr);

		return 0;
	}
	return 1;
}

// liefert Größe in X-Richtung
int Bitmap::GetDimX() const
{
  return m_iWidth;
}

// liefert Größe in Y-Richtung
int Bitmap::GetDimY() const
{
  return m_iHeight;
}

// liefert Farbwert an der x,y-Position
unsigned char Bitmap::GetGreyColor(int iXPos,int iYPos)
{
  unsigned char ucAvrgRGB,ucR,ucG,ucB;

  if((iXPos<m_iWidth)&&(iYPos<m_iHeight)&&(iXPos>=0)&&(iYPos>=0))
  {
    ucR = m_pucData[(iXPos+iYPos*m_iWidth)*3];  
    ucG = m_pucData[(iXPos+iYPos*m_iWidth)*3+1];
    ucB = m_pucData[(iXPos+iYPos*m_iWidth)*3+2];

//	ucAvrgRGB = (unsigned char)(0,299 * (double)ucR + 0,587 * (double)ucG + 0,114 * (double)ucB);
    ucAvrgRGB = (unsigned char)((ucR + ucG +ucB) / 3);

    return ucAvrgRGB;
  }

  return 0;
}

// setzt Farbwert an der x,y-Position
void Bitmap::SetGreyColor(int iXPos,int iYPos,unsigned char ucCol)
{
  if((iXPos<m_iWidth)&&(iYPos<m_iHeight))
  {
    m_pucData[(iXPos+iYPos*m_iWidth)*3]   = ucCol;  
    m_pucData[(iXPos+iYPos*m_iWidth)*3+1] = ucCol;
    m_pucData[(iXPos+iYPos*m_iWidth)*3+2] = ucCol;
  }
}

int Bitmap::ReadPGM(const char* pcFileName)
{
	char s[10];
	char t[10];
	char c;

	FILE* fp;
    fp = fopen(pcFileName,"rb");

	fscanf(fp,"%s",s);
	if (s[0]!='P') return 0;
	c=fgetc(fp);
	c=fgetc(fp);
	while(c=='#')  
	{ 
		if(c=='#') 
			while(c!=10)
		{
			c=fgetc(fp);
		}
		c=fgetc(fp); 
	}
 
	fscanf(fp,"%s",s);
	sprintf(t,"%c%s",c,s);
	m_iWidth = atoi(t);
	fscanf(fp,"%s",s);
	m_iHeight = atoi(s);
	fscanf(fp,"%s",s);
	m_iBpp = atoi(s);

	NeuesBild(m_iWidth,m_iHeight);
    
	for(int iCountY=0;iCountY<GetDimY();iCountY++) 
	{
		for(int iCountX=0;iCountX<GetDimX();iCountX++) 
		{
			SetGreyColor(iCountX,iCountY,fgetc(fp));
		}
	}

	fclose(fp);
	return 1;
}

// liefert einen Ausschnitt aus einem Bild
Bitmap Bitmap::GetGreyAoi(int iOffsetX,int iOffsetY,int iSizeX,int iSizeY)
{
	Bitmap xBmp;
	int iCountX;
	int iCountY;

	xBmp.NeuesBild(iSizeX,iSizeY);
	
	for(iCountY=0;iCountY<iSizeY;iCountY++) 
	{
		for(iCountX=0;iCountX<iSizeX;iCountX++) 
		{
			unsigned char ucTmp;
			int iXPos = (iOffsetX+iCountX)%m_iWidth;
			int iYPos = (iOffsetY+iCountY)%m_iHeight;
			if(iXPos<0) iXPos += m_iWidth;
			if(iYPos<0) iYPos += m_iHeight;
			ucTmp = GetGreyColor(iXPos,iYPos);
			xBmp.SetGreyColor(iCountX,iCountY,ucTmp);
		}
	}

	return xBmp;
}

/*
Bitmap Bitmap::Scale(int iXSize,int iYSize) 
{
	int half_dimx = iXSize >> 1;
	int half_dimy = iYSize >> 1;
	int sx, sy;
	int x, y;
	unsigned char pixel;
	Bitmap dst(iXSize,iYSize);

	for(y=0;y<iYSize;y++) 
	{
		for(x=0;x<iXSize;x++) 
		{
			sx = (x * GetDimX() + half_dimx) / iXSize;
			sy = (y * GetDimY() + half_dimy) / iYSize;
			pixel = GetGreyColor(sx,sy);
			dst.SetGreyColor(x,y,pixel);
		}
	}
	return dst;
}
  */

// liefert ein skaliertes Bild
Bitmap Bitmap::Scale(int iXSize,int iYSize) 
{
	int x, y;									// Pixelposition im Zielbild
	int sx1, sy1;								// Anfangs-Pixelposition im Quellbild
	int sx2, sy2;								// Ende-Pixelposition im Quellbild
	int sx3, sy3;
	int sx, sy;
	long sum;
	int count, half_count;
	Bitmap dst(iXSize,iYSize);

	int bx = GetDimX() / dst.GetDimX();	// Bresenham Anteile
	int rx = GetDimX() % dst.GetDimX();	// Bresenham Rest
	int fx = 0;									// Bresenham Summe
	int by = GetDimY() / dst.GetDimY();	// Bresenham Anteile
	int ry = GetDimY() % dst.GetDimY();	// Bresenham Rest
	int fy = 0;									// Bresenham Summe

	sy1 = 0;
	sy2 = 0;
	for(y = 0; y < dst.GetDimY(); y++) {

		// Bresenham in Y-Richtung:
		sy2 += by;
		if ((fy += ry) >= dst.GetDimY()) {
			fy -= dst.GetDimY();
			sy2++;
		}

		sy3 = sy2;
		if (sy3 == sy1) {	// verhindern, dass "kein" Quellpixel genommen wird (kommt beim Vergrš§ern vor)
			sy3++;
		}

		sx1 = 0;
		sx2 = 0;
		for(x = 0; x < dst.GetDimX(); x++) {

			// Bresenham in X-Richtung:
			sx2 += bx;
			if ((fx += rx) >= dst.GetDimX()) {
				fx -= dst.GetDimX();
				sx2++;
			}

			sx3 = sx2;
			if (sx3 == sx1) {	// verhindern, dass "kein" Quellpixel genommen wird (kommt beim Vergrš§ern vor)
				sx3++;
			}

			sum = 0;
			count = 0;
			for(sy = sy1; sy < sy3; sy++) {
				for(sx = sx1; sx < sx3; sx++) {			// Alle zum Zielpixel gehšrigen Quellpixel ...
					sum += GetGreyColor(sx,sy);			// ... auslesen und aufsummieren ...
					count++;
				}
			}

			half_count = (count >> 1);
			dst.SetGreyColor(x,y,(unsigned char)((sum + half_count)/count));

			sx1 = sx2;	// Ende-Pixelposition wird neue Anfangs-Pixelposition
		}
		sy1 = sy2;		// Ende-Pixelposition wird neue Anfangs-Pixelposition
	}

	return dst;
}

int Bitmap::IsNull()
{
	if(m_pucData!=NULL)	return 0;
	else				return 1;
}
