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
class ResourceList;
class PipelineLayout;
class ResourceLayout : public Object
{
public:
	explicit ResourceLayout(Context* context);
	virtual ~ResourceLayout(void) override;

public:
	void AppendResourceList(ResourceList* list);

public:
	virtual PipelineLayout* Update(void) = 0;

public:
	inline PipelineLayout* GetCurrentLayout(void) const { return mCurrentLayout; }
	inline ResourceList* GetResourceList(size_t index) const { return mResourceLists.at(index); }

protected:
	bool mDirty = true;
	PipelineLayout* mCurrentLayout = nullptr;
	std::vector<ResourceList*> mResourceLists;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCELAYOUT_H_ */
