/*
 * ExampleRenderPass.h
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#ifndef EXAMPLE_BASE_EXAMPLEPATH_H_
#define EXAMPLE_BASE_EXAMPLEPATH_H_

#include "ExampleViewport.h"
#include "CorePath.h"
#include "CoreThread.h"
#include "RenderFormat.h"

namespace Example
{

class Path: public Viewport
{
public:
	Path(void);
	virtual ~Path(void) override;

public:
	virtual void CreateRenderPath(void);
	virtual void CreateRenderPass(const std::vector<Render::Format>& formats, Render::Format depth);
	virtual void CreateFrameBuffer(const std::vector<Render::Image*>& attachments, Render::Image* depth);
	virtual void CreateRenderThread(size_t count);

protected:
	Core::Path* mPath = nullptr;
	Core::Thread* mThread = nullptr;
	std::vector<Render::CommandList*> mCommandLists;
};

} /* namespace Example */

#endif /* EXAMPLE_BASE_EXAMPLEPATH_H_ */
