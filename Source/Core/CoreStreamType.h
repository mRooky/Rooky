/*
 * CoreMeshData.h
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESTREAMTYPE_H_
#define SOURCE_CORE_CORESTREAMTYPE_H_

#include <cstdint>

namespace Core
{

enum class StreamType : uint32_t
{
	STREAM_TYPE_INDEX,
	STREAM_TYPE_POSITION,
	STREAM_TYPE_COLOR,
	STREAM_TYPE_NORMAL,
	STREAM_TYPE_TANGENT,
	STREAM_TYPE_TEXCOORD,
	STREAM_TYPE_WEIGHT,
	STREAM_TYPE_COUNT,
	STREAM_TYPE_UNKONWN = ~0U
};

static const uint32_t STREAM_TYPE_COUNT = static_cast<uint32_t>(StreamType::STREAM_TYPE_COUNT);
static inline uint32_t CastStream(StreamType type) { return static_cast<uint32_t>(type); }
static inline StreamType CastIndex(uint32_t index) { return static_cast<StreamType>(index); }

} /* namespace Core */

#endif /* SOURCE_CORE_CORESTREAMTYPE_H_ */
