/*
 * CoreShaderResource.h
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_CORESHADERRESOURCE_H_
#define SOURCE_CORE_MATERIAL_CORESHADERRESOURCE_H_

#include "GHIBinding.hpp"
#include "GHIClasses.h"
#include <vector>

namespace Core
{
class Uniform;
class Texture;
class ShaderResource
{
public:
	ShaderResource(void);
	virtual ~ShaderResource(void);

public:
	virtual std::vector<GHI::Binding> GetBindings(void) const = 0;

public:
	inline GHI::Shader* GetShader(void) const { return mShader; }
	inline void SetShader(GHI::Shader* shader)  { mShader = shader; }

protected:
	GHI::Shader* mShader = nullptr;

};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_CORESHADERRESOURCE_H_ */
