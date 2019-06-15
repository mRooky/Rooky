/*
 *       Filename:  GLTFBRDF.h
 *
 */
#ifndef SOURCE_GLTF_BRDF_TEXTURE_H
#define SOURCE_GLTF_BRDF_TEXTURE_H

#include "GLTFTexture.h"

namespace GLTF
{

class BRDF : public Texture
{
public:
	BRDF(void);
	~BRDF(void) override;

public:
	void Create(GHI::CommandList* command, const char* vert, const char* frag, uint32_t dimension);

public:
	inline bool IsValid(void) const { return mBRDF != nullptr; }

public:
	inline Core::Texture* GetBRDFTexture(void) const { return mBRDF; }

protected:
	Core::Texture* mBRDF = nullptr;

};

}

#endif
