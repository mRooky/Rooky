/*
 * CoreTexture.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETEXTURE_H_
#define SOURCE_CORE_CORETEXTURE_H_

#include "CoreResource.h"
#include "GHI/GHIImageLayout.h"
#include "GHI/GHIResourceUsage.h"
#include <string>

namespace Core
{

class TextureManager;
class Texture : public Resource
{
public:
	explicit Texture(TextureManager* manager);
	virtual ~Texture(void) override;

public:
	void Create(const GHI::ImageLayout& layout, const GHI::ResourceUsage& usage);

public:
	void Update(uint32_t index, uint32_t mipmap, const void* src);

public:
	inline GHI::Sampler* GetSampler(void) const { return mSampler; }
	inline void SetSampler(GHI::Sampler* sampler) { mSampler = sampler; }

public:
	inline TextureManager* GetManager(void) const { return mManager; }

protected:
	TextureManager* mManager = nullptr;

protected:
	GHI::Sampler* mSampler = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETEXTURE_H_ */
