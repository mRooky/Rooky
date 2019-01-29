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
public:
	explicit Shader(Context* context);
	virtual ~Shader(void) override;

public:
	virtual void Initialize(const char* file) = 0;

protected:
	std::string mName;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSHADER_H_ */
