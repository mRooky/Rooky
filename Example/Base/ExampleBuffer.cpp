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

#include "RenderImage.h"
#include "RenderSwapChain.h"

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

	CreateBuffer();
}

void Buffer::CreateBuffer(void)
{
	assert(mSystem != nullptr);
	auto manager = mSystem->GetBufferManager();

	mIndex = manager->CreateIndex();
	mIndex->Create(Render::IndexType::INDEX_TYPE_U16, 6);

	mVertex = manager->CreateVertex();

	mUniform = manager->CreateUniform();
}

} /* namespace Example */
