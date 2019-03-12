/*
 * CoreTarget.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETARGET_H_
#define SOURCE_CORE_CORETARGET_H_

#include "CoreObject.h"
#include "RenderClasses.h"

namespace Core
{

class Target : public Object
{
public:
	explicit Target(System* system);
	virtual ~Target(void) override;

public:
	void Create(const Render::ImageLayout& layout);

public:
	inline Render::Image* GetImage(void) const { return mImage; }

protected:
	Render::Image* mImage = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETARGET_H_ */
