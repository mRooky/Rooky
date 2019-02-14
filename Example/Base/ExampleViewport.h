/*
 * ExampleViewport.h
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#ifndef EXAMPLE_BASE_EXAMPLEVIEWPORT_H_
#define EXAMPLE_BASE_EXAMPLEVIEWPORT_H_

#include "ExampleBase.h"
#include "CoreViewport.h"

namespace Example
{

class Viewport: public Base
{
public:
	Viewport(void);
	virtual ~Viewport(void) override;

public:
	virtual void CreateViewport(void);

public:
	inline Core::Viewport* GetViewport(void) const { return mViewport; }

protected:
	Core::Viewport* mViewport = nullptr;
};

} /* namespace Example */

#endif /* EXAMPLE_BASE_EXAMPLEVIEWPORT_H_ */
