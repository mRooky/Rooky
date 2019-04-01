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

#include "RenderImage.h"
#include "RenderBuffer.h"
#include "RenderBinding.hpp"
#include "RenderBindingSet.h"
#include "RenderBindingLayout.h"
#include "RenderPipeline.h"
#include "RenderPipelineState.h"
#include "RenderPipelineLayout.h"
#include "RenderSwapChain.h"
#include "RenderCommandList.h"
#include "RenderPass.h"

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
	CreateRenderThread(2);
	CreateIndexBuffer();
	CreateVertexBuffer();
	CreateUniformBuffer();
	CreateTexture("Resource/vulkan2.png");
	CreateShader();
	CreatePipeline();
}

void Texture::RecordCommands(void)
{
	auto pass = mPath->GetRenderPass(0);

	Render::SwapChain* swap_chain = mViewport->GetSwapChain();

	Render::Extent2Di extent = swap_chain->GetExtent();
	Render::Offset2Di offset = { 0, 0 };
	Render::Rect2Di area = { offset, extent };
	Render::Viewport viewport = Render::Viewport(extent);
	Render::Rect2Di scissor = area;

	const size_t count = mThread->GetCommandListCount();
	for (uint32_t i = 0; i < count; ++i)
	{
		auto render_pass = pass->GetRenderPass();
		auto frame_buffer = render_pass->GetFrameBuffer(i);
		auto command_list = mThread->GetCommandList(i);
		command_list->Begin();
		command_list->BeginPass(render_pass, frame_buffer, area);
		command_list->SetViewport(0, 1, &viewport);
		command_list->SetScissor(0, 1, &scissor);

		command_list->SetVertex(mVertex->GetBuffer(), 0, 0);
		command_list->SetIndex(mIndex->GetBuffer(), 0, mIndex->GetType());

		command_list->EndPass();
		command_list->End();
		command_list->Submit(0u);
	}
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
		Render::Extent3Di extent = { width, height, 1 };

		auto manager = mSystem->GetTextureManager();
		mTexture = manager->CreateTexture2D(file_name.c_str(), extent, format);
		mTexture->Update(0, 0, bitmap);

		mPass->SetTexture(mTexture);
		SOIL_free_image_data(bitmap);
	}
	else
	{
		std::cout << "Failure to Open File : " << file << std::endl;
	}
}

void Texture::CreateShader(void)
{
	const char* vert_file = "Shaders/texture.vert";
	const char* frag_file = "Shaders/texture.frag";

	auto shader_state = mPass->GetShaderState();

	auto manager = mSystem->GetPipelineManager();
	auto vert_shader = manager->GetShader(vert_file);
	shader_state->SetShader(vert_shader);
	auto frag_shader = manager->GetShader(frag_file);
	shader_state->SetShader(frag_shader);
}

void Texture::CreatePipeline(void)
{
	auto pipeline_manager = mSystem->GetPipelineManager();

	auto pipeline_state = pipeline_manager->CreatePipelineState();
	pipeline_state->SetRenderPass(0, mPass->GetRenderPass());

	assert(mVertex != nullptr);
	auto vertex_layout = mVertex->GetLayout();
	pipeline_state->SetVertexLayout(vertex_layout);

	auto shader_state = mPass->GetShaderState();
	pipeline_state->SetShaderState(*shader_state);

	auto binding_manager = mSystem->GetBindingManager();
	auto binding_layout = binding_manager->CreateLayout();
	{
		auto binding_set = binding_manager->CreateSet();
		{
			assert(mUniform != nullptr);
			auto resource = mUniform->GetBuffer();
			Render::Binding binding = {};
			auto shader_stage = Render::ShaderStage::SHADER_STAGE_VERTEX;
			binding.SetResource(resource, shader_stage);
			binding_set->AppendBinding(binding);
		}

		const size_t count = mPass->GetTextureCount();
		assert(count > 0);
		for (size_t index = 0; index < count; ++index)
		{
			auto texture = mPass->GetTexture(index);
			auto resource = texture->GetImage();
			Render::Binding binding = {};
			auto shader_stage = Render::ShaderStage::SHADER_STAGE_FRAGMENT;
			binding.SetResource(resource, shader_stage);
			binding_set->AppendBinding(binding);
		}
		binding_set->Create();
		binding_layout->AppendBindingSet(binding_set);
	}
	auto pipeline_layout = pipeline_manager->CreatePipelineLayout();
	pipeline_layout->Create(binding_layout);
	pipeline_state->SetLayout(pipeline_layout);

	auto pipeline = pipeline_manager->GetPipeline(pipeline_state);
	assert(pipeline);
}

} /* namespace Example */
