#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

// Structures (char = 1, short = 2, int = 4, float = 4, double = 8 bytes)
#pragma pack(push,1)
struct bmpheader {
	unsigned short bfType;
	unsigned int bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned int bfOffBits;
};
#pragma pack(pop)


#pragma pack(push,1)
struct bmpinfoheader {
	unsigned int biSize;
	int biWidth;
	int biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned int biCompression;
	unsigned int biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	unsigned int biClrUsed;
	unsigned int biClrImportant;
};
#pragma pack(pop)

#pragma pack(push,1)
struct colortable {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char reserved;
};
#pragma pack(pop)

#pragma pack(push,1)
struct imageinfo {
	int width = 0;
	int height = 0;
	unsigned int filesize = 0;
	unsigned int datasize = 0;
	unsigned char* data = NULL;
};
#pragma pack(pop)

class bmpobject
{
public:
	// Variables
	bmpheader header;
	bmpinfoheader infoheader;
	colortable colors;
	imageinfo info;
	bool error;
	char* errorMsg;

	// Constructor
	bmpobject();
	
	// Destructor
	~bmpobject();
	
	// Public Functions
	int load(const char* filename);
	void save(const char* filename);
	bool isError();
	void setError(bool flag, char* msg);
};



