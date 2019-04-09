/*
 * UIBitmap.h
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTUITARGET_H_
#define DIRECTUI_DIRECTUITARGET_H_

#include "VulkanClasses.h"

namespace Direct
{

class Target
{
	friend class Surface;
public:
	Target(void);
	virtual ~Target(void);

public:
	inline VkFormat GetFormat(void) const { return mFormat; }

public:
	inline Vulkan::Image* GetImage(void) const { return mImage; }
	inline Vulkan::Sampler* GetSmapler(void) const { return mSampler; }
	inline Vulkan::DeviceMemory* GetMemory(void) const { return mMemory; }

protected:
	void CreateImage(uint32_t width, uint32_t height, VkFormat format);
	void CreateMemory(VkMemoryPropertyFlags property);
	void BindingMemory(Vulkan::DeviceMemory* memory);

protected:
	Vulkan::Image* mImage = nullptr;
	Vulkan::Sampler* mSampler = nullptr;
	Vulkan::DeviceMemory* mMemory = nullptr;

protected:
	uint32_t mWidth = 0;
	uint32_t mHeight = 0;
	VkFormat mFormat = VK_FORMAT_R8G8B8A8_UNORM;
};

} /* namespace UI */

#endif /* DIRECTUI_DIRECTUITARGET_H_ */
