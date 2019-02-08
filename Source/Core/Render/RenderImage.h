/*
 * RenderImage.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERIMAGE_H_
#define SOURCE_CORE_RENDER_RENDERIMAGE_H_

#include "RenderResource.h"
#include "RenderFormat.h"
#include "RenderMath.h"

namespace Render
{
class Sampler;
class Image : public Resource
{
public:
	enum class Type : uint32_t
	{
		IMAGE_1D,
		IMAGE_2D,
		IMAGE_3D,
		IMAGE_CUBE,
		IMAGE_1D_ARRAY,
		IMAGE_2D_ARRAY,
		IMAGE_CUBE_ARRAY,
		IMAGE_UNKNOWN = ~0u
	};

public:
	explicit Image(Context* context);
	virtual ~Image(void) override;

public:
	inline void Initialize(Format format, uint32_t width, uint32_t height, uint32_t usage)
	{
		Initialize(format, width, height, 1, usage);
	}

public:
	virtual void Initialize(Format format, uint32_t width, uint32_t height, uint32_t depth, uint32_t usage) = 0;
	virtual void CreateView(Type type) = 0;

public:
	inline Sampler* GetSampler(void) const { return mSampler; }
	inline void SetSampler(Sampler* sampler) { mSampler = sampler; }

public:
	inline const Extent3& GetExtent(void) const { return mExtent; }

public:
	inline Format GetFormat(void) const { return mFormat; }

protected:
	Extent3 mExtent = {};

protected:
	Sampler* mSampler = nullptr;
	Format mFormat = Format::UNDEFINED;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERIMAGE_H_ */
