/*
 * CoreTarget.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORERENDERTARGET_H_
#define SOURCE_CORE_CORERENDERTARGET_H_

#include "CoreResource.h"
#include "GHI/GHIResourceUsage.h"

namespace Core
{

class System;
class RenderTarget : public Resource
{
public:
	explicit RenderTarget(System& system);
	virtual ~RenderTarget(void) override;

public:
	void Create(const GHI::ImageLayout& layout, const GHI::ResourceUsage& usage);

public:
	const GHI::ImageLayout& GetLayout(void) const;

public:
	inline System* GetSystem(void) const { return mSystem; }

protected:
	System* mSystem = nullptr;

};

} /* namespace Core */

#endif /* SOURCE_CORE_CORERENDERTARGET_H_ */
