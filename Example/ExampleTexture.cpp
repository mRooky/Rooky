/*
 * ExampleTexture.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "ExampleTexture.h"
#include <FreeImage.h>

#include <iostream>

namespace Example
{

Texture::Texture(void)
{
}

Texture::~Texture(void)
{
}

void Texture::Initialize(void)
{
	Buffer::Initialize();
	CreateTexture("Resource/vulkan.png");
}

void Texture::CreateTexture(const char* file)
{
	FreeImage_Initialise(TRUE);
	FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(file);
	if (fif == FIF_UNKNOWN)
	{
		fif = FreeImage_GetFIFFromFilename(file);
	}

	if (fif != FIF_UNKNOWN)
	{
		BOOL support = FreeImage_FIFSupportsReading(fif);
		if (support)
		{
			FIBITMAP *bimap = FreeImage_Load(fif, file);
			int Width = FreeImage_GetWidth(bimap);
			int Height = FreeImage_GetHeight(bimap);
			int ByteWidth = FreeImage_GetLine(bimap);
			std::cout << "FreeImage BPP : " << FreeImage_GetBPP(bimap) << std::endl;
			std::cout << "FreeImage ImageType : " << FreeImage_GetImageType(bimap) << std::endl;
			std::cout << "FreeImage ColorsUsed : " << FreeImage_GetColorsUsed(bimap) << std::endl;
			std::cout << "FreeImage Layout : " << Width << " " << Height << " " << ByteWidth << std::endl;
			std::cout << "FreeImage DIBSize : " << FreeImage_GetDIBSize(bimap) << std::endl;
			FreeImage_Unload(bimap);
			bimap = nullptr;
		}
	}
	FreeImage_DeInitialise();
}

} /* namespace Example */
