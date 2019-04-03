/*
 * CoreMaterialManager.h
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_COREMATERIALMANAGER_H_
#define SOURCE_CORE_MANAGER_COREMATERIALMANAGER_H_

#include "CoreObject.h"

namespace Core
{

class MaterialManager: public Object
{
public:
	explicit MaterialManager(System* system);
	virtual ~MaterialManager(void) override;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_COREMATERIALMANAGER_H_ */
