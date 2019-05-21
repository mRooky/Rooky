/*
 * RenderAttachment.cpp
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#include "GHIAttachment.h"
#include "GHIImage.h"
#include "../Utillity/UtilitySearch.h"
#include <cassert>
#include <iostream>

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
		auto& usage = image->GetUsage();
		bool for_depth_stencil = usage.depthStencil == TRUE;
		assert(true == for_depth_stencil);
		if (true == for_depth_stencil)
		{
			const GHI::ImageLayout& layout = image->GetLayout();
			Format format = layout.GetFormat();
			bool format_depth_stencil = Image::IsDepthStencilFormat(format);
			assert(true == format_depth_stencil);
			mDepthStencil = (true == format_depth_stencil) ? image : nullptr;
		}
	}
}

void Attachment::AppendImage(Image* image)
{
	assert(image != nullptr);
	const GHI::ImageLayout& layout = image->GetLayout();
	Format format = layout.GetFormat();
	bool is_depth = Image::IsDepthStencilFormat(format);
	if (is_depth == false)
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

Attachment& Attachment::operator=(const Attachment& other)
{
	mImages = other.mImages;
	mDepthStencil = other.mDepthStencil;
	return *this;
}

} /* namespace Render */
