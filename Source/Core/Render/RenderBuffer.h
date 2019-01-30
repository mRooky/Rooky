/*
 * RenderBuffer.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERBUFFER_H_
#define SOURCE_CORE_RENDER_RENDERBUFFER_H_

#include "RenderObject.h"

namespace Render
{
class HardwareBuffer;
class Buffer : public Object
{
public:
	explicit Buffer(Context* context);
	virtual ~Buffer(void) override;

public:
	inline HardwareBuffer* GetHardwareBuffer(void) const { return mHardwareBuffer; }

protected:
	HardwareBuffer* mHardwareBuffer = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBUFFER_H_ */
