/*
 * ExampleRenderPass.h
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#ifndef EXAMPLE_EXAMPLEPATH_H_
#define EXAMPLE_EXAMPLEPATH_H_

#include "CorePath.h"
#include "CoreThread.h"
#include "RenderFormat.h"
#include "ExampleViewport.h"

namespace Example
{

class Path: public Viewport
{
public:
	Path(void);
	virtual ~Path(void) override;

public:
	virtual void CreateRenderPath(void);
	virtual void CreateRenderThread(size_t count);

protected:
	Core::Path* mPath = nullptr;
	Core::Thread* mThread = nullptr;
	std::vector<Render::CommandList*> mCommandLists;
};

} /* namespace Example */

#endif /* EXAMPLE_EXAMPLEPATH_H_ */
