/*
 * RenderPipelineLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINELAYOUT_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINELAYOUT_H_

#include "RenderObject.h"

namespace Render
{

class PipelineLayout : public Object
{
public:
	explicit PipelineLayout(Context* context);
	virtual ~PipelineLayout(void) override;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINELAYOUT_H_ */
