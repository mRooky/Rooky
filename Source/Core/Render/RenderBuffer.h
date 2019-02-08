/*
 * HardwareBuffer.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERBUFFER_H_
#define SOURCE_CORE_RENDER_RENDERBUFFER_H_

#include "RenderResource.h"

namespace Render
{

class Buffer : public Resource
{
public:
	explicit Buffer(Context* context);
	virtual ~Buffer(void) override;

public:
	virtual void Initialize(size_t size, uint32_t usage) = 0;

public:
	virtual void Copy(const Buffer& other) = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBUFFER_H_ */
