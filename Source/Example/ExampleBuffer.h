/*
 * ExampleBuffer.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef EXAMPLE_EXAMPLEBUFFER_H_
#define EXAMPLE_EXAMPLEBUFFER_H_

#include "../Core/CoreIndex.h"
#include "../Core/CoreVertex.h"
#include "../Core/CoreUniform.h"

#include "ExamplePath.h"

namespace Example
{

class Buffer: public Path
{
public:
	Buffer(void);
	virtual ~Buffer(void) override;

public:
	virtual void Initialize(void) override;

public:
	virtual int32_t ShowModal(void) override;
	virtual void RecordCommands(void) override;

public:
	virtual void CreateSubPass(void);
	virtual void CreateFrameBuffer(void);
	virtual void CreateIndexBuffer(void);
	virtual void CreateVertexBuffer(void);
	virtual void CreateUniformBuffer(void);

protected:
	Core::SubPass* mSubPass = nullptr;
	Core::Index* mIndex = nullptr;
	Core::Vertex* mVertex = nullptr;
	Core::Uniform* mUniform = nullptr;

protected:

};

} /* namespace Example */

#endif /* EXAMPLE_EXAMPLEBUFFER_H_ */
