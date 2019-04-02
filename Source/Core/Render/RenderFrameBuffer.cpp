/*
 * RenderFrameBuffer.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderFrameBuffer.h"
#include "RenderImage.h"

#include <algorithm>
#include <iostream>
#include <cassert>

namespace Render
{

FrameBuffer::FrameBuffer(Pass* pass):
		mPass(pass)
{
}

FrameBuffer::~FrameBuffer(void)
{
	mPass = nullptr;
	mAttachments.clear();
	mDepthStencil = nullptr;
}

void FrameBuffer::SetDepthStencil(Image* attachment)
{
	if(attachment != nullptr)
	{
		auto& usage = attachment->GetUsage();
		bool for_depth_stencil = usage.imageUsage.DepthStencil == TRUE;
		assert(true == for_depth_stencil);
		if (true == for_depth_stencil)
		{
			Format format = attachment->GetFormat();
			bool format_depth_stencil = Image::IsDepthStencilFormat(format);
			assert(true == format_depth_stencil);
			mDepthStencil = (true == format_depth_stencil) ? attachment : nullptr;
		}
	}
}

void FrameBuffer::AppendAttachment(Image* attachment)
{
	assert(attachment != nullptr);

	Format format = attachment->GetFormat();
	bool is_depth = Image::IsDepthStencilFormat(format);
	if (is_depth == false)
	{
		auto iterator = std::find(mAttachments.begin(), mAttachments.end(), attachment);
		if (iterator == mAttachments.end())
		{
			mAttachments.push_back(attachment);
		}
		else
		{
			std::cout << "Attachment exist !" << std::endl;
			assert(false);
		}
	}
	else
	{
		std::cout << "Attachment Format for DepthStencil !" << std::endl;
		assert(false);
	}

}

} /* namespace Render */
