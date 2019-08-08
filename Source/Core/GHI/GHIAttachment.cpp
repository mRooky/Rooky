/*
 * RenderAttachment.cpp
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#include "GHIAttachment.h"
#include "GHIImage.h"
#include <cassert>
#include <iostream>
#include <algorithm>

namespace GHI
{

Attachment::Attachment(void)
{
}

Attachment::~Attachment(void)
{
	mImages.clear();
	mDepthStencil = nullptr;
}

void Attachment::SetDepthStencil(Image* image)
{
	if(image != nullptr)
	{
		bool for_depth_stencil = image->IsDepthStencil();
		assert(true == for_depth_stencil);
		mDepthStencil = (true == for_depth_stencil) ? image : nullptr;
	}
}

void Attachment::AppendImage(Image* image)
{
	assert(image != nullptr);
	bool for_depth_stencil = image->IsDepthStencil();
	if (false == for_depth_stencil)
	{
		auto iterator = std::find(mImages.begin(), mImages.end(), image);
		if (iterator == mImages.end())
		{
			mImages.push_back(image);
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
