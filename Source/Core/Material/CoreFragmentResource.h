/*
 * CoreFragmentResource.h
 *
 *  Created on: Apr 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_COREFRAGMENTRESOURCE_H_
#define SOURCE_CORE_MATERIAL_COREFRAGMENTRESOURCE_H_

#include "CoreShaderResource.h"

namespace Core
{

class FragmentResource: public ShaderResource
{
public:
	FragmentResource(void);
	virtual ~FragmentResource(void);

public:
	virtual ResourceBindSet GetBindingSet(void) const override;

public:
	inline void AppendTexture(Texture* texture) { mTextures.push_back(texture); }
	inline size_t GetTextureCount(void) const { return mTextures.size(); }
	inline Texture* GetTexture(size_t index) const { return mTextures.at(index); }

protected:
	std::vector<Texture*> mTextures;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_COREFRAGMENTRESOURCE_H_ */
