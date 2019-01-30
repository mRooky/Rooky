/*
 * ExampleBase.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef EXAMPLE_BASE_EXAMPLEBASE_H_
#define EXAMPLE_BASE_EXAMPLEBASE_H_

#include "RenderContext.h"
#include "PlatformWindow.h"
#include <cstdint>

namespace Example
{

class Base
{
public:
	Base(void);
	virtual ~Base(void);

public:
	int32_t ShowModal(void);

public:
	void CreateWindow(const char* title);

protected:
	Platform::Window* mWindow = nullptr;
	Render::Context* mContext = nullptr;
};

} /* namespace Example */

#endif /* EXAMPLE_BASE_EXAMPLEBASE_H_ */
