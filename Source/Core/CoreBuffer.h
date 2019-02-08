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

class Buffer
{
public:
	Buffer(void);
	virtual ~Buffer(void);

public:
	inline Render::Buffer* GetBuffer(void) const { return mBuffer; }

protected:
	Render::Buffer* mBuffer = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREBUFFER_H_ */
