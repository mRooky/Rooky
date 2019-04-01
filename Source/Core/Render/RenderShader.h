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
	explicit Shader(Device* device);
	virtual ~Shader(void) override;

public:
	virtual void Create(const char* file) = 0;

public:
	inline ShaderType GetType(void) const { return mType; }
	inline ShaderStage GetStage(void) const { return mStage; }

public:
	inline void SetName(const char* name) { mName = name; }
	inline const char* GetName(void) const { return mName.c_str(); }

public:
	inline bool operator==(const Shader& other) const
	{
		return (mName == other.mName) && (mType == other.mType) && (mStage == other.mStage);
	}

public:
	static ShaderType GetShaderType(const char* file);
	static ShaderStage GetShaderStage(const char* file);

protected:
	std::string mName;
	ShaderType mType = ShaderType::SHADER_TYPE_UNKNOWN;
	ShaderStage mStage = ShaderStage::SHADER_STAGE_UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSHADER_H_ */
