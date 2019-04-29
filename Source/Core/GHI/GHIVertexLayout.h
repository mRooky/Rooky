/*
 * GHIVertexLayout.h
 *
 *  Created on: Apr 29, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_GHIVERTEXLAYOUT_H_
#define SOURCE_CORE_GHI_GHIVERTEXLAYOUT_H_

#include "GHIVertexElement.h"

namespace GHI
{

class VertexLayout
{
public:
	VertexLayout(void) = default;
	~VertexLayout(void) = default;

public:
	void PushSemantic(uint32_t binding, const VertexElement& element);
	void PushSemantic(uint32_t binding, Semantic semantic, SemanticType type);

public:
	VertexLayout& operator=(const VertexLayout& other);

public:
	inline bool operator==(const VertexLayout& other) const
	{
		return mVertexElements == other.mVertexElements;
	}

public:
	inline size_t GetVertexElementCount(void) const
	{
		return mVertexElements.size();
	}

	inline const VertexElement& GetVertexElement(size_t index) const
	{
		return mVertexElements.at(index);
	}

public:
	inline bool IsValid(void) const { return mVertexElements.size() > 0; }

protected:
	VertexElement* GetVertexElementBinding(uint32_t binding);

protected:
	std::vector<VertexElement> mVertexElements;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_GHIVERTEXLAYOUT_H_ */
