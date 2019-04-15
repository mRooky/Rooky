/*
 * CoreTarget.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETARGET_H_
#define SOURCE_CORE_CORETARGET_H_

#include <RenderLayout.h>
#include "CoreResource.h"
#include "RenderClasses.h"
#include "RenderUsageType.h"

namespace Core
{
class TextureManager;
class Target : public Resource
{
public:
	explicit Target(TextureManager* manager);
	virtual ~Target(void);

public:
	void Create(const Render::ImageLayout& layout, const Render::UsageType& usage);

public:
	inline TextureManager* GetManager(void) const { return mManager; }

protected:
	TextureManager* mManager = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETARGET_H_ */
