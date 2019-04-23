/*
 * CoreTexture.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETEXTURE_H_
#define SOURCE_CORE_CORETEXTURE_H_

#include "CoreRenderTarget.h"
#include <string>

namespace Core
{
class Texture : public RenderTarget
{
public:
	explicit Texture(TextureManager* manager);
	virtual ~Texture(void) override;

public:
	void Update(uint32_t index, uint32_t mipmap, const void* src);

public:
	inline GHI::Sampler* GetSampler(void) const { return mSampler; }
	inline void SetSampler(GHI::Sampler* sampler) { mSampler = sampler; }

protected:
	GHI::Sampler* mSampler = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETEXTURE_H_ */
