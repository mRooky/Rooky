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
class BufferManager;
class HardwareBuffer;
class Buffer
{
public:
	explicit Buffer(BufferManager* manager);
	virtual ~Buffer(void);

public:
	inline HardwareBuffer* GetHardwareBuffer(void) const { return mHardwareBuffer; }

protected:
	BufferManager* mManager = nullptr;
	HardwareBuffer* mHardwareBuffer = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBUFFER_H_ */
