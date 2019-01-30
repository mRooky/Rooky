/*
 * HardwareBuffer.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERHARDWAREBUFFER_H_
#define SOURCE_CORE_RENDER_RENDERHARDWAREBUFFER_H_

#include "RenderResource.h"

namespace Render
{

class HardwareBuffer : public Resource
{
public:
	explicit HardwareBuffer(Context* context);
	virtual ~HardwareBuffer(void) override;

public:
	virtual void Initialize(size_t size, uint32_t usage) = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERHARDWAREBUFFER_H_ */
