/*
 * CoreStreamData.h
 *
 *  Created on: Apr 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESTREAMDATA_H_
#define SOURCE_CORE_CORESTREAMDATA_H_

#include "PluginStreamType.h"
#include <cstddef>

namespace Plugin
{

class StreamData
{
public:
	StreamData(void);
	virtual ~StreamData(void);

public:
	void* AllocateSemanticBuffer(GHI::SemanticUsage usage, size_t count);

public:
	const void* GetSemanticBuffer(GHI::SemanticUsage usage) const;

public:
	size_t GetValidCount(void) const;
	size_t GetSemanticStride(void) const;

public:
	void ReadSemanticData(void* dst, size_t index);

protected:
	void FreeAllBuffer(void);
	void FreeSemanticBuffer(GHI::SemanticUsage usage);

protected:
	StreamColor mStreamColor = {};
	StreamTexCoord mStreamTexCoord = {};
	StreamNormal mStreamNormal = {};
	StreamPosition mStreamPosition = {};;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESTREAMDATA_H_ */
