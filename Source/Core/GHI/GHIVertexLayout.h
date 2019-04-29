/*
 * GHIVertexElement.h
 *
 *  Created on: Apr 29, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_GHIVERTEXLAYOUT_H_
#define SOURCE_CORE_GHI_GHIVERTEXLAYOUT_H_

#include "GHISemantic.h"
#include <vector>

namespace GHI
{

class VertexLayout
{
public:
	VertexLayout(void) = default;
	~VertexLayout(void) = default;

public:
	inline void Push(const SemanticElement& element)
	{
		Push(element.GetSemantic(), element.GetSemanticType());
	}

	inline void Push(Semantic semantic, SemanticType type)
	{
		mStride += GetTypeSize(type);
		mSemanticElements.push_back(SemanticElement(semantic, type));
	}

public:
	inline VertexLayout& operator=(const VertexLayout& other)
	{
		mStride = other.mStride;
		mSemanticElements = other.mSemanticElements;
		return *this;
	}

	inline bool operator==(const VertexLayout& other) const
	{
		return mStride == other.mStride
			&& mSemanticElements == other.mSemanticElements;
	}

public:
	inline size_t GetStride(void) const { return mStride; }
	inline size_t GetSemanticElementCount(void) const { return mSemanticElements.size(); }
	inline const SemanticElement& GetSemanticElement(size_t index) const
	{
		return mSemanticElements.at(index);
	}

public:
	inline bool IsValid(void) const { return mSemanticElements.size() > 0; }

protected:
	size_t mStride = 0;
	std::vector<SemanticElement> mSemanticElements;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_GHIVERTEXLAYOUT_H_ */
