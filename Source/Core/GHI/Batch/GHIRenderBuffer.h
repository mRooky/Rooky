/*
 * GHIRenderBuffer.h
 *
 *  Created on: May 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_BATCH_GHIRENDERBUFFER_H_
#define SOURCE_CORE_GHI_BATCH_GHIRENDERBUFFER_H_

#include "../GHIIndexType.h"
#include <cstddef>
#include <vector>

namespace GHI
{
class Buffer;
class BaseBuffer
{
public:
	BaseBuffer(void) = default;
	~BaseBuffer(void) = default;

public:
	inline size_t GetOffset(void) const { return mOffset; }
	inline void SetOffset(size_t offset) { mOffset = offset; }

public:
	inline void SetBuffer(Buffer* buffer) { mBuffer = buffer; }
	inline const Buffer* GetBuffer(void) const { return mBuffer; }

protected:
	size_t mOffset = 0;
	Buffer* mBuffer = nullptr;
};

class IndexBuffer : public BaseBuffer
{
public:
	IndexBuffer(void) = default;
	~IndexBuffer(void) = default;

public:
	inline void SetType(IndexType type) { mType = type; }
	inline IndexType GetType(void) const { return mType; }

protected:
	IndexType mType = IndexType::UNKNOWN;
};

class VertexBuffer : public BaseBuffer
{
public:
	VertexBuffer(void) = default;
	~VertexBuffer(void) = default;
};

class VertexAttribute
{
	constexpr static const size_t MAX_ATTRIBUTE_COUNT = 16;
public:
	VertexAttribute(void) = default;
	~VertexAttribute(void) = default;

public:
	inline void AppendBuffer(size_t offset, Buffer* buffer)
	{
		VertexBuffer vertex;
		vertex.SetOffset(offset);
		vertex.SetBuffer(buffer);
		AppendBuffer(vertex);
	}

	inline void AppendBuffer(const VertexBuffer& vertex)
	{
		mAttributes.push_back(vertex);
	}

public:
	inline size_t GetBufferCount(void) const
	{
		return mAttributes.size();
	}

	inline const VertexBuffer& GetBuffer(size_t index) const
	{
		return mAttributes.at(index);
	}

protected:
	std::vector<VertexBuffer> mAttributes;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_BATCH_GHIRENDERBUFFER_H_ */
