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
	GHI::Image* CreateAttachment(void);

public:
	inline GHI::Image* GetDepthStencil(void) const { return mDepthStencil; }
	inline size_t GetAttachmentCount(void) const { return mAttachments.size(); }
	inline GHI::Image* GetAttachment(size_t index) const { return mAttachments.at(index); }

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
	GHI::Image* mDepthStencil = nullptr;
	std::vector<GHI::Image*> mAttachments;

protected:
	GHI::RenderPass* mRenderPass = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPOLICY_H_ */
