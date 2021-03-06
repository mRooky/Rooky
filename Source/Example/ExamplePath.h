/*
 * ExampleRenderPass.h
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#ifndef EXAMPLE_EXAMPLEPATH_H_
#define EXAMPLE_EXAMPLEPATH_H_

#include "../Core/CorePass.h"

#include "ExampleBase.h"

namespace Example
{

class Path: public Base
{
public:
	Path(void);
	virtual ~Path(void) override;

public:
	virtual void CreateRenderPass(void);
	virtual void CreateRenderThread(size_t count);
	virtual void CreateViewport(void);

protected:
	Core::Pass* mPass = nullptr;
	Core::Thread* mThread = nullptr;
	Core::Viewport* mViewport = nullptr;
};

} /* namespace Example */

#endif /* EXAMPLE_EXAMPLEPATH_H_ */
