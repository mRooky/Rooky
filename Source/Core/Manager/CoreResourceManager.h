/*
 * CoreResourceManager.h
 *
 *  Created on: Mar 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_CORERESOURCEMANAGER_H_
#define SOURCE_CORE_MANAGER_CORERESOURCEMANAGER_H_

#include "CoreObject.h"

namespace Core
{

class ResourceManager : public Object
{
public:
	explicit ResourceManager(System* system);
	virtual ~ResourceManager(void) override;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_CORERESOURCEMANAGER_H_ */
