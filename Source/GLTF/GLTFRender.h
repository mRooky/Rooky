/*
 * =====================================================================================
 *
 *       Filename:  GLTFRender.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_RENDER_H
#define SOURCE_GLTF_RENDER_H

#include "../Core/Platform/PlatformWindow.h"
#include "GLTFManager.h"

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
	inline Manager* GetManager(void) const { return mManager; }
	inline Platform::Window* GetWindow(void) const { return mWindow; }

private:
	void CreateWindow(uint32_t width, uint32_t height, const char* title);
	void CreateSwapChain(void);

protected:
	Manager* mManager = nullptr;
	GHI::SwapChain* mSwapChain = nullptr;
	Platform::Window* mWindow = nullptr;
};

}

#endif
