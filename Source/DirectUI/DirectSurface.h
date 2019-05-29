/*
 * DirectSurface.h
 *
 *  Created on: Oct 16, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTSURFACE_H_
#define DIRECTUI_DIRECTSURFACE_H_

#include "../Platform/Vulkan/VulkanClasses.h"
#include <vector>

namespace Direct
{
class Target;
class Widget;
class Window;
class Painter;
class Surface
{
	friend class Window;
private:
	explicit Surface(Window* parent);
	virtual ~Surface(void);

public:
	void Create(uint32_t width, uint32_t height, VkFormat format);

public:
	void BeginFrame(void);
	void Draw(Widget* widget);
	void EndFrame(void);

public:
	Painter* CreatePainter(void);

public:
	inline Window* GetParent(void) const { return m_parent; }
	inline Target* GetTarget(void) const { return m_frontend; }

public:
	inline Vulkan::RenderPass* GetRenderPass(void) const { return m_renderPass; }
	inline Vulkan::FrameBuffer* GetFrameBuffer(void) const { return m_frameBuffer; }
	inline Vulkan::CommandPool* GetCommandPool(void) const { return m_commandPool; }
	inline Vulkan::CommandBuffer* GetCommandBuffer(void) const { return m_commandBuffer; }

private:
	void CreateTarget(VkFormat format);

private:
	void CreateCommandPool(void);
	void CreateCommandBuffer(void);

private:
	void CreateRenderPass(void);
	void CreateFrameBuffer(void);

private:
	void CopyTargets(void);

private:
	int32_t m_width = 0;
	int32_t m_height = 0;

private:
	Window* m_parent = nullptr;

private:
	Target* m_backend = nullptr;
	Target* m_frontend = nullptr;
	std::vector<VkImageCopy> m_copyRegions;

private:
	std::vector<Painter*> m_painters;

private:
	Vulkan::RenderPass* m_renderPass = nullptr;
	Vulkan::FrameBuffer* m_frameBuffer = nullptr;

private:
	Vulkan::CommandPool* m_commandPool = nullptr;
	Vulkan::CommandBuffer* m_commandBuffer = nullptr;

};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTSURFACE_H_ */
