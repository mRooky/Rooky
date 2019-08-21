/*
 * =====================================================================================
 *
 *       Filename:  GLTFSubMesh.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_SUB_MESH_H
#define SOURCE_GLTF_SUB_MESH_H

#include <cstdint>

namespace GLTF
{
class Mesh;
class Material;
class SubMesh
{
	friend class Mesh;
private:
	explicit SubMesh(Mesh* parent):
		mParent(parent)
	{}

public:
	~SubMesh(void) = default;

public:
	inline void SetFirstIndex(uint32_t first)
	{
		mFirstIndex = first;
	}

	inline void SetIndexCount(uint32_t count)
	{
		mIndexCount = count;
	}

	inline void SetFirstVertex(uint32_t first)
	{
		mFirstVertex = first;
	}

	inline void SetVertexCount(uint32_t count)
	{
		mVertexCount = count;
	}

public:
	inline uint32_t GetFirstIndex(void) const
	{
		return mFirstIndex;
	}

	inline uint32_t GetIndexCount(void) const
	{
		return mIndexCount;
	}

	inline uint32_t GetFirstVertex(void) const
	{
		return mFirstVertex;
	}

	inline uint32_t GetVertexCount(void) const
	{
		return mVertexCount;
	}

public:
	inline Mesh* GetParent(void) const
	{
		return mParent;
	}

	inline void SetParent(Mesh* parent)
	{
		mParent = parent;
	}

public:
	inline Material* GetMaterial(void)
	{
		return mMaterial;
	}

	inline void SetMaterial(Material* material)
	{
		mMaterial = material;
	}

protected:
	Mesh* mParent = nullptr;

protected:
	uint32_t mFirstIndex = 0;
	uint32_t mIndexCount = 0;
	uint32_t mFirstVertex = 0;
	uint32_t mVertexCount = 0; //TODO for what ?

protected:
	Material* mMaterial = nullptr;
};

}

#endif
