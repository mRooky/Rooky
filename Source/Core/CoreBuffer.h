/*
 * CoreBuffer.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREBUFFER_H_
#define SOURCE_CORE_COREBUFFER_H_

#include "RenderEnum.h"
#include "RenderClasses.h"
#include "RenderUsage.h"
#include <cstdint>
#include <cstddef>

namespace Core
{
class BufferManager;
class Buffer
{
protected:
	explicit Buffer(BufferManager* creator);
	virtual ~Buffer(void);

public:
	void Create(size_t size, Render::ResourceUsage usage);

public:
	void Read(void* dst, size_t offset, size_t size);
	void Write(const void* src, size_t offset, size_t size);

public:
	inline BufferManager* GetCreator(void) const {return mCreator; }
	inline Render::Buffer* GetBuffer(void) const { return mBuffer; }

protected:
	BufferManager* mCreator = nullptr;
	Render::Buffer* mBuffer = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREBUFFER_H_ */
