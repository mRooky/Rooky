/*
 * =====================================================================================
 *
 *       Filename:  GLTFViewport.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_VIEWPORT_H
#define SOURCE_GLTF_VIEWPORT_H

#include "../Core/GHI/GHIClasses.h"
#include "../Core/Platform/PlatformWindow.h"
#include <vector>

namespace GLTF
{

class Render;
class Viewport
{
public:
	explicit Viewport(Render* parent);
	~Viewport(void);

public:
	void Init(Platform::Window* window);

public:
	inline GHI::SwapChain* GetSwapChain(void) const
	{
		return mSwapChain;
	}

protected:
	void CreateSwapChian(Platform::Window* window);

protected:
	Render* mParent = nullptr;
	GHI::SwapChain* mSwapChain = nullptr;
	GHI::RenderPass* mRenderPass = nullptr;
	std::vector<GHI::FrameBuffer*> mFrameBuffers;
};

}

#endif
