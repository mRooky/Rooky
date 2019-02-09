/*
 * RenderShader.h
 *
 *  Created on: Jan 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSHADER_H_
#define SOURCE_CORE_RENDER_RENDERSHADER_H_

#include "RenderObject.h"
#include <string>

namespace Render
{

class Shader : public Object
{
	enum class Type : uint32_t
	{
		VERTEX,
		TESSELLATION_CONTROL,
		TESSELLATION_EVALUATION,
		GEOMETRY,
		FRAGMENT,
		COMPUTE,
		UNKNOWN = ~0u
	};

public:
	explicit Shader(Context* context);
	virtual ~Shader(void) override;

public:
	virtual void Create(const char* file) = 0;

public:
	inline Type GetType(void) const { return mType; }
	inline const char* GetName(void) const { return mName.c_str(); }

protected:
	std::string mName;
	Type mType = Type::UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSHADER_H_ */
