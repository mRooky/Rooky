/*
 * CoreResourceManager.h
 *
 *  Created on: Mar 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_
#define SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_

#include "CoreObject.h"
#include "RenderBinding.h"
#include <vector>

namespace Core
{

class BindingManager : public Object
{
public:
	explicit BindingManager(System* system);
	virtual ~BindingManager(void) override;

protected:
	std::vector<Render::Binding> mBindings;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_ */
