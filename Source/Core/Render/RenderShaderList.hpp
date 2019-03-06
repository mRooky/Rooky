/*
 * RenderShaderList.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSHADERLIST_HPP_
#define SOURCE_CORE_RENDER_RENDERSHADERLIST_HPP_

#include <array>
#include <bitset>

namespace Render
{
class Shader;
class ShaderList
{
public:
	ShaderList(void) = default;
	~ShaderList(void) = default;

public:
	inline void Clear(void) { mShaderMask.reset(); }
	inline bool IsValid(void) const { return mShaderMask.any(); }

public:
	inline void SetShader(size_t index, Shader* shader)
	{
		mShaderMask.set(index);
		mShaders.at(index) = shader;
	}

	inline ShaderList& operator = (const ShaderList& other)
	{
		mShaders = other.mShaders;
		mShaderMask = other.mShaderMask;
		return *this;
	}

	inline bool operator == (const ShaderList& other) const
	{
		return ((mShaders == other.mShaders) && (mShaderMask == other.mShaderMask));
	}

protected:
	std::bitset<5> mShaderMask;
	std::array<Shader*, 5> mShaders;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSHADERLIST_HPP_ */
