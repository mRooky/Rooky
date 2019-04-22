/*
 * VKFormat.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKFORMAT_H_
#define SOURCE_RENDER_VK_VKFORMAT_H_

#include "GHIFormat.h"
#include "VKRender.h"

namespace VK
{

GHI::Format ConvertFormat(VkFormat& format);
VkFormat ConvertFormat(GHI::Format& format);

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKFORMAT_H_ */
