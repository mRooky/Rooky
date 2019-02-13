/*
 * CoreBuffer.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREBUFFER_H_
#define SOURCE_CORE_COREBUFFER_H_

#include "RenderClasses.h"

namespace Core
{
class BufferManager;
class Buffer
{
	friend class BufferManager;
protected:
	explicit Buffer(BufferManager* creator);
	virtual ~Buffer(void);

public:
	inline BufferManager* GetCreator(void) const {return mCreator; }
	inline Render::Buffer* GetBuffer(void) const { return mBuffer; }

protected:
	BufferManager* mCreator = nullptr;
	Render::Buffer* mBuffer = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREBUFFER_H_ */
