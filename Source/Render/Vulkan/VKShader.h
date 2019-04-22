/*
 * VKShader.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKSHADER_H_
#define SOURCE_RENDER_VK_VKSHADER_H_

#include "GHIShader.h"
#include "VKPipelineState.h"
#include "VKRender.h"


namespace VK
{
class Device;
class Shader: public GHI::Shader
{
public:
	explicit Shader(Device* device);
	virtual ~Shader(void) override;

public:
	virtual void Create(const char* file) override;

public:
	inline Vulkan::ShaderModule* GetVulkanModule(void) const { return mShader; }

public:
	static VkShaderStageFlagBits ConvertStage(GHI::ShaderStage stage);

private:
	void CreateVulkanShader(size_t size, const void* data);

protected:
	Vulkan::ShaderModule* mShader = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKSHADER_H_ */
