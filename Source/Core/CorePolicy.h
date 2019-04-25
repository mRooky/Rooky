/*
 * CorePolicy.h
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREPOLICY_H_
#define SOURCE_CORE_COREPOLICY_H_

#include "GHIClasses.h"

#include <vector>

namespace Core
{
class SubPolicy;
class RenderTarget;
class Policy
{
public:
	Policy(void);
	virtual ~Policy(void);

public:
	SubPolicy* CreateSubPolicy(void);

public:
	inline GHI::RenderPass* GetRenderPass(void) const { return mRenderPass; }

public:
	inline size_t GetSubPolicyCount(void) const { return mSubPolicies.size(); }
	inline SubPolicy* GetSubPolicy(size_t index) const { return mSubPolicies.at(index); }

protected:
	std::vector<SubPolicy*> mSubPolicies = {};
	std::vector<RenderTarget*> mRenderTargets = {};

protected:
	GHI::RenderPass* mRenderPass = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPOLICY_H_ */
