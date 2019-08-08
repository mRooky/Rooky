/*
 * RenderAttachment.h
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_GHIATTACHMENT_H_
#define SOURCE_CORE_GHI_GHIATTACHMENT_H_

#include <vector>

namespace GHI
{
class Image;
class Attachment
{
public:
	Attachment(void);
	~Attachment(void);

public:
	void AppendImage(Image* image);
	void SetDepthStencil(Image* image);

public:
	inline bool IsValid(void) const
	{
		return mImages.size() > 0;
	}

public:
	inline Image* GetDepthStencil(void) const
	{
		return mDepthStencil;
	}

	inline size_t GetImageCount(void) const
	{
		return mImages.size();
	}

	inline Image* GetImage(size_t index) const
	{
		return mImages.at(index);
	}

public:
	inline bool operator==(const Attachment& other)
	{
		return (mDepthStencil == other.mDepthStencil)
			&& (mImages == other.mImages);
	}

	inline Attachment& operator=(const Attachment& other)
	{
		if (this != &other)
		{
			mImages = other.mImages;
			mDepthStencil = other.mDepthStencil;
		}
		return *this;
	}

protected:
	std::vector<Image*> mImages;
	Image* mDepthStencil = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_GHIATTACHMENT_H_ */
