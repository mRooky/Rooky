/*
 * CoreResourceManager.h
 *
 *  Created on: Mar 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_
#define SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_

#include "CoreObject.h"
#include "RenderClasses.h"
#include <vector>

namespace Core
{
class BindingManager : public Object
{
public:
	explicit BindingManager(System* system);
	virtual ~BindingManager(void) override;

public:
	Render::BindingSet* CreateSet(void);
	Render::BindingLayout* CreateLayout(void);

protected:
	std::vector<Render::BindingSet*> mBindingSets;
	std::vector<Render::BindingLayout*> mBindingLayouts;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_ */
