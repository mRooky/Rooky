/*
 * VKRenderState.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRENDERSTATE_H_
#define SOURCE_RENDER_VK_VKRENDERSTATE_H_

#include "RenderState.h"
#include "VKRender.h"

namespace VK
{
class Context;
class RenderState: public Render::State
{
public:
	explicit RenderState(Context* context);
	virtual ~RenderState(void) override;

protected:

};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRENDERSTATE_H_ */
