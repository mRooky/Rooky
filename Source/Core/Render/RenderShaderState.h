/*
 * RenderShaderState.h
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSHADERSTATE_H_
#define SOURCE_CORE_RENDER_RENDERSHADERSTATE_H_

#include "RenderShader.h"
#include <vector>

namespace Render
{
class Shader;
class VertexLayout;
class ShaderState
{
public:
	ShaderState(void);
	virtual ~ShaderState(void);

public:
	void SetShader(Shader* shader);

public:
	Shader* GetShader(ShaderType type) const;

public:
	bool operator==(const ShaderState& other) const;
	ShaderState& operator=(const ShaderState& other);

public:
	inline size_t GetShaderCount(void) const { return mShaders.size(); }
	inline Shader* GetShader(size_t index) const { return mShaders.at(index); }

protected:
	std::vector<Shader*> mShaders;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSHADERSTATE_H_ */
