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
class ResourceLayout;
class PipelineLayout
{
public:
	explicit PipelineLayout(ResourceLayout* layout);
	virtual ~PipelineLayout(void);

public:
	inline ResourceLayout* GetResourceLayout(void) const { return mResourceLayout; }

protected:
	ResourceLayout* mResourceLayout = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINELAYOUT_H_ */
