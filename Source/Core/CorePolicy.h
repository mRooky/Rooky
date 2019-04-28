/*
 * CorePolicy.h
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREPOLICY_H_
#define SOURCE_CORE_COREPOLICY_H_

#include "GHIClasses.h"
#include <cstdint>
#include <vector>

namespace Core
{
class SubPolicy;
class Renderable;
class RenderTarget;

enum class PolicyType : uint32_t
{
	FORWARD = 1,
	DEFERRED = 2,
	DEPTH_ONLY = 3,
	EXTERNAL = 4,
	UNKNOWN = ~0U
};

class Policy
{
public:
	explicit Policy(PolicyType type);
	virtual ~Policy(void);

public:
	void Render(GHI::CommandList* command, const std::vector<Renderable*>& renderables);

public:
	SubPolicy* CreateSubPolicy(void);

public:
	inline PolicyType GetType(void) const { return mType; }
	inline GHI::RenderPass* GetRenderPass(void) const { return mRenderPass; }

public:
	inline size_t GetSubPolicyCount(void) const { return mSubPolicies.size(); }
	inline SubPolicy* GetSubPolicy(size_t index) const { return mSubPolicies.at(index); }

protected:
	PolicyType mType = PolicyType::UNKNOWN;

protected:
	std::vector<SubPolicy*> mSubPolicies = {};
	std::vector<RenderTarget*> mRenderTargets = {};

protected:
	GHI::RenderPass* mRenderPass = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPOLICY_H_ */
