/*
 * CoreTextureManagerh.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_CORETEXTUREMANAGER_H_
#define SOURCE_CORE_MANAGER_CORETEXTUREMANAGER_H_

#include "CoreObject.h"
#include "RenderSampler.h"
#include <vector>

namespace Core
{
class Texture;
class TextureManager : public Object
{
public:
	explicit TextureManager(System* system);
	virtual ~TextureManager(void) override;

public:
	Texture* GetTexture(const char* name);
	Texture* CreateTexture(void);

public:
	Render::Sampler* CreateSampler(void);

protected:
	std::vector<Texture*> mTextures;
	std::vector<Render::Sampler*> mSamplers;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_CORETEXTUREMANAGER_H_ */
