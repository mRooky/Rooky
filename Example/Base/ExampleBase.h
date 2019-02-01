/*
 * ExampleBase.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef EXAMPLE_BASE_EXAMPLEBASE_H_
#define EXAMPLE_BASE_EXAMPLEBASE_H_

#include "RenderClasses.h"
#include "CoreViewport.h"
#include "PlatformWindow.h"
#include <cstdint>

namespace Example
{

class Base
{
public:
	explicit Base(const char* title);
	virtual ~Base(void);

public:
	int32_t ShowModal(void);

protected:
	Render::Context* mContext = nullptr;
};

} /* namespace Example */

#endif /* EXAMPLE_BASE_EXAMPLEBASE_H_ */
