/*
 * ExampleTexture.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "ExampleTexture.h"

#include "RenderLayout.hpp"
#include "RenderImage.h"

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

		Render::ImageLayout image_layout = {};
		image_layout.extent = { width, height, 1 };
		image_layout.usage = Render::ResourceUsage::GetImageUsage(false);
		image_layout.usage.binding.SampledImage = 1;
		image_layout.format = Render::Format::FORMAT_R8G8B8A8_UNORM;
		image_layout.type = Render::ImageType::IMAGE_TYPE_2D;

		auto manager = mSystem->GetTextureManager();

		std::string file_path = file;
		std::string file_name = file_path.substr(file_path.find_last_of("/\\") + 1);

		auto texture = manager->GetTexture(file_name.c_str());
		texture->Create(file_name.c_str(), image_layout);
		auto image = texture->GetImage();
		image->Upload(0, 0, bitmap);
	}
	else
	{
		std::cout << "Failure to Open File : " << file << std::endl;
	}
}

} /* namespace Example */
