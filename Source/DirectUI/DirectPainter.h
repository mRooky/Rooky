/*
 * DirectPainter.h
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTPAINTER_H_
#define DIRECTUI_DIRECTPAINTER_H_

#include "VulkanClasses.h"
#include <vector>

namespace Direct
{
class Surface;
class Painter
{
	friend class Surface;
private:
	explicit Painter(Surface* surface);
	virtual ~Painter(void);

public:
	void Create(std::vector<Vulkan::DescriptorSetLayout*> layouts);

public:
	void Binding(Vulkan::CommandBuffer* buffer);

private:
	void CreatePipelineLayout(void);
	void CreatePipelineCache(void);
	void CreatePipeline(void);

private:
	Vulkan::ShaderModule* m_vertShader = nullptr;
	Vulkan::ShaderModule* m_fragShader = nullptr;

private:
	Surface* m_parent = nullptr;

private:
	Vulkan::Pipeline* m_pipeline = nullptr;
	Vulkan::PipelineCache* m_pipelineCache = nullptr;
	Vulkan::PipelineLayout* m_pipelineLayout = nullptr;

private:
	std::vector<Vulkan::DescriptorSetLayout*> m_descriptorSetLayouts;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTPAINTER_H_ */
