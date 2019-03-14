/*
 * CoreTextureManagerh.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_CORETEXTUREMANAGER_H_
#define SOURCE_CORE_MANAGER_CORETEXTUREMANAGER_H_

#include "CoreObject.h"
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

protected:
	std::vector<Texture*> mTextures;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_CORETEXTUREMANAGER_H_ */
