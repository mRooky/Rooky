/*
 * CoreTarget.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORERENDERTARGET_H_
#define SOURCE_CORE_CORERENDERTARGET_H_

#include "GHIClasses.h"
#include "GHILayout.h"
#include "GHIUsageType.h"
#include "CoreResource.h"

namespace Core
{
class TextureManager;
class RenderTarget : public Resource
{
public:
	explicit RenderTarget(TextureManager* manager);
	virtual ~RenderTarget(void);

public:
	void Create(const GHI::ImageLayout& layout, const GHI::UsageType& usage);

public:
	inline TextureManager* GetManager(void) const { return mManager; }

protected:
	TextureManager* mManager = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORERENDERTARGET_H_ */
