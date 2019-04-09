/*
 * CoreStream.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESTREAM_H_
#define SOURCE_CORE_CORESTREAM_H_

#include "CoreStreamType.h"
#include <array>

namespace Core
{

class Stream
{
public:
	Stream(void);
	~Stream(void);

public:
	void* GetBuffer(StreamType type);
	void* Allocate(StreamType type, size_t size, bool discard);

protected:
	void FreeAllBuffer(void);
	void FreeBuffer(StreamType type);

protected:
	std::array<uint8_t*, STREAM_TYPE_COUNT> mBuffers;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESTREAM_H_ */
