/*
 * CoreResourceManager.h
 *
 *  Created on: Mar 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_
#define SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_

#include "../CoreInterface.h"
#include "../GHI/GHIClasses.h"
#include <vector>

namespace Core
{
class BindingManager : public Interface
{
public:
	explicit BindingManager(System* system);
	virtual ~BindingManager(void) override;

public:
	GHI::BindingSet* CreateSet(void);
	GHI::BindingLayout* CreateLayout(void);

protected:
	std::vector<GHI::BindingSet*> mBindingSets;
	std::vector<GHI::BindingLayout*> mBindingLayouts;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_COREBINDINGMANAGER_H_ */
