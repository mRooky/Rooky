/*
 * Object.h
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_

#include <vulkan/vulkan.h>
#include "VulkanBase.h"

namespace Vulkan
{

class ROOKY_EXPORT Object : public Base
{
protected:
	Object(void);
	virtual ~Object(void) override;

public:
	inline VkResult GetResult(void) const { return mResult; }

public:
	static const char* GetResultName(VkResult result);

protected:
	VkResult mResult = VK_INCOMPLETE;

};

} /* namespace Vulkan */

#endif /* BASEOBJECT_H_ */
