/*
 * CoreStreamData.h
 *
 *  Created on: Apr 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESTREAMDATA_H_
#define SOURCE_CORE_CORESTREAMDATA_H_

#include "CoreStreamType.h"
#include "CoreData.h"
#include <cstddef>
#include <array>

namespace Core
{

class StreamData
{
public:
	StreamData(void);
	virtual ~StreamData(void);

public:
	Data* GetBuffer(StreamType type);
	Data* Allocate(StreamType type, size_t size);

protected:
	void FreeAllBuffer(void);
	void FreeBuffer(StreamType type);

protected:
	std::array<Data, STREAM_TYPE_COUNT> mBuffers;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESTREAMDATA_H_ */
