/*
 * RenderResource.h
 *
 *  Created on: Mar 20, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERRESOURCE_H_
#define SOURCE_CORE_RENDER_RENDERRESOURCE_H_

#include "RenderObject.h"
#include "RenderUsage.h"

namespace Render
{

class Resource: public Object
{
public:
	explicit Resource(Device* device);
	virtual ~Resource(void) override;

public:
	inline ResourceType GetType(void) const { return mType; }
	inline const ResourceUsage& GetUsage(void) const { return mUsage; }

protected:
	ResourceUsage mUsage = {};
	ResourceType mType = ResourceType::RESOURCE_TYPE_UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCE_H_ */
