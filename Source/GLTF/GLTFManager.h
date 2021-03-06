/*
 * =====================================================================================
 *
 *       Filename:  GLTFManager.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_MANAGER_H
#define SOURCE_GLTF_MANAGER_H

#include "../Core/GHI/GHIClasses.h"
#include <vector>

namespace GLTF
{

class Render;
class Texture;
class Material;

class Manager
{
public:
	Manager(Render* render);
	~Manager(void);

public:
	void Init(void);

public:
	inline GHI::Device* GetDevice(void) const { return mDevice; }

protected:
	Render* mRender = nullptr;

protected:
	GHI::Device* mDevice = nullptr;
	std::vector<Texture*> mTextures;
	std::vector<Material*> mMaterials;
	std::vector<GHI::Sampler*> mSamplers;
};

}

#endif
