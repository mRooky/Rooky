/*
 * DirectWindow.h
 *
 *  Created on: Nov 1, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTWINDOW_H_
#define DIRECTUI_DIRECTWINDOW_H_

#include "../Platform/Vulkan/VulkanClasses.h"
#include <vector>

namespace Direct
{
class Context;
class Surface;
class Window
{
public:
	Window(void);
	virtual ~Window(void);

public:
	void Create(Vulkan::Device* device, int32_t width, int32_t height);

public:
	void Resize(int32_t width, int32_t height);

public:
	void Show(void);

public:
	inline int32_t GetWidth(void) const { return m_width; }
	inline int32_t GetHeight(void) const { return m_height; }

public:
	inline Context* GetContext(void) const { return m_context; }
	inline Surface* GetSurface(void) const { return m_surface; }

private:
	void CreateSurface(VkFormat format);
	void DestroySurface(void);

private:
	int32_t m_width = 0;
	int32_t m_height = 0;

private:
	Context* m_context = nullptr;
	Surface* m_surface = nullptr;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTWINDOW_H_ */
