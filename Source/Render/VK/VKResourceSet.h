/*
 * VKResourceSet.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRESOURCESET_H_
#define SOURCE_RENDER_VK_VKRESOURCESET_H_

#include "RenderResourceSet.h"
#include "VKRender.h"

namespace VK
{

class ResourceSet: public Render::ResourceSet
{
	friend class CommandList;
protected:
	ResourceSet(void);
	virtual ~ResourceSet(void) override;

public:
	void UpdateDescriptorSet(void);

public:
	inline Vulkan::DescriptorSet* GetDescriptorSet(void) const { return mDescriptorSet; }

protected:
	Vulkan::DescriptorSet* mDescriptorSet = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCESET_H_ */
