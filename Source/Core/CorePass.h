/*
 * CorePass.h
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREPASS_H_
#define SOURCE_CORE_COREPASS_H_

#include "GHIClasses.h"
#include "GHIFormat.h"
#include "GHIShaderState.h"
#include "GHIDepthStencil.h"
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
	void CreateRenderPass(const std::vector<GHI::Format>& formats);

public:
	inline Path* GetParent(void) const { return mParent; }

public:
	inline size_t GetTextureCount(void) const { return mTextures.size(); }

public:
	inline void SetTexture(Texture* texture) { mTextures.push_back(texture); }
	inline Texture* GetTexture(size_t index) const { return mTextures.at(index); }

public:
	inline GHI::RenderPass* GetRenderPass(void) const { return mRenderPass; }
	inline GHI::ShaderState* GetShaderState(void) { return &mShaderState; }
	inline GHI::DepthStencil* GetDepthStencil(void) { return &mDepthStencil; }

protected:
	Path* mParent = nullptr;

protected:
	std::vector<Texture*> mTextures;

protected:
	GHI::RenderPass* mRenderPass = nullptr;
	GHI::ShaderState mShaderState = {};
	GHI::DepthStencil mDepthStencil = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPASS_H_ */
