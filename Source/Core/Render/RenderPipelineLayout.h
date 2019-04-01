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
class PipelineLayout : public Object
{
public:
	explicit PipelineLayout(Device* device);
	virtual ~PipelineLayout(void);

public:
	virtual void Create(BindingLayout* layout) = 0;

public:
	inline BindingLayout* GetBindingLayout(void) const { return mBindingLayout; }

protected:
	BindingLayout* mBindingLayout = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINELAYOUT_H_ */
