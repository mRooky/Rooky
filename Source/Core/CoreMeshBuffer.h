/*
 * CoreMeshBuffer.h
 *
 *  Created on: Apr 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMESHBUFFER_H_
#define SOURCE_CORE_COREMESHBUFFER_H_

#include "RenderClasses.h"
#include "RenderEnum.h"
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
	inline Render::IndexType GetType(void) const { return mType; }

public:
	inline void SetIndex(Index* index) { mIndex = index; }
	inline void SetType(Render::IndexType type) { mType = type; }

public:
	Index* mIndex = nullptr;
	Render::IndexType mType = Render::IndexType::INDEX_TYPE_UNKNOWN;
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
	inline Render::VertexLayout* GetLayout(void) const { return mVertexLayout; }
	inline void SetLayout(Render::VertexLayout* layout) { mVertexLayout = layout; }

public:
	Vertex* mVertex = nullptr;
	Render::VertexLayout* mVertexLayout = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMESHBUFFER_H_ */
