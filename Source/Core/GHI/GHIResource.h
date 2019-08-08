/*
 * RenderResource.h
 *
 *  Created on: Mar 20, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERRESOURCE_H_
#define SOURCE_CORE_GHI_RENDERRESOURCE_H_

#include "GHIObject.h"
#include "GHIResourceType.h"

namespace GHI
{

class Resource: public Object
{
protected:
	explicit Resource(Device* device);

public:
	virtual ~Resource(void) override;

public:
	inline ResourceType GetType(void) const
	{
		return mType;
	}

protected:
	ResourceType mType = {};
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_RENDERRESOURCE_H_ */
