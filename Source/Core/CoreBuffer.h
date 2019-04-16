/*
 * CoreBuffer.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREBUFFER_H_
#define SOURCE_CORE_COREBUFFER_H_

#include "CoreResource.h"

namespace Core
{

class Buffer: public Resource
{
public:
	Buffer(void);
	virtual ~Buffer(void) override;

public:
	void Read(void* dst, size_t offset, size_t size);
	void Write(const void* src, size_t offset, size_t size);
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREBUFFER_H_ */
