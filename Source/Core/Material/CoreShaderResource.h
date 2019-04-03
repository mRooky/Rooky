/*
 * CoreShaderResource.h
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_CORESHADERRESOURCE_H_
#define SOURCE_CORE_MATERIAL_CORESHADERRESOURCE_H_

#include "RenderClasses.h"
#include <vector>

namespace Core
{
class Uniform;
class Texture;
class ShaderResource
{
public:
	ShaderResource(void);
	~ShaderResource(void);

public:
	void SetUniform(Uniform* uniform, size_t offset);

public:
	inline Render::Shader* GetShader(void) const { return mShader; }
	inline void SetShader(Render::Shader* shader)  { mShader = shader; }

public:
	inline void AppendTexture(Texture* texture) { mTextures.push_back(texture); }
	inline size_t GetTextureCount(void) const { return mTextures.size(); }
	inline Texture* GetTexture(size_t index) const { return mTextures.at(index); }

public:
	inline Uniform* GetUniform(void) const { return mUniform; }
	inline size_t GetUniformOffset(void) const { return mUniformOffset; }

protected:
	Render::Shader* mShader = nullptr;

protected:
	Uniform* mUniform = nullptr;
	size_t mUniformOffset = 0;
	std::vector<Texture*> mTextures;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_CORESHADERRESOURCE_H_ */
