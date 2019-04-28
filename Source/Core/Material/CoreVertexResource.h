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
	virtual std::vector<GHI::Binding> GetBindings(void) const override;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_COREVERTEXRESOURCE_H_ */
