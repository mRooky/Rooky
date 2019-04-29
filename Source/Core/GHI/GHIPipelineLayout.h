/*
 * RenderPipelineLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERPIPELINELAYOUT_H_
#define SOURCE_CORE_GHI_RENDERPIPELINELAYOUT_H_

#include "GHIObject.h"
#include "GHIVertexLayout.h"

namespace GHI
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
	void PushVertexElement(const VertexElement& element);
	void PushVertexElement(uint32_t binding, const VertexElement& element);

public:
	inline BindingLayout* GetBindingLayout(void) const { return mBindingLayout; }
	inline const VertexLayout& GetVertexLayout(void) const { return mVertexLayout; }

protected:
	VertexLayout mVertexLayout = {};
	BindingLayout* mBindingLayout = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERPIPELINELAYOUT_H_ */
