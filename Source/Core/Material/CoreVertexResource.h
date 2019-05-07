/*
 * CoreVertexResource.h
 *
 *  Created on: Apr 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_COREVERTEXRESOURCE_H_
#define SOURCE_CORE_MATERIAL_COREVERTEXRESOURCE_H_

#include "CoreShaderResource.h"

namespace Core
{

class VertexResource: public ShaderResource
{
public:
	VertexResource(void);
	virtual ~VertexResource(void) override;

public:
	void SetUniform(Uniform* uniform, size_t offset);

public:
	inline size_t GetOffset(void) const { return mOffset; }
	inline Uniform* GetUniform(void) const { return mUniform; }

protected:
	size_t mOffset = 0;
	Uniform* mUniform = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_COREVERTEXRESOURCE_H_ */
