/*
 * CoreStream.cpp
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#include "CoreStream.h"
#include "CoreIndex.h"
#include "CoreVertex.h"
#include "CoreMesh.h"
#include "CoreData.h"

#include "RenderInline.h"
#include "RenderVertexLayout.h"
#include <cassert>
#include <climits>

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
	const void* index_data = mStreamData.GetBuffer(StreamType::STREAM_TYPE_INDEX);
	if (nullptr != index && nullptr != index_data)
	{
		assert(index->IsValid());
		const size_t index_count = mParent->GetIndexCount();
		Render::IndexType index_type = mIndexBuffer.GetType();
		assert(index_type != Render::IndexType::INDEX_TYPE_UNKNOWN);
		const size_t buffer_offset = mIndexBuffer.GetOffset();
		const size_t buffer_size = index_count * Render::GetIndexTypeSize(index_type);
		index->Write(index_data, buffer_offset, buffer_size);
	}
}

void Stream::UploadVertex(void)
{
	Vertex* vertex = mVertexBuffer.GetVertex();
	if (nullptr != vertex)
	{
		assert(vertex->IsValid());
		Render::VertexLayout* vertex_layout = mVertexBuffer.GetLayout();
		assert(vertex_layout != nullptr);
		Data vertex_data = {};
		const size_t vertex_stride = vertex_layout->GetStride();
		const size_t vertex_count = mParent->GetVertexCount();
		const size_t buffer_size = vertex_stride * vertex_count;
		vertex_data.Allocate(buffer_size);
		FillVertexData(&vertex_data);
		void* vertex_buffer = vertex_data.GetBuffer();
		const size_t buffer_offset = mIndexBuffer.GetOffset();
		vertex->Write(vertex_buffer, buffer_offset, buffer_size);
	}
}

void Stream::FillVertexData(Data* dst)
{
	const size_t start = CastStream(StreamType::STREAM_TYPE_POSITION);
	const size_t end = STREAM_TYPE_COUNT;
	for (size_t index = start; index < end; ++index)
	{
		StreamType type = CastIndex(index);
		Data* element_data = mStreamData.GetBuffer(type);
		if (element_data != nullptr)
		{

		}
	}
}

} /* namespace Core */
