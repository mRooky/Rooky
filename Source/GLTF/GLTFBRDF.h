/*
 *       Filename:  GLTFBRDF.h
 *
 */

#include "../Core/CoreTexture.h"
#include "../Core/GHI/GHIClasses.h"

namespace GLTF
{

class BRDF
{
public:
	BRDF(void);
	~BRDF(void);

public:
	void Create(const char* vert, const char* frag, uint32_t dimmon);
	void Generate(GHI::CommandList* command);

public:
	inline bool IsValid(void) const { return mBRDF != nullptr; }

protected:
	Core::Texture* mBRDF = nullptr;
	GHI::Sampler* mSampler = nullptr;

};

}
