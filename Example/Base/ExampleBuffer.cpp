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
#include "RenderTypes.h"

#include <cassert>

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
		Render::Image* attachment = swap_chain->GetRenderBuffer(0);
		auto format = attachment->GetFormat();
		std::vector<Render::Format> formats = { format };
		CreateRenderPass(formats, Render::Format::FORMAT_UNDEFINED);

		std::vector<Render::Image*> attachments = { attachment };
		CreateFrameBuffer(attachments, nullptr);

		attachments[0] = swap_chain->GetRenderBuffer(1);
		CreateFrameBuffer(attachments, nullptr);

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

	Render::Extent2 extent2 =
	{
			extent.width,
			extent.height
	};

	Render::Rect2D area =
	{
			Render::Offset2(0.0f, 0.0f),
			extent2
	};

	Render::Viewport viewport =
	{
			0.0f,
			0.0f,
			static_cast<float>(extent.width),
			static_cast<float>(extent.height),
			0.0f,
			1.0f
	};

	Render::Rect2D scissor = area;

	const size_t count = mThread->GetCommandListCount();
	for (uint32_t i = 0; i < count; ++i)
	{
		auto render_pass = pass->GetRenderPass();
		auto frame_buffer = render_pass->GetFrameBuffer(i);
		auto command_list = mThread->GetCommandList(i);
		command_list->BeginRecord();
		command_list->BeginPass(0, render_pass);
		command_list->BindFrameBuffer(frame_buffer, area);
		command_list->SetViewport(0, 1, &viewport);
		command_list->SetScissor(0, 1, &scissor);
		command_list->EndPass();
		command_list->EndRecord();
		if (true)
		{
			command_list->Submit(0);
		}
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
	Render::HeapAccess access = Render::HeapAccess::HEAP_ACCESS_CPU_VISIBLE;
	mIndex = manager->CreateIndex();
	mIndex->Create(Render::IndexType::INDEX_TYPE_U16, 6, access);
}

void Buffer::CreateVertexBuffer(void)
{
	assert(mSystem != nullptr);
	auto manager = mSystem->GetBufferManager();
	Render::HeapAccess access = Render::HeapAccess::HEAP_ACCESS_CPU_VISIBLE;
	mVertex = manager->CreateVertex();
}

void Buffer::CreateUniformBuffer(void)
{
	assert(mSystem != nullptr);
	auto manager = mSystem->GetBufferManager();
	Render::HeapAccess access = Render::HeapAccess::HEAP_ACCESS_CPU_VISIBLE;
	mUniform = manager->CreateUniform();
}

} /* namespace Example */
