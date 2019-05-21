/*
 * CoreShaderResource.h
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_CORESHADERRESOURCE_H_
#define SOURCE_CORE_MATERIAL_CORESHADERRESOURCE_H_

#include "../GHI/GHIBinding.h"
#include "../GHI/GHIClasses.h"
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
	inline GHI::Shader* GetShader(void) const { return mShader; }
	inline void SetShader(GHI::Shader* shader)  { mShader = shader; }

public:
	inline size_t GetBindingCount(void) const { return mBindings.size(); }
	inline const GHI::Binding& GetBinding(size_t index) const { return mBindings.at(index); }

protected:
	GHI::Shader* mShader = nullptr;
	std::vector<GHI::Binding> mBindings;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_CORESHADERRESOURCE_H_ */
