/*
 * RenderAttachment.h
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_FRAME_LAYPUT_H
#define SOURCE_CORE_GHI_FRAME_LAYPUT_H

#include <vector>

namespace GHI
{
class Image;
class FrameLayout
{
public:
	FrameLayout(void);
	~FrameLayout(void);

public:
	void AppendImage(Image* image);
	void SetDepthStencil(Image* image);

public:
	inline bool IsValid(void) const
	{
		return mAttachments.size() > 0;
	}

public:
	inline Image* GetDepthStencil(void) const
	{
		return mDepthStencil;
	}

	inline size_t GetImageCount(void) const
	{
		return mAttachments.size();
	}

	inline Image* GetImage(size_t index) const
	{
		return mAttachments.at(index);
	}

public:
	inline bool operator==(const FrameLayout& other)
	{
		if (mDepthStencil == other.mDepthStencil)
		{
			return (mAttachments == other.mAttachments);
		}
		return false;
	}

	inline FrameLayout& operator=(const FrameLayout& other)
	{
		if (this != &other)
		{
			mAttachments = other.mAttachments;
			mDepthStencil = other.mDepthStencil;
		}
		return *this;
	}

protected:
	Image* mDepthStencil = nullptr;
	std::vector<Image*> mAttachments;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_GHIATTACHMENT_H_ */
