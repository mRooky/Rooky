/*
 * ExampleBuffer.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "ExampleBuffer.h"

#include "../Core/GHI/GHIBuffer.h"
#include "../Core/GHI/GHICommandList.h"
#include "../Core/GHI/GHIIndexType.h"
#include "../Core/GHI/GHIFrameBuffer.h"
#include "../Core/GHI/GHIImage.h"
#include "../Core/GHI/GHIRenderPass.h"
#include "../Core/GHI/GHISwapChain.h"

#include "../Core/CoreSubPass.h"
#include "../Core/CoreIndex.h"
#include "../Core/CoreVertex.h"
#include "../Core/CoreUniform.h"
#include "../Core/CoreSystem.h"
#include "../Core/Manager/CoreMeshManager.h"
#include "../Core/Manager/CoreBufferManager.h"
#include "../Core/CoreThread.h"
#include "../Core/Math/MathColorValue.h"

#include <cassert>
#include <array>
#include <iostream>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Example
{

Buffer::Buffer(void)
{
}

Buffer::~Buffer(void)
{
	mIndex = nullptr;
	mVertex = nullptr;
	mUniform = nullptr;
}

void Buffer::Initialize(void)
{
	CreateWindow("Buffer Window");
	CreateScene();
	CreateViewport();
	CreateRenderPass();
	CreateSubPass();
	CreateFrameBuffer();
	CreateRenderThread(2);
	CreateIndexBuffer();
	CreateVertexBuffer();
	CreateUniformBuffer();
}

void Buffer::CreateSubPass(void)
{
	assert(mPass != nullptr);
	GHI::SwapChain* swap_chain = mScene->GetSwapChain();
	auto format = swap_chain->GetFormat();
	std::vector<GHI::Format> formats = { format };
	mSubPass = mPass->CreateSubPass();
	mSubPass->CreateRenderPass(formats);
}

void Buffer::CreateFrameBuffer(void)
{
	assert(mPass->GetSubPassCount() > 0);
	GHI::SwapChain* swap_chain = mScene->GetSwapChain();
	Math::ColorI clear_color = Math::ColorI(10, 10, 10, 255);
	GHI::RenderPass* pass = mPass->GetSubPass(0)->GetRenderPass();
	for (size_t index = 0; index < 2; ++index)
	{
		GHI::Image* image = swap_chain->GetRenderBuffer(index);
		image->SetClearColor(clear_color);
		GHI::FrameLayout layout = {};
		layout.AppendImage(image);
		GHI::FrameBuffer* frame = pass->CreateFrameBuffer();
		frame->Create(layout);
	}
}

void Buffer::RecordCommands(void)
{
	auto sub = mPass->GetSubPass(0);

	GHI::SwapChain* swap_chain = mScene->GetSwapChain();
	const Math::Extent2Di& extent = swap_chain->GetExtent();
	Math::Rect2Di area = {};
	area.extent = extent;
	Math::Viewport viewport = Math::Viewport(extent);
	Math::Rect2Di scissor = area;

	const size_t count = mThread->GetCommandListCount();
	assert(count > 1);
	for (uint32_t i = 0; i < count; ++i)
	{
		auto render_pass = sub->GetRenderPass();
		auto frame_buffer = render_pass->GetFrameBuffer(i);
		auto command_list = mThread->GetCommandList(i);
		command_list->Begin();
		command_list->BeginPass(render_pass, frame_buffer, area);
		command_list->SetViewport(0, 1, &viewport);
		command_list->SetScissor(0, 1, &scissor);
		command_list->EndPass();
		command_list->End();
		command_list->Submit(0u);
	}
}

int32_t Buffer::ShowModal(void)
{
	assert(mWindow != nullptr);
	GHI::SwapChain* swap_chain = mScene->GetSwapChain();
	bool done = false;
	while (!done)
	{
		done = mWindow->HandleEvent();
		swap_chain->SwapBuffer(0);
	}
	return 0;
}

void Buffer::CreateIndexBuffer(void)
{
	assert(mSystem != nullptr);
	auto mesh_manager = mSystem->GetMeshManager();
	auto buffer_manager = mesh_manager->GetBufferManager();

	std::vector<uint16_t> indexes = { 0, 1, 2, 0, 2, 3 };
	const size_t count = indexes.size();
	const size_t size = sizeof(uint16_t) * count;

	mIndex = buffer_manager->CreateIndex();
	GHI::IndexType index_type = GHI::IndexType::U16;
	mIndex->Create(index_type, count);
	assert(mIndex->GetSizeInByte() == size);
	mIndex->Write(indexes.data(), 0, size);
}

void Buffer::CreateVertexBuffer(void)
{
	assert(mSystem != nullptr);
	auto mesh_manager = mSystem->GetMeshManager();
	auto buffer_manager = mesh_manager->GetBufferManager();

	mVertex = buffer_manager->CreateVertex();

	struct Vertex
	{
		float position[3];
		float uv[2];
	};

	const float x = 0.90f;
	const float y = 0.85f;
	const float z = 0.1f;

	std::vector<Vertex> vertex_buffer =
	{
			{ {  x,  y, z }, { 1.0f, 1.0f } },
			{ { -x,  y, z }, { 0.0f, 1.0f } },
			{ { -x, -y, z }, { 0.0f, 0.0f } },
			{ {  x, -y, z }, { 1.0f, 0.0f } }
	};

	GHI::VertexLayout layout;
	layout.PushSemantic(GHI::SemanticUsage::POSITION, GHI::SemanticType::FLOAT3);
	layout.PushSemantic(GHI::SemanticUsage::TEXCOORD, GHI::SemanticType::FLOAT2);

	const size_t count = vertex_buffer.size();
	const uint32_t size = count * sizeof(Vertex);
	mVertex->Create(&layout, count);
	mVertex->Write(vertex_buffer.data(), 0, size);
}

void Buffer::CreateUniformBuffer(void)
{
	assert(mSystem != nullptr);
	auto mesh_manager = mSystem->GetMeshManager();
	auto buffer_manager = mesh_manager->GetBufferManager();

	GHI::ResourceUsage usage;
	usage.memoryType.cpuAccess = 1;

	mUniform = buffer_manager->CreateUniform();
	glm::mat4 matrix = glm::mat4(1.0f);

	uint32_t size = sizeof(matrix);
	mUniform->Create(size, usage);
	mUniform->Write(&matrix, 0, size);
}

} /* namespace Example */
