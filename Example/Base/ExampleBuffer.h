/*
 * ExampleBuffer.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef EXAMPLE_BASE_EXAMPLEBUFFER_H_
#define EXAMPLE_BASE_EXAMPLEBUFFER_H_

#include "ExampleBase.h"
#include "CoreIndex.h"
#include "CoreVertex.h"
#include "CoreUniform.h"

namespace Example
{

class Buffer: public Base
{
public:
	Buffer(void);
	virtual ~Buffer(void) override;

public:
	virtual void CreateBuffer(void);

protected:
	Core::Index* mIndex = nullptr;
	Core::Vertex* mVertex = nullptr;
	Core::Uniform* mUniform = nullptr;
};

} /* namespace Example */

#endif /* EXAMPLE_BASE_EXAMPLEBUFFER_H_ */
