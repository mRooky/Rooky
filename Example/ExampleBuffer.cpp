/*
 * ExampleBuffer.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "ExampleBuffer.h"

#include "CoreIndex.h"
#include "CoreVertex.h"
#include "CoreUniform.h"
#include "CorePass.h"
#include "CoreSystem.h"
#include "CoreMeshManager.h"
#include "CoreBufferManager.h"
#include "CoreThread.h"

#include "RenderCommandList.h"
#include "RenderImage.h"
#include "RenderSwapChain.h"
#include "RenderPass.h"
#include "RenderBuffer.h"
#include "RenderEnum.h"
#include "RenderFrameBuffer.h"

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
	CreateRenderPath();
	CreateRenderPass();
	CreateFrameBuffer();
	CreateRenderThread(2);
	CreateIndexBuffer();
	CreateVertexBuffer();
	CreateUniformBuffer();
}

void Buffer::CreateRenderPass(void)
{
	assert(mPath != nullptr);
	Render::SwapChain* swap_chain = mScene->GetSwapChain();
	auto format = swap_chain->GetFormat();
	std::vector<Render::Format> formats = { format };
	mPass = mPath->CreatePass();
	mPass->CreateRenderPass(formats);
}

void Buffer::CreateFrameBuffer(void)
{
	assert(mPath->GetPassCount() > 0);
	Render::SwapChain* swap_chain = mScene->GetSwapChain();
	Render::Color clear_color = Render::Color(10, 10, 10);
	Render::Pass* pass = mPath->GetRenderPass(0)->GetRenderPass();
	for (size_t index = 0; index < 2; ++index)
	{
		Render::Image* image = swap_chain->GetRenderBuffer(index);
		image->SetClearColor(clear_color);
		Render::Attachment attachment = {};
		attachment.AppendImage(image);
		Render::FrameBuffer* frame = pass->CreateFrameBuffer();
		frame->Create(attachment);
	}
}

void Buffer::RecordCommands(void)
{
	auto pass = mPath->GetRenderPass(0);

	Render::SwapChain* swap_chain = mScene->GetSwapChain();
	const Render::Extent2Di& extent = swap_chain->GetExtent();
	Render::Rect2Di area = {};
	area.extent = extent;
	Render::Viewport viewport = Render::Viewport(extent);
	Render::Rect2Di scissor = area;

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
		command_list->EndPass();
		command_list->End();
		command_list->Submit(0u);
	}
}

int32_t Buffer::ShowModal(void)
{
	assert(mWindow != nullptr);
	Render::SwapChain* swap_chain = mScene->GetSwapChain();
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
	Render::IndexType index_type = Render::IndexType::INDEX_TYPE_U16;
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

	std::vector<Render::Element> elements =
	{
		Render::Element(0, 0, Render::ElementType::ELEMENT_TYPE_FLOAT3),
		Render::Element(0, 1, Render::ElementType::ELEMENT_TYPE_FLOAT2)
	};

	auto layout = buffer_manager->CreateVertexLayout(elements);
	const size_t count = vertex_buffer.size();
	const uint32_t size = count * sizeof(Vertex);
	mVertex->Create(layout, count);
	mVertex->Write(vertex_buffer.data(), 0, size);
}

void Buffer::CreateUniformBuffer(void)
{
	assert(mSystem != nullptr);
	auto mesh_manager = mSystem->GetMeshManager();
	auto buffer_manager = mesh_manager->GetBufferManager();

	Render::UsageType usage;
	usage.cpuAccess = 1;

	mUniform = buffer_manager->CreateUniform();
	glm::mat4 matrix = glm::mat4(1.0f);

	uint32_t size = sizeof(matrix);
	mUniform->Create(size, usage);
	mUniform->Write(&matrix, 0, size);
}

} /* namespace Example */
