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
#include "RenderBindingState.h"
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
	Render::BindingState* CreateState(void);
	Render::BindingLayout* CreateLayout(void);

protected:
	std::vector<Render::BindingState*> mBindingStates;
	std::vector<Render::BindingLayout*> mBindingLayouts;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_ */
