/*
 * =====================================================================================
 *
 *       Filename:  GLTFBaseTexture.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_BASE_TEXTURE_H
#define SOURCE_GLTF_BASE_TEXTURE_H

#include "GLTFResource.h"
#include "../Core/GHI/GHIClasses.h"
#include "../Core/GHI/GHIImageLayout.h"
#include "../Core/GHI/GHIResourceUsage.h"

namespace GLTF
{

class Texture : public Resource
{
public:
	Texture(Manager* manager);
	virtual ~Texture(void);

public:
	void Create(const GHI::ImageLayout& layout, const GHI::ResourceUsage& usage);

public:
	inline GHI::Image* GetImage(void) const
	{
		return mImage;
	}

	inline bool IsValid(void) const
	{
		return mImage != nullptr;
	}

	inline GHI::Sampler* GetSamper(void) const
	{
		return mSampler;
	}

	inline void SetSampler(GHI::Sampler* sampler)
	{
		mSampler = sampler;
	}

protected:
	Manager* mManager = nullptr;
	GHI::Image* mImage = nullptr;
	GHI::Sampler* mSampler = nullptr;

};

}

#endif
