/*
 * RenderResourceLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERRESOURCELAYOUT_H_
#define SOURCE_CORE_RENDER_RENDERRESOURCELAYOUT_H_

#include "RenderObject.h"
#include <cstddef>

namespace Render
{
class ResourceList;
class PipelineLayout;
class ResourceLayout : public Object
{
public:
	explicit ResourceLayout(Context* context);
	virtual ~ResourceLayout(void) override;

public:
	virtual PipelineLayout* UpdatePipelineLayout(void) = 0;
	virtual ResourceList* GetResourceList(size_t index) = 0;

public:
	inline PipelineLayout* GetCurrentLayout(void) const { return mCurrentLayout; }

protected:
	bool mDirty = true;
	PipelineLayout* mCurrentLayout = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCELAYOUT_H_ */
