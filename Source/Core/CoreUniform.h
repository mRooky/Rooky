/*
 * CoreUniform.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREUNIFORM_H_
#define SOURCE_CORE_COREUNIFORM_H_

#include "CoreBuffer.h"

namespace Core
{

class Uniform: public Buffer
{
	friend class BufferManager;
private:
	explicit Uniform(BufferManager* creator);

public:
	virtual ~Uniform(void) override;

public:
	void Create(size_t size, Render::ResourceHeap heap);
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREUNIFORM_H_ */
