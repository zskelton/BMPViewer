#pragma once
#include <stdio.h>
#include <string.h>

class bmpobject
{
public:
	// Structures (char = 1, short = 2, int = 4, float = 4, double = 8 bytes)
	struct bmpheader
	{
		unsigned short bfType;
		unsigned int bfSize;
		unsigned short bfReserved1;
		unsigned short bfReserved2;
		unsigned int bfOffBits;
	};

	struct bmpinfoheader
	{
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
	
	struct imageinfo {
		int width;
		int height;
		unsigned int filesize;
		unsigned int datasize;
		unsigned char* data;
	};

	// Variables
	bmpheader header;
	bmpinfoheader infoheader;
	imageinfo info;
	bool error;
	char* errorMsg;

	// Constructor
	bmpobject();
	
	// Destructor
	~bmpobject();
	
	// Public Functions
	int load(char* filename);
	void save(char* filename);
	bool isError();
	void setError(bool flag, char* msg);
};



