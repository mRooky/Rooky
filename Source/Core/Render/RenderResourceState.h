/*
 * RenderResourceList.h
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERRESOURCESTATE_H_
#define SOURCE_CORE_RENDER_RENDERRESOURCESTATE_H_

#include "RenderResource.h"
#include <vector>

namespace Render
{

class ResourceLayout;
class ResourceState
{
public:
	ResourceState(ResourceLayout* layout);
	virtual ~ResourceState(void);

public:
	virtual void Update(void) = 0;

public:
	void AppendResource(const Resource& resource);

protected:
	ResourceLayout* mLayout = nullptr;
	std::vector<Render::Resource> mResources;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCESTATE_H_ */
