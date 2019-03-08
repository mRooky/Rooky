/*
 * VulkanInline.h
 *
 *  Created on: Dec 8, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANINLINE_H_
#define VULKAN_VULKANINLINE_H_

#include <vector>
#include <algorithm>

namespace Vulkan
{

template<class T>
static inline void Release(T*& ptr)
{
	if(ptr != nullptr)
	{
		ptr->Destroy();
	}
	ptr = nullptr;
}

template<class T>
static inline void Release(T*& ptr, bool flag)
{
	if(ptr != nullptr && flag)
	{
		ptr->Destroy();
	}
	ptr = nullptr;
}

}

#endif /* VULKAN_VULKANINLINE_H_ */
