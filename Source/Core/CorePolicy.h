/*
 * CorePolicy.h
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREPOLICY_H_
#define SOURCE_CORE_COREPOLICY_H_

#include "CoreInterface.h"
#include "MathExtent2.h"
#include "GHIClasses.h"
#include <cstdint>
#include <vector>

namespace Core
{
class SubPolicy;
class Renderable;
class RenderTarget;

class Policy : public Interface
{
public:
	explicit Policy(System* system);
	virtual ~Policy(void);

public:
	void Create(void);

public:
	void Render(GHI::CommandList* command, const std::vector<Renderable*>& renderables);

public:
	void CreateDepthStencil(const Math::Extent2Di& extent);
	RenderTarget* CreateRenderTarget(void);

public:
	inline RenderTarget* GetDepthStencil(void) const { return mDepthStencil; }
	inline size_t GetRenderTargetCount(void) const { return mRenderTargets.size(); }
	inline RenderTarget* GetRenderTarget(size_t index) const { return mRenderTargets.at(index); }

public:
	inline GHI::RenderPass* GetRenderPass(void) const { return mRenderPass; }

public:
	inline size_t GetSubPolicyCount(void) const { return mSubPolicies.size(); }
	inline SubPolicy* GetSubPolicy(size_t index) const { return mSubPolicies.at(index); }

protected:
	void RenderSub(GHI::CommandList* command, const std::vector<Renderable*>& renderables);

protected:
	std::vector<SubPolicy*> mSubPolicies = {};

protected:
	RenderTarget* mDepthStencil = nullptr;
	std::vector<RenderTarget*> mRenderTargets;

protected:
	GHI::RenderPass* mRenderPass = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPOLICY_H_ */
