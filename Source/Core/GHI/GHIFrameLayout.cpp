/*
 * RenderAttachment.cpp
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#include "GHIFrameLayout.h"
#include "GHIImage.h"
#include <cassert>
#include <iostream>
#include <algorithm>

namespace GHI
{

FrameLayout::FrameLayout(void)
{
}

FrameLayout::~FrameLayout(void)
{
	mAttachments.clear();
	mDepthStencil = nullptr;
}

void FrameLayout::SetDepthStencil(Image* image)
{
	if(image != nullptr)
	{
		bool for_depth_stencil = image->IsDepthStencil();
		assert(true == for_depth_stencil);
		mDepthStencil = (true == for_depth_stencil) ? image : nullptr;
	}
}

void FrameLayout::AppendImage(Image* image)
{
	assert(image != nullptr);
	bool for_depth_stencil = image->IsDepthStencil();
	if (false == for_depth_stencil)
	{
		auto iterator = std::find(mAttachments.begin(), mAttachments.end(), image);
		if (iterator == mAttachments.end())
		{
			mAttachments.push_back(image);
		}
		else
		{
			std::cout << "FrameLayout exist !" << std::endl;
			assert(false);
		}
	}
	else
	{
		std::cout << "FrameLayout Format for DepthStencil !" << std::endl;
		assert(false);
	}
}

} /* namespace Render */
