/*
 * ExampleTexture.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "ExampleTexture.h"

#include "CorePass.h"
#include "CoreTexture.h"

#include "CoreTextureManager.h"
#include "CoreBufferManager.h"
#include "CoreTextureManager.h"
#include "CoreBindingManager.h"
#include "CorePipelineManager.h"

#include "UtilString.h"

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
	CreateWindow("Texture Window");
	CreateSystem();
	CreateViewport();
	CreateRenderPath();
	CreateRenderPass();
	CreateFrameBuffer();
	CreateShader();
	CreateRenderThread(2);
	CreateIndexBuffer();
	CreateVertexBuffer();
	CreateUniformBuffer();
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
		std::string file_name = Util::GetFileName(file);
		Render::Extent3D extent = { width, height, 1 };

		auto manager = mSystem->GetTextureManager();
		mTexture = manager->CreateTexture2D(file_name.c_str(), extent, format);
		mTexture->Update(0, 0, bitmap);

		auto pass = mPath->GetRenderPass(0);
		pass->SetTexture(mTexture);
		SOIL_free_image_data(bitmap);
	}
	else
	{
		std::cout << "Failure to Open File : " << file << std::endl;
	}
}

void Texture::CreateShader(void)
{
	const char* vert_file = "Resource/texture.vert";
	const char* frag_file = "Resource/texture.frag";

	auto pass = mPath->GetRenderPass(0);
	auto shader_state = pass->GetShaderState();

	auto manager = mSystem->GetPipelineManager();
	auto vert_shader = manager->GetShader(vert_file);
	shader_state->SetShader(vert_shader);
	auto frag_shader = manager->GetShader(frag_file);
	shader_state->SetShader(frag_shader);
}

void Texture::CreatePipeline(void)
{

}

} /* namespace Example */
