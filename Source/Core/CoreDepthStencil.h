/*
 * CoreDepthStencil.h
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREDEPTHSTENCIL_H_
#define SOURCE_CORE_COREDEPTHSTENCIL_H_

#include "CoreRenderTarget.h"

namespace Core
{

class DepthStencil: public RenderTarget
{
public:
	explicit DepthStencil(TextureManager* manager);
	virtual ~DepthStencil(void) override;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREDEPTHSTENCIL_H_ */
