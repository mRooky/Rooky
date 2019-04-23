/*
 * CoreSubPolicy.h
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESUBPOLICY_H_
#define SOURCE_CORE_CORESUBPOLICY_H_

#include "GHIClasses.h"

#include <vector>

namespace Core
{
class Policy;
class RenderTarget;
class SubPolicy
{
public:
	explicit SubPolicy(Policy* policy);
	virtual ~SubPolicy(void);

public:
	void Create(size_t index);

public:
	inline size_t GetIndex(void) const { return mIndex; }
	inline GHI::Pipeline* GetPipeline(void) const { return mPipeline; }
	inline GHI::FrameBuffer* GetFrameBuffer(void) const { return mFrameBuffer; }

public:
	inline Policy* GetParentPolicy(void) const { return mParentPolicy; }
	inline size_t GetRenderTargetCount(void) const { return mRenderTargets.size(); }
	inline RenderTarget* GetRenderTarget(size_t index) const { return mRenderTargets.at(index); }

protected:
	void CreatePipeline(void);
	void CreateFrameBuffer(void);

protected:
	size_t mIndex = 0;
	Policy* mParentPolicy = nullptr;
	std::vector<RenderTarget*> mRenderTargets = {};

protected:
	GHI::Pipeline* mPipeline = nullptr;
	GHI::FrameBuffer* mFrameBuffer = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESUBPOLICY_H_ */
