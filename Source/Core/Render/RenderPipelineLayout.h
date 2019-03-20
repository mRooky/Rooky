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
class BindingLayout;
class PipelineLayout
{
public:
	explicit PipelineLayout(BindingLayout* layout);
	virtual ~PipelineLayout(void);

public:
	inline BindingLayout* GetResourceLayout(void) const { return mBindingLayout; }

protected:
	BindingLayout* mBindingLayout = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINELAYOUT_H_ */
