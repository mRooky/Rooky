/*
 * CoreStream.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESTREAM_H_
#define SOURCE_CORE_CORESTREAM_H_

#include "GHIElement.h"
#include "CoreStreamType.h"
#include "CoreMeshBuffer.h"
#include "CoreStreamData.h"

#include <vector>

namespace Core
{
class Mesh;
class StreamData;
class Stream
{
public:
	explicit Stream(Mesh* parent);
	~Stream(void);

public:
	bool UploadData(void);

public:
	inline Mesh* GetParent(void) const { return mParent; }
	inline void SetParent(Mesh* parent) { mParent = parent; }

public:
	inline StreamData* GetStreamData(void) { return &mStreamData; }
	inline IndexBuffer* GetIndexBuffer(void) { return &mIndexBuffer; }
	inline VertexBuffer* GetVertexBuffer(void) { return &mVertexBuffer; }

protected:
	void UploadIndex(void);
	void UploadVertex(void);

private:
	const void* FillVertexData(Data* dest, size_t stride, size_t count);

protected:
	Mesh* mParent = nullptr;

protected:
	StreamData mStreamData = {};
	IndexBuffer mIndexBuffer = {};
	VertexBuffer mVertexBuffer = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESTREAM_H_ */
