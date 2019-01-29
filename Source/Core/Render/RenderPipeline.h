/*
 * RenderPipeline.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINE_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINE_H_

#include "RenderObject.h"

namespace Render
{
class Pass;
class Pipeline : public Object
{
public:
	explicit Pipeline(Context* context);
	virtual ~Pipeline(void) override;

public:
	inline Pass* GetRenderPass(void) const { return mRenderPass; }

protected:
	Pass* mRenderPass = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINE_H_ */
