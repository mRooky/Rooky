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

public:
	inline void SetIndex(Index* index) { mIndex = index; }

protected:
	Index* mIndex = nullptr;
};

class VertexBuffer : public BaseBuffer
{
public:
	VertexBuffer(void) = default;
	~VertexBuffer(void) = default;

public:
	inline Vertex* GetPosition(void) const { return mPosition; }
	inline Vertex* GetAttribute(void) const { return mAttribute; }

public:
	inline void SetPosition(Vertex* position) { mPosition = position; }
	inline void SetAttribute(Vertex* attribute) { mAttribute = attribute; }

protected:
	Vertex* mPosition = nullptr; // for Z pre_pass, Format:RGB32SFLOAT
	Vertex* mAttribute = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMESHBUFFER_H_ */
