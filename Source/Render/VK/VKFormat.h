/*
 * VKFormat.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKFORMAT_H_
#define SOURCE_RENDER_VK_VKFORMAT_H_

#include "RenderFormat.h"
#include "VKRender.h"

namespace VK
{

Render::Format ConvertFormat(VkFormat& format);
VkFormat ConvertFormat(Render::Format& format);

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKFORMAT_H_ */
