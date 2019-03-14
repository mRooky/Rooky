/*
 * ExampleTexture.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "ExampleTexture.h"

#include "CoreTextureManager.h"
#include "CoreTexture.h"

#include <iostream>
#include <cassert>

#include <SOIL/SOIL.h>

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
	CreateTexture("Resource/vulkan2.png");
}

void Texture::CreateTexture(const char* file)
{
	int width, height, channels;
	uint8_t * bitmap = SOIL_load_image(file, &width, &height, &channels, SOIL_LOAD_RGBA);
	if (bitmap != nullptr)
	{
		assert(channels == 4);
		std::cout << "Width " << width << std::endl;
		std::cout << "Height " << height << std::endl;
		std::cout << "Channels " << channels << std::endl;
		Render::Format format = Render::Format::FORMAT_R8G8B8A8_UNORM;

		std::string file_path = file;
		std::string file_name = file_path.substr(file_path.find_last_of("/\\") + 1);
		Render::Extent3 extent = { width, height, 1 };
		mTexture = mSystem->CreateTexture2D(file_name.c_str(), extent, format);
		mTexture->Update(0, 0, bitmap);
		SOIL_free_image_data(bitmap);
	}
	else
	{
		std::cout << "Failure to Open File : " << file << std::endl;
	}
}

} /* namespace Example */
