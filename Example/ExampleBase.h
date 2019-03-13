/*
 * ExampleBase.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef EXAMPLE_EXAMPLEBASE_H_
#define EXAMPLE_EXAMPLEBASE_H_

#include "CoreSystem.h"
#include "CoreViewport.h"
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
	virtual void Initialize(void);

public:
	virtual void CreateWindow(const char* title);
	virtual void CreateSystem(void);

public:
	virtual void RecordCommands(void) = 0;

public:
	virtual int32_t ShowModal(void) = 0;

protected:
	Core::System* mSystem = nullptr;
	Platform::Window* mWindow = nullptr;
};

} /* namespace Example */

#endif /* EXAMPLE_EXAMPLEBASE_H_ */
