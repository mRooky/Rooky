/*
 * CoreStream.cpp
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#include "GHIInline.h"
#include "GHILayout.h"
#include "CoreStream.h"
#include "CoreIndex.h"
#include "CoreVertex.h"
#include "CoreMesh.h"
#include "CoreData.h"

#include <cassert>
#include <climits>
#include <cstring>

namespace Core
{

Stream::Stream(Mesh* parent):
		mParent(parent)
{
	assert(mParent != nullptr);
}

Stream::~Stream(void)
{
}

bool Stream::UploadData(void)
{
	UploadIndex();
	UploadVertex();
	return true;
}

void Stream::UploadIndex(void)
{
	Index* index = mIndexBuffer.GetIndex();
	const Data* index_data = mStreamData.GetIndexBuffer();
	if (nullptr != index && nullptr != index_data)
	{
		assert(index->IsValid());
		assert(index_data->IsValid());
		const size_t index_count = mParent->GetIndexCount();
		GHI::IndexType index_type = mIndexBuffer.GetType();
		assert(index_type != GHI::IndexType::INDEX_TYPE_UNKNOWN);
		const size_t buffer_offset = mIndexBuffer.GetOffset();
		const size_t buffer_size = index_count * GHI::GetIndexTypeSize(index_type);
		const void* index_buffer = index_data->GetMemory();
		index->Write(index_buffer, buffer_offset, buffer_size);
	}
}

void Stream::UploadVertex(void)
{
	Vertex* vertex = mVertexBuffer.GetVertex();
	if (nullptr != vertex)
	{
		assert(vertex->IsValid());
		GHI::VertexLayout* vertex_layout = mVertexBuffer.GetLayout();
		assert(vertex_layout != nullptr);
		Data vertex_data = {};
		const size_t vertex_stride = vertex_layout->GetStride();
		const size_t vertex_count = mParent->GetVertexCount();
		const size_t buffer_size = vertex_stride * vertex_count;
		vertex_data.AllocateMemory(buffer_size);
		const void* vertex_buffer = FillVertexData(&vertex_data, vertex_stride, vertex_count);
		const size_t buffer_offset = mIndexBuffer.GetOffset();
		vertex->Write(vertex_buffer, buffer_offset, buffer_size);
	}
}

const void* Stream::FillVertexData(Data* dest, size_t stride, size_t count)
{
	const size_t stream_count = mStreamData.GetValidCount();
	GHI::VertexLayout* vertex_layout = mVertexBuffer.GetLayout();
	const size_t element_count = vertex_layout->GetElementCount();
	assert(element_count == stream_count);
	if (element_count == stream_count)
	{
		assert(dest->IsValid());
		void* vertex_buffer = dest->GetMemory();
		uint8_t* vertex_memory = reinterpret_cast<uint8_t*>(vertex_buffer);
		for (size_t index = 0; index < count; ++index)
		{
			mStreamData.ReadSemanticData(vertex_memory, index);
			vertex_memory += stride;
		}
	}
	return dest->GetMemory();
}

} /* namespace Core */
