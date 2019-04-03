/*
 * CoreResource.h
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORERESOURCE_H_
#define SOURCE_CORE_CORERESOURCE_H_

#include "CoreBase.h"
#include "RenderClasses.h"

namespace Core
{

class Resource : public Base
{
public:
	Resource(void);
	virtual ~Resource(void) override;

public:
	inline bool IsValid(void) const { return mResource != nullptr; }
	inline Render::Resource* GetRenderResource(void) const { return mResource; }

protected:
	Render::Resource* mResource = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORERESOURCE_H_ */
