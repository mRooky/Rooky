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
#include <vector>

namespace Render
{
class ResourceState;
class PipelineLayout;
class ResourceLayout : public Object
{
public:
	explicit ResourceLayout(Context* context);
	virtual ~ResourceLayout(void) override;

public:
	void AppendResourceState(ResourceState* state);

public:
	virtual PipelineLayout* Update(void) = 0;

public:
	inline PipelineLayout* GetCurrentLayout(void) const { return mCurrentLayout; }

public:
	inline size_t GetResourceListCount(void) const { return mResourceStates.size(); }
	inline ResourceState* GetResourceList(size_t index) const { return mResourceStates.at(index); }

protected:
	bool mDirty = true;
	PipelineLayout* mCurrentLayout = nullptr;
	std::vector<ResourceState*> mResourceStates;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCELAYOUT_H_ */
