/*
 * CorePass.h
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREPASS_H_
#define SOURCE_CORE_COREPASS_H_

#include "RenderClasses.h"
#include "RenderFormat.h"
#include "RenderShaderState.h"
#include "RenderDepthStencil.h"
#include <vector>

namespace Core
{
class Path;
class Texture;
class Pass
{
	friend class Path;
protected:
	explicit Pass(Path* parent);

public:
	virtual ~Pass(void);

public:
	void CreateRenderPass(const std::vector<Render::Format>& formats);

public:
	inline Path* GetParent(void) const { return mParent; }

public:
	inline size_t GetTextureCount(void) const { return mTextures.size(); }

public:
	inline void SetTexture(Texture* texture) { mTextures.push_back(texture); }
	inline Texture* GetTexture(size_t index) const { return mTextures.at(index); }

public:
	inline Render::Pass* GetRenderPass(void) const { return mRenderPass; }
	inline Render::ShaderState* GetShaderState(void) { return &mShaderState; }
	inline Render::DepthStencil* GetDepthStencil(void) { return &mDepthStencil; }

protected:
	Path* mParent = nullptr;

protected:
	std::vector<Texture*> mTextures;

protected:
	Render::Pass* mRenderPass = nullptr;
	Render::ShaderState mShaderState = {};
	Render::DepthStencil mDepthStencil = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPASS_H_ */
