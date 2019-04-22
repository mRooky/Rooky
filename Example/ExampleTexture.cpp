/*
 * ExampleTexture.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "ExampleTexture.h"

#include "GHIBinding.hpp"
#include "GHIBindingLayout.h"
#include "GHIBindingSet.h"
#include "GHIBuffer.h"
#include "GHICommandList.h"
#include "GHIImage.h"
#include "GHIRenderPass.h"
#include "GHIPipeline.h"
#include "GHIPipelineLayout.h"
#include "GHIPipelineState.h"
#include "GHISwapChain.h"
#include "CorePass.h"
#include "CoreTexture.h"
#include "CoreSystem.h"
#include "CoreThread.h"
#include "CoreTextureManager.h"
#include "CoreBufferManager.h"
#include "CoreTextureManager.h"
#include "CoreBindingManager.h"
#include "CorePipelineManager.h"

#include "UtilityString.h"

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
	CreateScene();
	CreateViewport();
	CreateRenderPath();
	CreateRenderPass();
	CreateFrameBuffer();
	CreateRenderThread(2);
	CreateIndexBuffer();
	CreateVertexBuffer();
	CreateUniformBuffer();
	CreateTexture("Resource/vulkan.png");
	CreateShader();
	CreatePipeline();
}

void Texture::RecordCommands(void)
{
	auto pass = mPath->GetRenderPass(0);

	GHI::SwapChain* swap_chain = mScene->GetSwapChain();

	Math::Extent2Di extent = swap_chain->GetExtent();
	Math::Offset2Di offset = {};
	Math::Rect2Di area = {};
	area.offset = offset;
	area.extent = extent ;
	Math::Viewport viewport = Math::Viewport(extent);
	Math::Rect2Di scissor = area;
	GHI::Draw* draw = mIndex->GetDraw();
	const size_t count = mThread->GetCommandListCount();
	assert(count > 1);
	for (uint32_t i = 0; i < count; ++i)
	{
		auto render_pass = pass->GetRenderPass();
		auto frame_buffer = render_pass->GetFrameBuffer(i);
		auto command_list = mThread->GetCommandList(i);
		command_list->Begin();
		command_list->BeginPass(render_pass, frame_buffer, area);
		command_list->SetViewport(0, 1, &viewport);
		command_list->SetScissor(0, 1, &scissor);
		command_list->SetPipeline(mPipeline);
		command_list->SetVertex(mVertex->GetRenderResource(), 0, 0);
		command_list->SetIndex(mIndex->GetRenderResource(), 0, mIndex->GetType());
		command_list->Draw(draw);
		command_list->EndPass();
		command_list->End();
		command_list->Submit(0u);
	}
}

void Texture::CreateTexture(const char* file)
{
	assert(Utility::DoesFileExist(file));
	int width, height, channels;
	uint8_t * bitmap = SOIL_load_image(file, &width, &height, &channels, SOIL_LOAD_RGBA);
	if (bitmap != nullptr)
	{
		//assert(channels == 4);
		Math::Extent3Di extent = { width, height, 1 };
		GHI::Format format = GHI::Format::FORMAT_R8G8B8A8_UNORM;

		auto manager = mSystem->GetTextureManager();
		mTexture = manager->CreateTexture2D(file, extent, format);
		mTexture->Update(0, 0, bitmap);

		auto sampler = manager->CreateSampler();
		sampler->Create();
		mTexture->SetSampler(sampler);

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
	auto shader_state = mPass->GetShaderState();
	auto manager = mSystem->GetPipelineManager();

	const char* vert_file = "Shaders/texture.vert";
	auto vert_shader = manager->GetShader(vert_file);
	shader_state->SetShader(vert_shader);

	const char* frag_file = "Shaders/texture.frag";
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
			GHI::Resource* resource = mUniform->GetRenderResource();
			GHI::Binding binding = {};
			auto shader_stage = GHI::ShaderStage::SHADER_STAGE_VERTEX;
			binding.SetResource(resource, shader_stage);
			binding_set->AppendBinding(binding);
		}

		const size_t count = mPass->GetTextureCount();
		assert(count > 0);
		for (size_t index = 0; index < count; ++index)
		{
			GHI::ShaderStage shader_stage = GHI::ShaderStage::SHADER_STAGE_FRAGMENT;
			Core::Texture* texture = mPass->GetTexture(index);
			{
				GHI::Resource* resource = texture->GetRenderResource();
				GHI::Binding binding = {};
				binding.SetResource(resource, shader_stage);
				binding_set->AppendBinding(binding);
			}

			GHI::Sampler* sampler = texture->GetSampler();
			if (sampler != nullptr)
			{
				GHI::Binding binding = {};
				binding.SetResource(sampler, shader_stage);
				binding_set->AppendBinding(binding);
			}
		}
		binding_set->Create();
		binding_layout->AppendBindingSet(binding_set);
	}
	auto pipeline_layout = pipeline_manager->CreatePipelineLayout();
	pipeline_layout->Create(binding_layout);
	pipeline_state->SetLayout(pipeline_layout);

	mPipeline = pipeline_manager->GetPipeline(pipeline_state);
}

} /* namespace Example */
