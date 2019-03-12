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
#include <array>
#include <bitset>

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
	void SetResourceState(uint32_t index, ResourceState* state);

public:
	virtual PipelineLayout* Update(void) = 0;
	virtual ResourceState* CreateState(void) = 0;

public:
	inline void ClearState(void) { mResourceMask.reset(); }
	inline PipelineLayout* GetCurrentLayout(void) const { return mCurrentLayout; }

public:
	inline size_t GetResourceListCount(void) const { return mResourceStates.size(); }
	inline ResourceState* GetResourceList(size_t index) const { return mResourceStates.at(index); }

protected:
	bool mDirty = true;
	PipelineLayout* mCurrentLayout = nullptr;
	std::bitset<8> mResourceMask = 0;
	std::array<ResourceState*, 8> mResourceStates;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCELAYOUT_H_ */
