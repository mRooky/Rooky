/*
 * RenderShader.h
 *
 *  Created on: Jan 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERSHADER_H_
#define SOURCE_CORE_GHI_RENDERSHADER_H_

#include "GHIShaderTypes.h"
#include "GHIObject.h"
#include <string>

namespace GHI
{

class Shader : public Object
{
public:
	explicit Shader(Device* device);
	virtual ~Shader(void) override;

public:
	virtual void Create(const std::string& file) = 0;

public:
	inline ShaderType GetType(void) const { return mType; }
	inline ShaderStage GetStage(void) const { return mStage; }

public:
	inline void SetName(const char* name) { mName = name; }
	inline const std::string& GetName(void) const { return mName; }

public:
	inline bool operator==(const Shader& other) const
	{
		return (mName == other.mName) && (mType == other.mType) && (mStage == other.mStage);
	}

public:
	static ShaderType GetShaderType(const std::string& file);
	static ShaderStage GetShaderStage(const std::string& file);

protected:
	std::string mName;
	ShaderType mType = ShaderType::UNKNOWN;
	ShaderStage mStage = ShaderStage::UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERSHADER_H_ */
