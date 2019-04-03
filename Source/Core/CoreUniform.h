/*
 * CoreUniform.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREUNIFORM_H_
#define SOURCE_CORE_COREUNIFORM_H_

#include "CoreResource.h"
#include "RenderClasses.h"
#include "RenderUsage.h"

#include <cstddef>

namespace Core
{
class BufferManager;
class Uniform : public Resource
{
	friend class BufferManager;
private:
	explicit Uniform(BufferManager* creator);

public:
	virtual ~Uniform(void);

public:
	void Create(size_t size, Render::AllocateType allocate);

public:
	void Read(void* dst, size_t offset, size_t size);
	void Write(const void* src, size_t offset, size_t size);

protected:
	void CreateRenderBuffer(Render::AllocateType allocate);

protected:
	size_t mSize = 0;
	BufferManager* mCreator = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREUNIFORM_H_ */
