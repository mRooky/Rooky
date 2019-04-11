/*
 * CoreMeshData.h
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESTREAMTYPE_H_
#define SOURCE_CORE_CORESTREAMTYPE_H_

#include "RenderColor.hpp"
#include "RenderVector.hpp"
#include <cstdint>
#include <vector>

namespace Core
{

enum class StreamType : uint32_t
{
	STREAM_TYPE_POSITION,
	STREAM_TYPE_COLOR,
	STREAM_TYPE_NORMAL,
	STREAM_TYPE_TANGENT,
	STREAM_TYPE_TEXCOORD,
	STREAM_TYPE_WEIGHT,
	STREAM_TYPE_UNKONWN = ~0U
};

static const uint32_t STREAM_TYPE_COUNT = 6;
static inline uint32_t CastStream(StreamType type) { return static_cast<uint32_t>(type); }
static inline StreamType CastIndex(uint32_t index) { return static_cast<StreamType>(index); }

template<class T>
class StreamBase
{
public:
	StreamBase(void) = default;
	~StreamBase(void) = default;

public:
	inline void* Create(size_t count)
	{
		mPositionData.resize(count);
		return mPositionData.data();
	}

public:
	inline void ClearSemanticData(void) { mPositionData.clear(); }

public:
	inline bool IsValid(void) const { return mPositionData.size() > 0; }
	inline size_t GetSemanticCount(void) const { return mPositionData.size(); }
	inline const void* GetDataMemory(void) const { return mPositionData.data(); }

protected:
	std::vector<T> mPositionData;
};

typedef StreamBase<Render::Color> StreamColor;
typedef StreamBase<Render::Vector2f> StreamCoord;
typedef StreamBase<Render::Vector3f> StreamPosition, StreamNormal;

} /* namespace Core */

#endif /* SOURCE_CORE_CORESTREAMTYPE_H_ */
