/*
 * CoreSubPolicy.h
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESUBPOLICY_H_
#define SOURCE_CORE_CORESUBPOLICY_H_

#include "GHI/GHIClasses.h"

#include <vector>

namespace Core
{
class Policy;
class Renderable;
class RenderTarget;
class SubPolicy
{
public:
	explicit SubPolicy(Policy* policy);
	virtual ~SubPolicy(void);

public:
	void Create(size_t index);

public:
	void Render(GHI::CommandList* command, const std::vector<Renderable*>& renderables);

public:
	inline size_t GetIndex(void) const { return mIndex; }
	inline GHI::Pipeline* GetPipeline(void) const { return mPipeline; }
	inline GHI::FrameBuffer* GetFrameBuffer(void) const { return mFrameBuffer; }

public:
	inline Policy* GetParent(void) const { return mParent; }

public:
	inline size_t GetRenderTargetCount(void) const { return mRenderTargets.size(); }
	inline RenderTarget* GetRenderTarget(size_t index) const { return mRenderTargets.at(index); }

protected:
	virtual void CreatePipeline(void);
	virtual void CreateFrameBuffer(void);

protected:
	size_t mIndex = 0;
	Policy* mParent = nullptr;
	std::vector<RenderTarget*> mRenderTargets = {};

protected:
	GHI::Pipeline* mPipeline = nullptr;
	GHI::FrameBuffer* mFrameBuffer = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESUBPOLICY_H_ */
