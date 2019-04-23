/*
 * RenderDeclaration.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERELEMENT_H_
#define SOURCE_CORE_GHI_RENDERELEMENT_H_

#include "GHIFormat.h"
#include "GHIObject.h"
#include <vector>

namespace GHI
{

enum class ElementType : uint32_t
{
	ELEMENT_TYPE_FLOAT1,
	ELEMENT_TYPE_FLOAT2,
	ELEMENT_TYPE_FLOAT3,
	ELEMENT_TYPE_FLOAT4,
	ELEMENT_TYPE_UNKNOWN = ~0u
};

class Element
{
public:
	explicit Element(uint32_t binding, uint32_t location, ElementType type)
	{
		Set(binding, location, type);
	}

	~Element(void) = default;

public:
	void Set(uint32_t binding, uint32_t location, ElementType type)
	{
		mType = type;
		mBinding = binding;
		mLocation = location;
	}

public:
	inline ElementType GetType(void) const { return mType; }
	inline uint32_t GetBinding(void) const { return mBinding; }
	inline uint32_t GetLocation(void) const { return mLocation; }

public:
	static size_t GetTypeSize(ElementType type);
	static const char* GetTypeName(ElementType type);

public:
	inline bool operator == (const Element& other) const
	{
		return mType == other.mType
			&& mBinding == other.mBinding
			&& mLocation == other.mLocation;
	}

protected:
	uint32_t mBinding = 0;
	uint32_t mLocation = 0;
	ElementType mType = ElementType::ELEMENT_TYPE_UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERELEMENT_H_ */