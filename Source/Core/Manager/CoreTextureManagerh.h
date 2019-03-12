/*
 * CoreTextureManagerh.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_CORETEXTUREMANAGERH_H_
#define SOURCE_CORE_MANAGER_CORETEXTUREMANAGERH_H_

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

private:
	std::vector<Texture*> mTextures;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_CORETEXTUREMANAGERH_H_ */
