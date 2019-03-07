/*
 * RenderShaderState.h
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSHADERSTATE_H_
#define SOURCE_CORE_RENDER_RENDERSHADERSTATE_H_

#include <array>
#include <bitset>

namespace Render
{
class Shader;
class Declaration;
class ShaderState
{
public:
	ShaderState(void);
	virtual ~ShaderState(void);

public:
	void SetShader(Shader* shader);

public:
	inline ShaderState& operator = (const ShaderState& other)
	{
		mShaders = other.mShaders;
		mShaderMask = other.mShaderMask;
		return *this;
	}

	inline bool operator == (const ShaderState& other) const
	{
		return ((mShaders == other.mShaders) && (mShaderMask == other.mShaderMask));
	}

public:
	inline void Clear(void) { mShaderMask.reset(); }
	inline void SetDeclaration(Declaration* declaration) { mDeclaration = declaration; }
	inline Declaration* GetDeclaration(void) const { return mDeclaration; }
	inline bool IsValid(void) const { return mShaderMask.any() &&  mDeclaration != nullptr;}

protected:
	std::bitset<5> mShaderMask;
	std::array<Shader*, 5> mShaders;

protected:
	Declaration* mDeclaration = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSHADERSTATE_H_ */
