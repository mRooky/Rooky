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
#include <vector>

namespace Core
{
class Path;
class Pass
{
	friend class Path;
protected:
	explicit Pass(Path* parent);

public:
	virtual ~Pass(void);

public:
	void Create(const std::vector<Render::Format>& formats);

public:
	inline Path* GetParent(void) const { return mParent; }

public:
	inline Render::Pipeline* GetPipeline(void) const { return mPipeline; }
	inline Render::Pass* GetRenderPass(void) const { return mRenderPass; }

protected:
	Path* mParent = nullptr;

protected:
	Render::Pass* mRenderPass = nullptr;
	Render::Pipeline* mPipeline = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPASS_H_ */
