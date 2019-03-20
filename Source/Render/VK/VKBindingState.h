/*
 * ResourceList.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKBINDINGSTATE_H_
#define SOURCE_RENDER_VK_VKBINDINGSTATE_H_

#include "RenderBindingState.h"
#include "VKRender.h"

namespace VK
{

class BindingLayout;
class BindingState : public Render::BindingState
{
public:
	explicit BindingState(BindingLayout* layout);
	virtual ~BindingState(void) override;

public:
	virtual void Update(void) override;

public:
	inline Vulkan::DescriptorSet* GetDescriptorSet(void) const { return mDescriptorSet; }

public:
	static VkDescriptorType GetDescriptorType(Render::ResourceFlag type);

public:
	static void SetImageInfo(const Render::Binding& binding, VkDescriptorImageInfo* info);
	static void SetUniformInfo(const Render::Binding& binding, VkDescriptorBufferInfo* info);
	static void SetSamplerInfo(const Render::Binding& binding, VkDescriptorImageInfo* info);

protected:
	void WriteDescriptorSet(void);
	void UpdateDescriptorSet(void);

protected:
	Vulkan::DescriptorSet* mDescriptorSet = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKBINDINGSTATE_H_ */
