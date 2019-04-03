/*
 * CoreMesh.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMESH_H_
#define SOURCE_CORE_COREMESH_H_

#include "CoreRenderable.h"
#include "CoreDataType.h"

#include <array>
#include <vector>

namespace Core
{
class SubMesh;
class MeshManager;
class Mesh : public Renderable
{
	friend class MeshManager;
protected:
	explicit Mesh(MeshManager* manager);

public:
	virtual ~Mesh(void) override;

public:
	SubMesh* CreateSubMesh(void);

public:
	void* Allocate(StreamType type, size_t size, bool discard);

public:
	inline void* GetStream(StreamType type)
	{
		uint32_t index = static_cast<uint32_t>(type);
		return mSubMeshes.at(index);
	}

public:
	inline size_t GetSubMeshCount(void) const { return mSubMeshes.size(); }
	inline SubMesh* GetSubMesh(size_t index) const { return mSubMeshes.at(index); }

protected:
	void FreeAllStream(void);
	void FreeStream(StreamType type);

protected:
	MeshManager* mManager = nullptr;
	std::vector<SubMesh*> mSubMeshes;
	std::array<uint8_t*, STREAM_TYPE_COUNT> mStreams;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMESH_H_ */
