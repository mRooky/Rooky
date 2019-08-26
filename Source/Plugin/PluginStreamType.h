/*
 * CoreMeshData.h
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESTREAMTYPE_H_
#define SOURCE_CORE_CORESTREAMTYPE_H_

#include "../Core/GHI/GHIVertexSemantic.h"
#include "../Core/Math/MathColorInt.h"
#include "../Core/Math/MathVector.h"
#include <cstdint>
#include <vector>
#include <cstring>

namespace Plugin
{

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

	inline size_t WriteTo(void* dest, size_t index) const
	{
		size_t write_size = 0;
		if (IsValid())
		{
			write_size = StreamBase::GetSemanticSize();
			const void* memory = GetSemanticData(index);
			std::memcpy(dest, memory, write_size);
		}
		return write_size;
	}

public:
	inline void ClearSemanticData(void) { mPositionData.clear(); }

public:
	inline bool IsValid(void) const { return mPositionData.size() > 0; }
	inline size_t GetSemanticCount(void) const { return mPositionData.size(); }
	inline const void* GetDataMemory(void) const { return mPositionData.data(); }
	inline const void* GetSemanticData(size_t index) const { return &mPositionData.at(index); }

public:
	static inline constexpr size_t GetSemanticSize(void) { return sizeof(T); }

protected:
	std::vector<T> mPositionData;
};

typedef StreamBase<Math::ColorI> StreamColor;
typedef StreamBase<Math::Vector2f> StreamTexCoord;
typedef StreamBase<Math::Vector3f> StreamPosition, StreamNormal;

} /* namespace Core */

#endif /* SOURCE_CORE_CORESTREAMTYPE_H_ */
