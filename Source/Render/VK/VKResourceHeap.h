/*
 * VKHeap.h
 *
 *  Created on: Mar 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRESOURCEHEAP_H_
#define SOURCE_RENDER_VK_VKRESOURCEHEAP_H_

#include "VKRender.h"

#include <vector>

namespace VK
{
class Buffer;
class Context;
class ResourceHeap
{
public:
	ResourceHeap(Context* context);
	virtual ~ResourceHeap(void);

public:
	Buffer* AcquireBuffer(size_t size, VkBufferUsageFlags usage, bool cpu);

protected:
	Buffer* BufferFind(size_t size, VkBufferUsageFlags usage, bool cpu);

protected:
	Context* mContext = nullptr;
	std::vector<Buffer*> mBuffers;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCEHEAP_H_ */
