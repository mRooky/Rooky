/*
 * =====================================================================================
 *
 *       Filename:  GLTFBaseColor.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_BASE_COLOR_H
#define SOURCE_GLTF_BASE_COLOR_H

#include "GLTFTexture.h"
#include "../Core/Math/MathVector.h"

namespace GLTF
{

class BaseColor : public Texture
{
public:
	BaseColor(void);
	~BaseColor(void);

public:
	inline void SetFactor(const Math::Vector4f& factor) { mFactor = factor; }

public:
	inline const Math::Vector4f& GetFactor(void) const { return mFactor; }

protected:
	Math::Vector4f mFactor = {};

};

}

#endif
