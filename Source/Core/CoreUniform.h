/*
 * CoreUniform.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREUNIFORM_H_
#define SOURCE_CORE_COREUNIFORM_H_

#include "CoreBuffer.h"
#include "RenderClasses.h"
#include "RenderUsageType.h"

#include <cstddef>

namespace Core
{
class BufferManager;
class Uniform : public Buffer
{
	friend class BufferManager;
private:
	explicit Uniform(BufferManager* creator);

public:
	virtual ~Uniform(void) override;

public:
	void Create(size_t size, Render::UsageType usage);

protected:
	void CreateRenderBuffer(Render::UsageType usage);

protected:
	size_t mSize = 0;
	BufferManager* mCreator = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREUNIFORM_H_ */
