/*
 * ExampleRenderPass.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#include "ExamplePath.h"

#include "CorePass.h"

#include "RenderPass.h"
#include "RenderFrameBuffer.h"

#include <cassert>

namespace Example
{

Path::Path(void)
{
}

Path::~Path(void)
{
	delete mPath;
	mPath = nullptr;
	delete mThread;
	mThread = nullptr;
	mCommandLists.clear();
}

void Path::CreateRenderPath(void)
{
	assert(mSystem != nullptr);
	mPath = new Core::Path(mSystem);
}

void Path::CreateRenderPass(const std::vector<Render::Format>& formats, Render::Format depth)
{
	assert(mPath != nullptr);
	Core::Pass* pass = mPath->CreatePass();
	pass->Create(formats);
}

void Path::CreateFrameBuffer(const std::vector<Render::Image*>& attachments, Render::Image* depth)
{
	assert(mPath->GetPassCount() > 0);
	Render::Pass* pass = mPath->GetPass(0)->GetRenderPass();
	Render::FrameBuffer* frame = pass->CreateFrameBuffer();
	for (auto attachment : attachments)
	{
		frame->AppendAttachment(attachment);
	}

	frame->SetDepthStencil(depth);
	frame->Create();
}

void Path::CreateRenderThread(size_t count)
{
	mThread = new Core::Thread(mSystem);
	mThread->Create();
	for (size_t i = 0; i < count; ++i)
	{
		Render::CommandList* list = mThread->Allocate(true);
		mCommandLists.push_back(list);
	}
}

} /* namespace Example */
