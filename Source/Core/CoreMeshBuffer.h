/*
 * CoreMeshBuffer.h
 *
 *  Created on: Apr 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMESHBUFFER_H_
#define SOURCE_CORE_COREMESHBUFFER_H_

#include "GHIClasses.h"
#include "GHIEnum.h"
#include <cstddef>

namespace Core
{
class Index;
class Vertex;
class BaseBuffer
{
public:
	BaseBuffer(void) = default;
	~BaseBuffer(void) = default;

public:
	inline size_t GetOffset(void) const { return mOffset; }
	inline void SetOffset(size_t offset) { mOffset = offset; }

protected:
	size_t mOffset = 0;
};

class IndexBuffer : public BaseBuffer
{
public:
	IndexBuffer(void) = default;
	~IndexBuffer(void) = default;

public:
	inline Index* GetIndex(void) const { return mIndex; }
	inline GHI::IndexType GetType(void) const { return mType; }

public:
	inline void SetIndex(Index* index) { mIndex = index; }
	inline void SetType(GHI::IndexType type) { mType = type; }

public:
	Index* mIndex = nullptr;
	GHI::IndexType mType = GHI::IndexType::INDEX_TYPE_UNKNOWN;
};

class VertexBuffer : public BaseBuffer
{
public:
	VertexBuffer(void) = default;
	~VertexBuffer(void) = default;

public:
	inline Vertex* GetVertex(void) const { return mVertex; }
	inline void SetVertex(Vertex* vertex) { mVertex = vertex; }

public:
	inline GHI::VertexElement* GetElement(void) const { return mVertexElement; }
	inline void SetLayout(GHI::VertexElement* element) { mVertexElement = element; }

public:
	Vertex* mVertex = nullptr;
	GHI::VertexElement* mVertexElement = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMESHBUFFER_H_ */
