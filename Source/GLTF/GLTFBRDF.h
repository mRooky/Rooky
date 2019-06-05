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
	void Create(GHI::CommandList* command, const char* vert, const char* frag, uint32_t dimension);

public:
	inline bool IsValid(void) const { return mBRDF != nullptr; }

public:
	inline Core::Texture* GetBRDFTexture(void) const { return mBRDF; }

protected:
	Core::Texture* mBRDF = nullptr;

};

}
