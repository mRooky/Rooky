/*
 * CoreTarget.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORERENDERTARGET_H_
#define SOURCE_CORE_CORERENDERTARGET_H_

#include "GHIImageLayout.h"
#include "GHIClasses.h"
#include "GHIUsageType.h"
#include "CoreResource.h"

namespace Core
{
class TextureManager;
class RenderTarget : public Resource
{
public:
	RenderTarget(void);
	virtual ~RenderTarget(void);

};

} /* namespace Core */

#endif /* SOURCE_CORE_CORERENDERTARGET_H_ */
