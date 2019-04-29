/*
 * GHIVertexLayout.h
 *
 *  Created on: Apr 29, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_GHIINPUTLAYOUT_H_
#define SOURCE_CORE_GHI_GHIINPUTLAYOUT_H_

#include "GHIVertexLayout.h"

namespace GHI
{

class InputLayout
{
public:
	InputLayout(void) = default;
	~InputLayout(void) = default;

public:
	void PushVertexLayout(uint32_t binding, const VertexLayout& element);
	void PushVertexLayout(uint32_t binding, Semantic semantic, SemanticType type);

public:
	inline InputLayout& operator=(const InputLayout& other)
	{
		mVertexLayouts = other.mVertexLayouts;
		return *this;
	}

	inline bool operator==(const InputLayout& other) const
	{
		return mVertexLayouts == other.mVertexLayouts;
	}

public:
	inline size_t GetVertexElementCount(void) const
	{
		return mVertexLayouts.size();
	}

	inline const VertexLayout& GetVertexLayout(size_t index) const
	{
		return mVertexLayouts.at(index);
	}

public:
	inline bool IsValid(void) const { return mVertexLayouts.size() > 0; }

protected:
	VertexLayout* GetVertexLayoutBinding(uint32_t binding);

protected:
	std::vector<VertexLayout> mVertexLayouts;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_GHIINPUTLAYOUT_H_ */
