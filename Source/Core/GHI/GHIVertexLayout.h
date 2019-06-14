/*
 * GHIVertexElement.h
 *
 *  Created on: Apr 29, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_GHIVERTEXLAYOUT_H_
#define SOURCE_CORE_GHI_GHIVERTEXLAYOUT_H_

#include "GHIVertexSemantic.h"
#include <vector>

namespace GHI
{

class VertexLayout
{
public:
	VertexLayout(void) {};
	~VertexLayout(void) {};

public:
	inline void PushSemantic(const VertexSemantic& element)
	{
		PushSemantic(element.GetSemanticUsage(), element.GetSemanticType());
	}

	inline void PushSemantic(SemanticUsage usage, SemanticType type)
	{
		mStride += GetTypeSize(type);
		mVertexSemantics.push_back(VertexSemantic(usage, type));
	}

public:
	inline VertexLayout& operator=(const VertexLayout& other)
	{
		mStride = other.mStride;
		mVertexSemantics = other.mVertexSemantics;
		return *this;
	}

	inline bool operator==(const VertexLayout& other) const
	{
		return mStride == other.mStride
			&& mVertexSemantics == other.mVertexSemantics;
	}

public:
	inline size_t GetStride(void) const { return mStride; }
	inline size_t GetSemanticCount(void) const { return mVertexSemantics.size(); }
	inline const VertexSemantic& GetSemantic(size_t index) const
	{
		return mVertexSemantics.at(index);
	}

public:
	inline bool IsValid(void) const { return mVertexSemantics.size() > 0; }

protected:
	size_t mStride = 0;
	std::vector<VertexSemantic> mVertexSemantics;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_GHIVERTEXLAYOUT_H_ */
