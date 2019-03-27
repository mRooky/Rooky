/*
 * VKShader.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKSHADER_H_
#define SOURCE_RENDER_VK_VKSHADER_H_

#include "RenderShader.h"
#include "VKRender.h"

#include "VKPipelineState.h"

namespace VK
{
class Device;
class Shader: public Render::Shader
{
public:
	explicit Shader(Device* device);
	virtual ~Shader(void) override;

public:
	virtual void Create(Render::ShaderStage stage, const char* file) override;
	virtual void Create(Render::ShaderStage stage, size_t size, const void* data) override;

public:
	inline Vulkan::ShaderModule* GetVulkanModule(void) const { return mShader; }

public:
	static VkShaderStageFlagBits ConvertStage(Render::ShaderStage stage);

protected:
	Vulkan::ShaderModule* mShader = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKSHADER_H_ */
