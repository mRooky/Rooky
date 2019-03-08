/*
 * RenderPipeline.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINE_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINE_H_

#include "RenderPipelineTraits.h"
#include "RenderObject.h"

namespace Render
{
class Pipeline : public Object
{
public:
	explicit Pipeline(Context* context);
	virtual ~Pipeline(void) override;

public:
	virtual void Initialize(const PipelineTraits& detail) = 0;

public:
	inline const PipelineTraits& GetTraits(void) const { return mTraits; }

protected:
	PipelineTraits mTraits;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINE_H_ */
