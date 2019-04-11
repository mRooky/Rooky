/*
 * CoreStreamData.h
 *
 *  Created on: Apr 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESTREAMDATA_H_
#define SOURCE_CORE_CORESTREAMDATA_H_

#include "CoreData.h"
#include "CoreStreamType.h"
#include <cstddef>

namespace Core
{

class StreamData
{
public:
	StreamData(void);
	virtual ~StreamData(void);

public:
	Data* AllocateIndexBuffer(size_t size);
	void* AllocateSemanticBuffer(StreamType type, size_t count);

public:
	const void* GetSemanticBuffer(StreamType type) const;

public:
	size_t GetValidCount(void) const;
	size_t GetSemanticStride(void) const;

public:
	void ReadSemanticData(void* dst, size_t index);

public:
	inline const Data* GetIndexBuffer(void) const { return &mIndexBuffer; }

protected:
	void FreeAllBuffer(void);
	void FreeSemanticBuffer(StreamType type);

protected:
	Data mIndexBuffer = {};

protected:
	StreamColor mStreamColor = {};
	StreamTexCoord mStreamTexCoord = {};
	StreamNormal mStreamNormal = {};
	StreamPosition mStreamPosition = {};;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESTREAMDATA_H_ */
