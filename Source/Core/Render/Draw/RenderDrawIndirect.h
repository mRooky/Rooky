/*
 * RenderDrawIndirect.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_DRAW_RENDERDRAWINDIRECT_H_
#define SOURCE_CORE_RENDER_DRAW_RENDERDRAWINDIRECT_H_

#include <Draw/RenderDrawCall.h>
#include <cstddef>

namespace Render
{
class Buffer;
class Device;
class DrawIndirect : public DrawCall
{
public:
	DrawIndirect(void);
	virtual ~DrawIndirect(void) override;

public:
	void Create(Device* device, size_t size);

public:
	inline size_t GetSize(void) const { return mSize; }
	inline Buffer* GetBuffer(void) const { return mBuffer; }
	inline uint32_t GetOffset(void) const { return mOffset; }
	inline uint32_t GetDrawCount(void) const { return mDrawCount; }

public:
	inline void SetOffset(uint32_t offset) { mOffset = offset; }
	inline void SetDrawCount(uint32_t count) { mDrawCount = count; }

protected:
	Buffer* mBuffer = nullptr;

protected:
	size_t mSize = 0;
	uint32_t mOffset = 0;
	uint32_t mDrawCount = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_DRAW_RENDERDRAWINDIRECT_H_ */
