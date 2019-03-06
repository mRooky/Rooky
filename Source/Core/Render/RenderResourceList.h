/*
 * RenderResourceList.h
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERRESOURCELIST_H_
#define SOURCE_CORE_RENDER_RENDERRESOURCELIST_H_

#include "RenderResource.h"

namespace Render
{
class ResourceLayout;
class ResourceList
{
public:
	ResourceList(ResourceLayout* layout);
	virtual ~ResourceList(void);

protected:
	ResourceLayout* mLayout = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCELIST_H_ */
