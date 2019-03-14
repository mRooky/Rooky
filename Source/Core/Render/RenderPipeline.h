/*
 * RenderPipeline.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINE_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINE_H_

#include "RenderPipelineInfo.h"
#include "RenderObject.h"

namespace Render
{
class Pipeline : public Object
{
public:
	explicit Pipeline(Context* context);
	virtual ~Pipeline(void) override;

public:
	virtual void Initialize(const PipelineInfo& info) = 0;

public:
	inline const PipelineInfo& GetInfo(void) const { return mInfo; }

protected:
	PipelineInfo mInfo;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINE_H_ */
