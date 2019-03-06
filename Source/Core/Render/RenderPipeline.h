/*
 * RenderPipeline.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINE_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINE_H_

#include "RenderObject.h"
#include "RenderPipelineDetail.h"

namespace Render
{
class Pipeline : public Object
{
public:
	explicit Pipeline(Context* context);
	virtual ~Pipeline(void) override;

public:
	virtual void Initialize(const PipelineDetail& detail) = 0;

public:
	inline const PipelineDetail& GetDetail(void) const { return mDetail; }

protected:
	PipelineDetail mDetail;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINE_H_ */
