/*
 * VulkanDefine.h
 *
 *  Created on: Nov 27, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANDEFINE_H_
#define VULKAN_VULKANDEFINE_H_

#include "VulkanObject.h"
#include <cassert>
#include <iostream>

namespace Vulkan
{

#ifdef VK_RESULT_CHECK
#error "VK_RESULT_CHECK has define"
#else
#define VK_RESULT_CHECK(x, v)\
{\
	if(x != v)\
	{\
		std::cout << "[RESULT] : " << Object::GetResultName(x) << std::endl;\
		assert(x == v);\
	}\
}
#endif

}

#endif /* VULKAN_VULKANDEFINE_H_ */
