/*
 * =====================================================================================
 *
 *       Filename:  GLTFRender.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_RENDER_H
#define SOURCE_GLTF_RENDER_H

#include "../Core/CoreSystem.h"
#include "../Core/Platform/PlatformWindow.h"
#include <cstdint>

namespace GLTF
{

class Render
{
public:
	Render(void);
	~Render(void);

public:
	Platform::Window* Init(uint32_t width, uint32_t height, const char* title);

public:


private:
	Core::System* m_system = nullptr;
	Platform::Window* m_window = nullptr;
};

}

#endif
