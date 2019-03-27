/*
 * VKStaging.h
 *
 *  Created on: Mar 22, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKSTAGING_H_
#define SOURCE_RENDER_VK_VKSTAGING_H_

#include "VKRender.h"
#include <vector>

namespace VK
{
class Buffer;
class Device;
class Staging
{
public:
	explicit Staging(Device* device);
	virtual ~Staging(void);

public:
	Buffer* GetBuffer(size_t size, VkBufferUsageFlags usage);

protected:
	Buffer* SearchBuffer(size_t size, VkBufferUsageFlags usage);

protected:
	Device* mDevice = nullptr;
	std::vector<Buffer*> mBuffers;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKSTAGING_H_ */
