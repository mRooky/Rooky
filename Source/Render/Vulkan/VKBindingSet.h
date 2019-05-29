/*
 * ResourceList.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKBINDINGSTATE_H_
#define SOURCE_RENDER_VK_VKBINDINGSTATE_H_

#include "../../Core/GHI/GHIBindingSet.h"
#include "../../Core/GHI/GHIUsageType.h"
#include "VKRender.h"

namespace VK
{

class Device;
class BindingSet : public GHI::BindingSet
{
public:
	explicit BindingSet(Device* device);
	virtual ~BindingSet(void) override;

public:
	virtual void Create(void) override;

public:
	inline Vulkan::DescriptorSet* GetDescriptorSet(void) const { return mDescriptorSet; }

public:
	static VkDescriptorType GetDescriptorType(GHI::ResourceType type, const GHI::UsageType& usage);

protected:
	void WriteDescriptorSet(void);
	void AllocateDescriptorSet(void);

protected:
	Vulkan::DescriptorSet* mDescriptorSet = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKBINDINGSTATE_H_ */
