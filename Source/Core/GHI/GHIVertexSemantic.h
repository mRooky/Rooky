/*
 * GHISemantic.h
 *
 *  Created on: Apr 29, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_GHISEMANTIC_H_
#define SOURCE_CORE_GHI_GHISEMANTIC_H_

#include <cstdint>
#include <cstddef>

namespace GHI
{

enum class SemanticUsage : uint16_t
{
	POSITION,
	TEXCOORD,
	NORMAL,
	TANGENT,
	BONEINDEX,
	BONEWEIGHT,
	DEFFUSECOOR,
	COUNT,
	UNKNOWN
};

enum class SemanticType : uint16_t
{
	FLOAT1,
	FLOAT2,
	FLOAT3,
	FLOAT4,
	UNKNOWN
};

static inline size_t GetTypeSize(SemanticType type)
{
	switch(type)
	{
	case SemanticType::FLOAT1:
		return 1 * sizeof(float);
	case SemanticType::FLOAT2:
		return 2 * sizeof(float);
	case SemanticType::FLOAT3:
		return 3 * sizeof(float);
	case SemanticType::FLOAT4:
		return 4 * sizeof(float);
	default:
		return 0;
	}
}

static inline const char* GetTypeName(SemanticType type)
{
	switch (type)
	{
	case SemanticType::FLOAT1:
		return "SEMANTIC_TYPE_FLOAT1";
	case SemanticType::FLOAT2:
		return "SEMANTIC_TYPE_FLOAT2";
	case SemanticType::FLOAT3:
		return "SEMANTIC_TYPE_FLOAT3";
	case SemanticType::FLOAT4:
		return "SEMANTIC_TYPE_FLOAT4";
	default:
		return ("Undefined Type Value!");
	}
}

template<typename T>
static inline constexpr uint16_t EnumCast(T semantic)
{
	return static_cast<uint16_t>(semantic);
}

class VertexSemantic
{
public:
	VertexSemantic(SemanticUsage usage, SemanticType type)
	{
		Set(usage, type);
	}

	~VertexSemantic(void) = default;

public:
	inline void Set(SemanticUsage usage, SemanticType type)
	{
		this->type = type;
		this->usage = usage;
	}

public:
	inline bool operator==(const VertexSemantic& other) const
	{
		return element == other.element;
	}

public:
	inline SemanticType GetSemanticType(void) const
	{
		return type;
	}

	inline SemanticUsage GetSemanticUsage(void) const
	{
		return usage;
	}

public:
	union
	{
		struct
		{
			SemanticType type;
			SemanticUsage usage;
		};
		uint32_t element = 0;
	};
};

}

#endif /* SOURCE_CORE_GHI_GHISEMANTIC_H_ */
