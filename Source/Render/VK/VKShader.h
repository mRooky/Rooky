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
class Context;
class Shader: public Render::Shader
{
public:
	explicit Shader(Context* context);
	virtual ~Shader(void) override;

public:
	virtual void Create(const char* file) override;

public:
	inline Vulkan::ShaderModule* GetModuleVK(void) const { return mShader; }

public:
	ShaderStageCreateInfo GetStageCreateInfo(VkShaderStageFlagBits stage) const;

protected:
	Vulkan::ShaderModule* mShader = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKSHADER_H_ */
