/*
 * CoreTextureManagerh.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_CORETEXTUREMANAGER_H_
#define SOURCE_CORE_MANAGER_CORETEXTUREMANAGER_H_

#include "GHIFormat.h"
#include "MathExtent.h"
#include "GHISampler.h"
#include "CoreInterface.h"
#include <vector>

namespace Core
{
class Texture;
class TextureManager : public Interface
{
public:
	explicit TextureManager(System* system);
	virtual ~TextureManager(void) override;

public:
	Texture* CreateTexture1D(const char* name, const Math::Extent3Di& extent, GHI::Format format);
	Texture* CreateTexture2D(const char* name, const Math::Extent3Di& extent, GHI::Format format);
	Texture* CreateTexture3D(const char* name, const Math::Extent3Di& extent, GHI::Format format);

public:
	Texture* CreateTexture1DArray(const char* name, const Math::Extent3Di& extent, GHI::Format format);
	Texture* CreateTexture2DArray(const char* name, const Math::Extent3Di& extent, GHI::Format format);

public:
	Texture* CreateTextureCube(const char* name, const Math::Extent3Di& extent, GHI::Format format);
	Texture* CreateTextureCubeArray(const char* name, const Math::Extent3Di& extent, GHI::Format format);

public:
	Texture* GetTexture(const char* name);
	Texture* CreateTexture(void);

public:
	GHI::Sampler* CreateSampler(void);

protected:
	std::vector<Texture*> mTextures;
	std::vector<GHI::Sampler*> mSamplers;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_CORETEXTUREMANAGER_H_ */
