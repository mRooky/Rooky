/*
 * RenderPipeline.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERPIPELINE_H_
#define SOURCE_CORE_GHI_RENDERPIPELINE_H_

#include "GHIObject.h"
#include <cstdint>

namespace GHI
{
class PipelineState;
class Pipeline : public Object
{
public:
	explicit Pipeline(Device* device);
	virtual ~Pipeline(void) override;

public:
	virtual void Create(PipelineState* state) = 0;

public:
	bool IsValid(void) const;

public:
	inline PipelineState* GetState(void) const { return mPipelineState; }

protected:
	PipelineState* mPipelineState = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERPIPELINE_H_ */
