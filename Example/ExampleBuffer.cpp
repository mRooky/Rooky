/*
 * ExampleBuffer.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "ExampleBuffer.h"

#include "CoreBufferManager.h"
#include "CoreIndex.h"
#include "CoreVertex.h"
#include "CoreUniform.h"
#include "CorePass.h"

#include "RenderCommandList.h"
#include "RenderImage.h"
#include "RenderSwapChain.h"
#include "RenderPass.h"
#include "RenderBuffer.h"
#include "RenderEnum.h"

#include <cassert>

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
	CreateWindow("Rooky Window");
	CreateSystem();
	CreateViewport();
	CreateRenderPath();

	{
		Core::Viewport* viewport = GetViewport();
		Render::SwapChain* swap_chain = viewport->GetSwapChain();
		auto format = swap_chain->GetFormat();
		std::vector<Render::Format> formats = { format };
		CreateRenderPass(formats, Render::Format::FORMAT_UNDEFINED);
		Render::Color clear_color = Render::Color(150, 150, 150);

		for (size_t index = 0; index < 2; ++index)
		{
			Render::Image* attachment = swap_chain->GetRenderBuffer(index);
			attachment->SetClearColor(clear_color);
			std::vector<Render::Image*> attachments = { attachment };
			CreateFrameBuffer(attachments, nullptr);
		}

		CreateRenderThread(2);
	}

	CreateIndexBuffer();
	CreateVertexBuffer();
	CreateUniformBuffer();
}

void Buffer::RecordCommands(void)
{
	auto pass = mPath->GetPass(0);

	Render::SwapChain* swap_chain = mViewport->GetSwapChain();
	Render::Image* attachment = swap_chain->GetRenderBuffer(0);

	auto& extent = attachment->GetExtent();

	Render::Extent2D extent2 = { extent.width, extent.height };
	Render::Offset2D offset2 = {0.0f, 0.0f};
	Render::Rect2D area = { offset2, extent2 };
	Render::Viewport viewport = Render::Viewport(extent);
	Render::Rect2D scissor = area;

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
		command_list->EndPass();
		command_list->End();
		command_list->Submit(0u);
	}
}

int32_t Buffer::ShowModal(void)
{
	assert(mWindow != nullptr);
	Render::SwapChain* swap_chain = mViewport->GetSwapChain();
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
	auto manager = mSystem->GetBufferManager();

	Render::AllocateType allocate;
	allocate.CPUAccess = 1;

	mIndex = manager->CreateIndex();
	mIndex->Create(Render::IndexType::INDEX_TYPE_U16, 6, allocate);

	std::vector<uint16_t> indexes = { 0, 1, 2, 0, 2, 3 };

	size_t size = sizeof(uint16_t) * indexes.size();
	mIndex->Write(indexes.data(), 0, size);
}

void Buffer::CreateVertexBuffer(void)
{
	assert(mSystem != nullptr);
	auto manager = mSystem->GetBufferManager();

	Render::AllocateType allocate;
	allocate.CPUAccess = 1;

	mVertex = manager->CreateVertex();

	struct Vertex { float position[3]; float color[3]; };

	const float x = 1150.0f / 2.0f; //2.3f;
	const float y = 326.0f / 2.0f; //0.652f;
	const float z = 1.0f;
	const float o = 0.0f;

	std::vector<Vertex> vertex_buffer =
	{
			{ { x, y, z }, { 0.0f, 0.0f, 1.0f } },
			{ { o, y, z }, { 0.0f, 1.0f, 0.0f } },
			{ { o, o, z }, { 0.0f, 0.0f, 1.0f } },
			{ { x, o, z }, { 1.0f, 1.0f, 0.0f } }
	};

	std::vector<Render::Element> elements;
	elements.push_back(Render::Element(0, 0, 0, Render::ElementType::ELEMENT_TYPE_FLOAT3));
	elements.push_back(Render::Element(0, 1, 4, Render::ElementType::ELEMENT_TYPE_FLOAT3));
	auto layout = manager->CreateVertexLayout(elements);
	mVertex->Create(layout, vertex_buffer.size(), allocate);

	uint32_t size = vertex_buffer.size() * sizeof(Vertex);
	mVertex->Write(vertex_buffer.data(), 0, size);
}

void Buffer::CreateUniformBuffer(void)
{
	assert(mSystem != nullptr);
	auto manager = mSystem->GetBufferManager();

	Render::AllocateType allocate;
	allocate.CPUAccess = 1;

	mUniform = manager->CreateUniform();

	glm::mat4 scale = glm::scale(glm::mat4(1.0f) ,glm::vec3(1.0f / 1280.f, 1.0f / 800.0f, 0.0f));
	glm::mat4 trans = glm::translate(glm::mat4(1.0f) ,glm::vec3(-1.0f, -1.0f, 0.0f));
	glm::mat4 matrix = trans * scale;

	uint32_t size = sizeof(matrix);
	mUniform->Create(size, allocate);
	mVertex->Write(&matrix, 0, size);
}

} /* namespace Example */
