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
#include "GHIResourceUsage.h"

namespace GHI
{

class Resource: public Object
{
protected:
	explicit Resource(Device* device);

public:
	virtual ~Resource(void) override;

public:
	inline const ResourceType& GetType(void) const
	{
		return mType;
	}

	inline const ResourceUsage& GetUsage(void) const
	{
		return mUsage;
	}

protected:
	ResourceType mType;
	ResourceUsage mUsage;

};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_RENDERRESOURCE_H_ */
