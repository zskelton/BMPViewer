#include "bmpobject.h"

// Constructor
bmpobject::bmpobject() {
	return;
}

// Destructor
bmpobject::~bmpobject() {
	return;
}

// Public Functions
int bmpobject::load(const char* filename) {
	// Set File Pointer
	FILE* file = NULL;
	fopen_s(&file, filename, "rb");
	
	// Check if file exists
	if (file == NULL) {
		this->setError(true, (char *)"File does not exist");
		return -1;
	}

	// Read File Header
	fread(&this->header, sizeof(this->header), 1, file);
	
	// Check if file is a BMP file
	if (this->header.bfType != 0x4D42) {
		this->setError(true, (char *)"File is not a BMP file");
		return -2;
	}
	
	// Read DIB Header
	fread(&this->infoheader, sizeof(this->infoheader), 1, file);
	
	// Read Color Table
	fread(&this->colors, sizeof(this->colors), 1, file);

	// Read Image Data
	/*unsigned char* _data;
	fread(&_data, this->infoheader.biSizeImage, 1, file);*/

	// Test for Error
	if (ferror(file)) {
		this->setError(true, (char *)"Error reading file");
		return -3;
	}
	
	// Close File
	fclose(file);
	
	// Set Image Size
	this->info.width = this->infoheader.biWidth;
	this->info.height = this->infoheader.biHeight;
	this->info.filesize = this->header.bfSize;
	this->info.datasize = this->infoheader.biSizeImage;
	/*this->info.data = _data;*/
	return 0;
}

void bmpobject::save(const char* filename) {
	// Not used.
	return;
}

// Private Functions
void bmpobject::setError(bool flag, char* msg) {
	if (flag) {
		this->error = true;
		this->errorMsg = msg;
	} else {
		this->error = false;
		this->errorMsg = (char*)"";
	}
}

bool bmpobject::isError() {
	return error;
}

