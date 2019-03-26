/*
 * CoreResourceManager.h
 *
 *  Created on: Mar 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_
#define SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_

#include <RenderBinding.hpp>
#include <RenderBindingSet.h>
#include "CoreObject.h"
#include "RenderBindingLayout.h"
#include <vector>

namespace Core
{
class BindingManager : public Object
{
public:
	explicit BindingManager(System* system);
	virtual ~BindingManager(void) override;

public:
	Render::BindingLayout* CreateLayout(void);

protected:
	std::vector<Render::BindingLayout*> mBindingLayouts;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_ */
