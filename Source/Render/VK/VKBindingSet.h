/*
 * ResourceList.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKBINDINGSTATE_H_
#define SOURCE_RENDER_VK_VKBINDINGSTATE_H_

#include <RenderBindingSet.h>
#include "RenderUsage.h"
#include "VKRender.h"

namespace VK
{

class BindingLayout;
class BindingSet : public Render::BindingSet
{
public:
	explicit BindingSet(BindingLayout* layout);
	virtual ~BindingSet(void) override;

public:
	virtual void Update(void) override;
	virtual void SetBinding(uint32_t index, const Render::Binding& binding) override;

public:
	inline Vulkan::DescriptorSet* GetDescriptorSet(void) const { return mDescriptorSet; }

public:
	static void SetImageInfo(const Render::Binding* binding, VkDescriptorImageInfo* info);
	static void SetUniformInfo(const Render::Binding* binding, VkDescriptorBufferInfo* info);
	static void SetSamplerInfo(const Render::Binding* binding, VkDescriptorImageInfo* info);

public:
	static VkDescriptorType GetDescriptorType(Render::ResourceType type, const Render::ResourceUsage& usage);

protected:
	void WriteDescriptorSet(void);
	void UpdateDescriptorSet(void);

protected:


protected:
	Vulkan::DescriptorSet* mDescriptorSet = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKBINDINGSTATE_H_ */
