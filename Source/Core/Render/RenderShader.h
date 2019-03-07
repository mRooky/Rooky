/*
 * RenderShader.h
 *
 *  Created on: Jan 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSHADER_H_
#define SOURCE_CORE_RENDER_RENDERSHADER_H_

#include "RenderObject.h"
#include "RenderEnum.h"
#include <string>

namespace Render
{

class Shader : public Object
{
public:
	explicit Shader(Context* context);
	virtual ~Shader(void) override;

public:
	virtual void Create(ShaderStage stage, const char* file) = 0;

public:
	inline ShaderType GetType(void) const { return mType; }
	inline ShaderStage GetStage(void) const { return mStage; }
	inline const char* GetName(void) const { return mName.c_str(); }

protected:
	std::string mName;
	ShaderType mType = ShaderType::SHADER_TYPE_UNKNOWN;
	ShaderStage mStage = ShaderStage::SHADER_STAGE_UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSHADER_H_ */
