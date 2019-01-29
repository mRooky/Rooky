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

template<typename T>
static inline auto Find(const std::vector<T>& container, T& value)
{
	auto iterator = std::find(container.begin(), container.end(), value);
	return iterator != container.end();
}

}

#endif /* VULKAN_VULKANINLINE_H_ */
