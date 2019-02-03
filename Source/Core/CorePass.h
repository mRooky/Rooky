/*
 * CorePass.h
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREPASS_H_
#define SOURCE_CORE_COREPASS_H_

#include "RenderClasses.h"
#include <vector>

namespace Core
{

class Pass
{
public:
	Pass(void);
	virtual ~Pass(void);

public:
	inline Render::Pipeline* GetPipeline(void) const { return mPipeline; }
	inline Render::FrameBuffer* GetFrameBuffer(void) const { return mFrameBuffer; }

protected:
	Render::Pipeline* mPipeline = nullptr;
	Render::FrameBuffer* mFrameBuffer = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPASS_H_ */
