/*
 * ExampleGLTF.h
 *
 * Created on: Jun 3, 2019
 *     Author: rookyma
 */

#ifndef EXAMPLE_EXAMPLEGLTF_H_
#define EXAMPLE_EXAMPLEGLTF_H_

#include "ExampleBuffer.h"

namespace Example
{

class GLTF : public Buffer
{
public:
	GLTF(void);
	virtual ~GLTF(void) override;

public:
	virtual void Initialize(void) override;
	virtual void RecordCommands(void) override;

protected:
	virtual void CreateBRDF(void);
};

}

#endif
