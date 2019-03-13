/*
 * CoreTarget.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETARGET_H_
#define SOURCE_CORE_CORETARGET_H_

#include "RenderClasses.h"

namespace Core
{
class TextureManager;
class Target
{
public:
	explicit Target(TextureManager* manager);
	virtual ~Target(void);

public:
	void Create(const Render::ImageLayout& layout);

public:
	inline Render::Image* GetImage(void) const { return mImage; }
	inline TextureManager* GetManager(void) const { return mManager; }

protected:
	Render::Image* mImage = nullptr;
	TextureManager* mManager = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETARGET_H_ */
