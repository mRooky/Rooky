/*
 * RenderPipeline.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINE_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINE_H_

#include "RenderObject.h"
#include "RenderPipelineDescription.h"

namespace Render
{
class Pipeline : public Object
{
public:
	explicit Pipeline(Context* context);
	virtual ~Pipeline(void) override;

public:
	virtual void Initialize(const PipelineDescription& desc) = 0;

public:
	inline const PipelineDescription& GetTraits(void) const { return mDescription; }

protected:
	PipelineDescription mDescription;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINE_H_ */
